#ifndef CDIRECTORIES_H
#define CDIRECTORIES_H

#include <QString>


class cDirectories
{
public:
	~cDirectories();

	static cDirectories*	getInstance();
	static void				cleanUp();

	QString					getResourcePath() const;
	QString					getSharedPath() const;
	QString					getUserPath() const;
	QString					getGamesPath() const;
	QString					getCapturePath() const;
	QString					getDataPath() const;
	void					setResourcePath(const QString& path);

private:
	QString					m_resourcePath;
	QString					m_sharedPath;
	QString					m_userPath;
	QString					m_gamesPath;
	QString					m_capturePath;
	QString					m_dataPath;

	static cDirectories*	m_instance;

	void					createPath(const QString& path);
	QString					searchResources() const;

protected:
	cDirectories();
};

#endif // CDIRECTORIES_H
