#include "cexception.h"
#include "cresourcearchive.h"
#include "cresourceindex.h"


cResourceIndex::cResourceIndex()
	: m_resourceFilename("")
	, m_numResources(0)
	, m_resIdxMap()
	, m_resIdxIterator(m_resIdxMap.begin())
{
}

cResourceIndex::~cResourceIndex()
{
	m_resIdxMap.clear();
}

void cResourceIndex::load(const QString& filename)
{
	try
	{
		cResourceFile		rmf;
		rmf.open(filename, false);

		cFileBuffer			rmfBuffer(rmf.size());
		rmf.seek(0);
		rmf.load(rmfBuffer);
		rmf.close();

		if((rmfBuffer.getUint32LE() != 1) || (rmfBuffer.getUint16LE() != 4))
			throw cDataCorruption(__FILE__, __LINE__);

		m_resourceFilename	= QString::fromStdString(rmfBuffer.getString(RES_FILENAME_LEN));
		m_numResources		= rmfBuffer.getUint16LE();

		cResourceFile		res;
		res.open(m_resourceFilename, false);

		cFileBuffer			resBuffer(RES_FILENAME_LEN + 4);

		for(unsigned int i = 0; i < m_numResources; i++)
		{
			unsigned int	hashkey	= rmfBuffer.getUint32LE();
			std::streamoff	offset	= rmfBuffer.getUint32LE();

			res.seek(offset);
			res.load(resBuffer);

			std::string resIdxName = resBuffer.getString(RES_FILENAME_LEN);

			cResourceIndexData	resIdxData;
			resIdxData.m_hashkey	= hashkey;
			resIdxData.m_offset	= offset + RES_FILENAME_LEN + 4;
			resIdxData.m_size		= resBuffer.getUint32LE();
			m_resIdxMap.insert(std::pair<const QString, cResourceIndexData>(QString::fromStdString(resIdxName), resIdxData));
		}
		res.close();
	}
	catch (cException &e)
	{
		e.print("ResourceIndex::Load");
		throw;
	}
}

void cResourceIndex::save(const QString& filename)
{
	try
	{
		cFileBuffer	rmfBuffer(4 + 2 + RES_FILENAME_LEN + 2 + m_numResources * (4 + 4));
		rmfBuffer.putUint32LE(1);
		rmfBuffer.putUint16LE(4);
		rmfBuffer.putString(m_resourceFilename.toStdString(), RES_FILENAME_LEN);
		rmfBuffer.putUint16LE(m_numResources);

		cResourceFile res;
		res.open(m_resourceFilename, false);
		cFileBuffer		resBuffer(RES_FILENAME_LEN + 4);
		unsigned int	offset	= 0;

		for(unsigned int i = 0; i < m_numResources; i++)
		{
			res.seek(offset);
			res.load(resBuffer);
			std::string			resIdxName = resBuffer.getString(RES_FILENAME_LEN);
			cResourceIndexData	resIdxData;

			find(QString::fromStdString(resIdxName), resIdxData);
			rmfBuffer.putUint32LE(resIdxData.m_hashkey);
			rmfBuffer.putUint32LE(offset);

			offset += RES_FILENAME_LEN + 4 + resIdxData.m_size;
		}
		res.close();

		cResourceFile	rmf;
		rmf.open(filename, true);
		rmf.save(rmfBuffer);
		rmf.close();
	}
	catch (cException &e)
	{
		e.print("ResourceIndex::Save");
		throw;
	}
}

QString cResourceIndex::getResourceFilename() const
{
	return(m_resourceFilename);
}

unsigned int cResourceIndex::getNumResources() const
{
	return(m_numResources);
}

bool cResourceIndex::find(const QString& name, cResourceIndexData &data)
{
	std::map<const QString, cResourceIndexData>::iterator it = m_resIdxMap.find(name);

	if(it != m_resIdxMap.end())
	{
		data = it->second;
		return(true);
	}
	return(false);
}

bool cResourceIndex::getFirst(QString& name, cResourceIndexData &data)
{
	m_resIdxIterator = m_resIdxMap.begin();

	if(m_resIdxIterator != m_resIdxMap.end())
	{
		name = m_resIdxIterator->first;
		data = m_resIdxIterator->second;
		return(true);
	}
	return(false);
}


bool cResourceIndex::getNext(QString& name, cResourceIndexData &data)
{
	if(m_resIdxIterator == m_resIdxMap.end())
		return(false);

	m_resIdxIterator++;

	if(m_resIdxIterator != m_resIdxMap.end())
	{
		name = m_resIdxIterator->first;
		data = m_resIdxIterator->second;
		return(true);
	}
	return(false);
}
