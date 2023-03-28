#include "cdirectories.h"
#include "cexception.h"
#include "cresourcefile.h"


cResourceFile::cResourceFile()
{
}

cResourceFile::~cResourceFile()
{
}

QString cResourceFile::getDefaultPath() const
{
	return(cDirectories::getInstance()->getDataPath());
}

QString cResourceFile::getAlternatePath() const
{
	return(cDirectories::getInstance()->getSharedPath());
}

QString cResourceFile::getLastResortPath() const
{
	return(cDirectories::getInstance()->getResourcePath());
}

QString cResourceFile::getStoragePath() const
{
	return(cDirectories::getInstance()->getDataPath());
}
