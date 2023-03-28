#ifndef CFILEMANAGER_H
#define CFILEMANAGER_H


#include "cconfigdata.h"
//#include "GameData.h"
#include "cresourcearchive.h"
#include "cresourcedata.h"
#include "cresourceindex.h"

#include <QString>


class cFileManager
{
public:
	~cFileManager();
	static cFileManager*			getInstance();
	static void						cleanUp();
//    bool ConfigExists ( const std::string &name );
	void							load(cConfigData* cfg, const QString& name);
//    void Save ( ConfigData *cfg, const std::string &name );
//    bool GameExists ( const std::string &name );
//    void Load ( GameData *gam, const std::string &name );
//    void Save ( GameData *gam, const std::string &name );
//    bool ResourceExists ( const std::string &name );
	void							load(cResourceData *res, const QString& name);
//    void Save ( ResourceData *res, const std::string &name );
//    void ExtractResource ( const std::string &name );
//    void ExtractAllResources();
//    void ArchiveAllResources();

//private:
	cResourceIndex					m_resIndex;
	cResourceArchive				m_resArchive;
	cFileBuffer*					loadConfig(const QString& name);
//    void SaveConfig ( const std::string &name, FileBuffer* buffer );
//    void SaveConfig ( const std::string &name, FileBuffer* buffer, const unsigned int n );
//    FileBuffer* LoadGame ( const std::string &name );
//    void SaveGame ( const std::string &name, FileBuffer* buffer );
//    void SaveGame ( const std::string &name, FileBuffer* buffer, const unsigned int n );
	cFileBuffer*					loadResource(const QString& name);
//    void SaveResource ( const std::string &name, FileBuffer* buffer );
//    void SaveResource ( const std::string &name, FileBuffer* buffer, const unsigned int n );
	static cFileManager*			m_instance;

protected:
	cFileManager();

};

#endif // CFILEMANAGER_H
