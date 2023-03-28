#include "cexception.h"
#include "cconfigfile.h"
#include "cdirectories.h"


cConfigFile::cConfigFile()
{
}

cConfigFile::~cConfigFile()
{
}

QString cConfigFile::getDefaultPath() const
{
	return(cDirectories::getInstance()->getUserPath());
}

QString cConfigFile::getAlternatePath() const
{
	return(cDirectories::getInstance()->getSharedPath());
}

QString cConfigFile::getLastResortPath() const
{
	return(cDirectories::getInstance()->getResourcePath());
}

QString cConfigFile::getStoragePath() const
{
	return(cDirectories::getInstance()->getUserPath());
}
