#include "cdirectories.h"
#include "cexception.h"
#include "cbasicfile.h"


cBasicFile::cBasicFile()
{
}

cBasicFile::~cBasicFile()
{
}

QString cBasicFile::getDefaultPath() const
{
	return(QString(""));
}

QString cBasicFile::getAlternatePath() const
{
	return(QString(""));
}

QString cBasicFile::getLastResortPath() const
{
	return(QString(""));
}

QString cBasicFile::getStoragePath() const
{
	return(QString(""));
}

void cBasicFile::open(const QString& name, const bool writable)
{
	if(writable)
	{
		QString	filename	= getStoragePath() + name;
		ofs.open(filename.toStdString().c_str(), std::ios::out | std::ios::binary);
		if(ofs.fail())
			throw cOpenError(__FILE__, __LINE__, "(" + filename + ")");
	}
	else
	{
		QString	filename	= getDefaultPath() + name;
		ifs.open(filename.toStdString().c_str(), std::ios::in | std::ios::binary);
		if(ifs.fail())
		{
			ifs.clear();
			filename	= getAlternatePath() + name;
			ifs.open(filename.toStdString().c_str(), std::ios::in | std::ios::binary);
			if(ifs.fail())
			{
				ifs.clear();
				filename	= getLastResortPath() + name;
				ifs.open(filename.toStdString().c_str(), std::ios::in | std::ios::binary);
				if(ifs.fail())
					throw cOpenError(__FILE__, __LINE__, "(" + filename + ")");
			}
		}
	}
}

void cBasicFile::close()
{
	if(ifs.is_open())
		ifs.close();
	if(ofs.is_open())
		ofs.close();
}

void cBasicFile::seek(const std::streamoff offset)
{
	if(ifs.is_open())
	{
		ifs.seekg(offset, std::ios::beg);
		if(ifs.fail())
			throw cIOError(__FILE__, __LINE__);
	}

	if(ofs.is_open())
	{
		ofs.seekp(offset, std::ios::beg);
		if(ofs.fail())
			throw cIOError(__FILE__, __LINE__);
	}
}

void cBasicFile::seekEnd(const std::streamoff offset)
{
	if(ifs.is_open())
	{
		ifs.seekg(offset, std::ios::end);
		if(ifs.fail())
			throw cIOError(__FILE__, __LINE__);
	}
	if(ofs.is_open())
	{
		ofs.seekp(offset, std::ios::end);
		if(ofs.fail())
			throw cIOError(__FILE__, __LINE__);
	}
}

std::streamsize cBasicFile::size()
{
	if(ifs.is_open())
	{
		ifs.seekg(0, std::ios::end);
		if(ifs.fail())
			throw cIOError(__FILE__, __LINE__);
		return(ifs.tellg());
	}
	if(ofs.is_open())
	{
		ofs.seekp(0, std::ios::end);
		if(ofs.fail())
			throw cIOError(__FILE__, __LINE__);
		return(ofs.tellp());
	}
	return(0);
}

void cBasicFile::load(cFileBuffer &buffer)
{
	try
	{
		buffer.load(ifs);
	}
	catch (cException &e)
	{
		e.print("BasicFile::Load");
		throw;
	}
}

void cBasicFile::save(cFileBuffer &buffer)
{
	try
	{
		buffer.save(ofs);
	}
	catch (cException &e)
	{
		e.print("BasicFile::Save");
		throw;
	}
}

void cBasicFile::save(cFileBuffer &buffer, const unsigned int n)
{
	try
	{
		buffer.save(ofs, n);
	}
	catch (cException &e)
	{
		e.print("BasicFile::Save");
		throw;
	}
}
