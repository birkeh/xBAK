#ifndef CRESOURCEINDEX_H
#define CRESOURCEINDEX_H


#include <QString>
#include <map>

#include "cfilebuffer.h"


struct cResourceIndexData
{
	unsigned int											m_hashkey;
	std::streamoff											m_offset;
	unsigned int											m_size;
};

class cResourceIndex
{
public:
	cResourceIndex();
	virtual ~cResourceIndex();
	void													load(const QString& filename);
	void													save(const QString& filename);
	QString													getResourceFilename() const;
	unsigned int											getNumResources() const;
	bool													find(const QString& name, cResourceIndexData& data);
	bool													getFirst(QString& name, cResourceIndexData& data);
	bool													getNext(QString& name, cResourceIndexData& data);

private:
	QString													m_resourceFilename;
	unsigned int											m_numResources;
	std::map <const QString, cResourceIndexData>			m_resIdxMap;
	std::map<const QString, cResourceIndexData>::iterator	m_resIdxIterator;
};

#endif // CRESOURCEINDEX_H
