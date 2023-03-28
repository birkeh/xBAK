#include "cdirectories.h"
#include "cexception.h"

#include <QDir>
#include <QStringList>

#include <QDebug>


cDirectories* cDirectories::m_instance	= nullptr;

cDirectories::cDirectories() :
	m_resourcePath(""),
	m_sharedPath(""),
	m_userPath(""),
	m_gamesPath(""),
	m_capturePath(""),
	m_dataPath("")
{
	m_resourcePath	= searchResources();
	m_sharedPath	= "";
	m_userPath		= QDir::homePath() + "/xBAK/";
	m_gamesPath		= m_userPath + "games/";
	m_capturePath	= m_userPath + "capture/";
	m_dataPath		= m_userPath + "data/";

	createPath(m_userPath);
	createPath(m_gamesPath);
	createPath(m_capturePath);
	createPath(m_dataPath);
}

cDirectories::~cDirectories()
{
}

void cDirectories::cleanUp()
{
	if(m_instance)
	{
		delete m_instance;
		m_instance = 0;
	}
}

cDirectories* cDirectories::getInstance()
{
	if(!m_instance)
		m_instance =	new cDirectories();

	return(m_instance);
}

void cDirectories::createPath(const QString& path)
{
	QDir	dir;
	dir.mkpath(path);
}

const QString SEARCH_RESOURCE_FILE = "krondor.001";
const QStringList SEARCH_RESOURCE_PATH =	QStringList() <<
											"./" <<
											"/krondor/" <<
											"./krondor/" <<
											"../krondor/" <<
											"/opt/krondor/" <<
											"/bakcd/" <<
											"./bakcd/" <<
											"../bakcd/" <<
											"/opt/bakcd/";

QString cDirectories::searchResources() const
{
	for(int i = 0;i < SEARCH_RESOURCE_PATH.count();i++)
	{
		QFile	f(SEARCH_RESOURCE_PATH[i] + SEARCH_RESOURCE_FILE);
		if(f.exists())
			return(SEARCH_RESOURCE_PATH[i]);
	}

	throw cFileNotFound(__FILE__, __LINE__, SEARCH_RESOURCE_FILE);
	return "";
}

void cDirectories::setResourcePath(const QString& path)
{
	m_resourcePath	= path;
}

QString cDirectories::getResourcePath() const
{
	return(m_resourcePath);
}

QString cDirectories::getSharedPath() const
{
	return(m_sharedPath);
}

QString cDirectories::getUserPath() const
{
	return(m_userPath);
}

QString cDirectories::getGamesPath() const
{
	return(m_gamesPath);
}

QString cDirectories::getCapturePath() const
{
	return(m_capturePath);
}

QString cDirectories::getDataPath() const
{
	return(m_dataPath);
}
