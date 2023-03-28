#include "cexception.h"
#include "ctaggedresource.h"


cTaggedResource::cTaggedResource()
{
}

cTaggedResource::~cTaggedResource()
{
	clearTags();
}

void cTaggedResource::clearTags()
{
	for(std::map<const unsigned int, cFileBuffer*>::iterator it = m_bufferMap.begin(); it != m_bufferMap.end(); ++it)
		delete it->second;

	m_bufferMap.clear();
}

void cTaggedResource::split(cFileBuffer *buffer)
{
	while(!buffer->atEnd())
	{
		unsigned int label = buffer->getUint32LE();
		switch (label)
		{
		case TAG_ADS:
		case TAG_APP:
		case TAG_BIN:
		case TAG_BMP:
		case TAG_DAT:
		case TAG_FNT:
		case TAG_GID:
		case TAG_INF:
		case TAG_MAP:
		case TAG_PAG:
		case TAG_PAL:
		case TAG_RES:
		case TAG_SCR:
		case TAG_SND:
		case TAG_TAG:
		case TAG_TT3:
		case TAG_TTI:
		case TAG_VER:
		case TAG_VGA:
		{
			unsigned int size = buffer->getUint32LE();
			std::map<const unsigned int, cFileBuffer*>::iterator it = m_bufferMap.find(label);

			if(it != m_bufferMap.end())
			{
				delete it->second;
				m_bufferMap.erase(it);
			}

			if(size & 0x80000000)
			{
				cFileBuffer *lblbuf = new cFileBuffer(size & 0x7fffffff);
				lblbuf->fill(buffer);
				m_bufferMap.insert(std::pair<const unsigned int, cFileBuffer*>(label, 0));
				split(lblbuf);
				delete lblbuf;
			}
			else
			{
				cFileBuffer *lblbuf = new cFileBuffer(size);
				lblbuf->fill(buffer);
				m_bufferMap.insert(std::pair<const unsigned int, cFileBuffer*>(label, lblbuf));
			}
		}
		break;
		default:
			throw cUnexpectedValue(__FILE__, __LINE__, label);
			break;
		}
	}
}

bool cTaggedResource::find(const unsigned int label, cFileBuffer* &buffer)
{
	try
	{
		buffer = m_bufferMap[label];
	}
	catch (...)
	{
		return(false);
	}
	return(buffer != 0);
}
