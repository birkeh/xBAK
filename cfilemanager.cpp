#include "cfilemanager.h"


#include "cconfigfile.h"
#include "cexception.h"
#include "cfilemanager.h"
//#include "GameFile.h"
#include "cresourcefile.h"


cFileManager* cFileManager::m_instance = nullptr;

cFileManager::cFileManager()
{
	m_resIndex.load("krondor.rmf");
	m_resArchive.open(m_resIndex.getResourceFilename(), false);
}

cFileManager::~cFileManager()
{
//	resArchive.Close();
}

cFileManager* cFileManager::getInstance()
{
	if(!m_instance)
		m_instance = new cFileManager();

	return(m_instance);
}

void cFileManager::cleanUp()
{
	if(m_instance)
	{
		delete m_instance;
		m_instance = 0;
	}
}

cFileBuffer* cFileManager::loadConfig(const QString &name)
{
	try
	{
		cConfigFile	cfgfile;
		cfgfile.open(name, false);
		cFileBuffer *buffer = new cFileBuffer(cfgfile.size());
		cfgfile.seek(0);
		cfgfile.load(*buffer);
		cfgfile.close();
		return buffer;
	}
	catch(cException &e)
	{
		e.print("FileManager::LoadConfig");
		throw;
	}
	return 0;
}

//void
//FileManager::SaveConfig(const std::string &name, FileBuffer* buffer)
//{
//    try
//    {
//        ConfigFile cfgfile;
//        cfgfile.Open(name, true);
//        cfgfile.Save(*buffer);
//        cfgfile.Close();
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::SaveConfig");
//        throw;
//    }
//}

//void
//FileManager::SaveConfig(const std::string &name, FileBuffer* buffer, const unsigned int n)
//{
//    try
//    {
//        ConfigFile cfgfile;
//        cfgfile.Open(name, true);
//        cfgfile.Save(*buffer, n);
//        cfgfile.Close();
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::SaveConfig");
//        throw;
//    }
//}

//FileBuffer*
//FileManager::LoadGame(const std::string &name)
//{
//    try
//    {
//        GameFile gamfile;
//        gamfile.Open(name, false);
//        FileBuffer *buffer = new FileBuffer(gamfile.Size());
//        gamfile.Seek(0);
//        gamfile.Load(*buffer);
//        gamfile.Close();
//        return buffer;
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::LoadGame");
//        throw;
//    }
//    return 0;
//}

//void
//FileManager::SaveGame(const std::string &name, FileBuffer* buffer)
//{
//    try
//    {
//        GameFile gamfile;
//        gamfile.Open(name, true);
//        gamfile.Save(*buffer);
//        gamfile.Close();
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::SaveGame");
//        throw;
//    }
//}

//void
//FileManager::SaveGame(const std::string &name, FileBuffer* buffer, const unsigned int n)
//{
//    try
//    {
//        GameFile gamfile;
//        gamfile.Open(name, true);
//        gamfile.Save(*buffer, n);
//        gamfile.Close();
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::SaveGame");
//        throw;
//    }
//}

cFileBuffer* cFileManager::loadResource(const QString& name)
{
	try
	{
		cResourceFile	resfile;
		resfile.open(name, false);
		cFileBuffer*	buffer	= new cFileBuffer(resfile.size());
		resfile.seek(0);
		resfile.load(*buffer);
		resfile.close();
		return(buffer);
	}
	catch(cException &e1)
	{
		cResourceIndexData resIdxData = {0, 0, 0};
		if(m_resIndex.find(name, resIdxData) && (resIdxData.m_size != 0))
		{
			try
			{
				cFileBuffer*	buffer	= new cFileBuffer(resIdxData.m_size);
				m_resArchive.loadResource(*buffer, resIdxData.m_offset);
				return(buffer);
			}
			catch(cException &e2)
			{
				e2.print("FileManager::LoadResource");
				throw;
			}
		}
		else
			throw cFileNotFound(__FILE__, __LINE__, name);
	}
	return(0);
}

//void
//FileManager::SaveResource(const std::string &name, FileBuffer* buffer)
//{
//    try
//    {
//        ResourceFile resfile;
//        resfile.Open(name, true);
//        resfile.Save(*buffer);
//        resfile.Close();
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::SaveResource");
//        throw;
//    }
//}

//void
//FileManager::SaveResource(const std::string &name, FileBuffer* buffer, const unsigned int n)
//{
//    try
//    {
//        ResourceFile resfile;
//        resfile.Open(name, true);
//        resfile.Save(*buffer, n);
//        resfile.Close();
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::SaveResource");
//        throw;
//    }
//}

//bool
//FileManager::ConfigExists(const std::string &name)
//{
//    try
//    {
//        ConfigFile cfgfile;
//        cfgfile.Open(name, false);
//        cfgfile.Close();
//        return true;
//    }
//    catch (Exception &e)
//    {
//        return false;
//    }
//    return false;
//}

void cFileManager::load(cConfigData* cfg, const QString& name)
{
	try
	{
		cFileBuffer*	buffer;
		buffer	= loadConfig(name);
		cfg->load(buffer);
		delete buffer;
	}
	catch(cException &e)
	{
		e.print("cFileManager::load");
		throw;
	}
}

//void
//FileManager::Save(ConfigData *cfg, const std::string &name)
//{
//    try
//    {
//        FileBuffer *buffer = new FileBuffer(16);
//        unsigned int size = cfg->Save(buffer);
//        SaveConfig(name, buffer, size);
//        delete buffer;
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::Save");
//        throw;
//    }
//}

//bool
//FileManager::GameExists(const std::string &name)
//{
//    try
//    {
//        GameFile gamfile;
//        gamfile.Open(name, false);
//        gamfile.Close();
//        return true;
//    }
//    catch (Exception &e)
//    {
//        return false;
//    }
//    return false;
//}

//void
//FileManager::Load(GameData *gam, const std::string &name)
//{
//    try
//    {
//        FileBuffer *buffer;
//        buffer = LoadGame(name);
//        gam->Load(buffer);
//        delete buffer;
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::Load");
//        throw;
//    }
//}

//void
//FileManager::Save(GameData *gam, const std::string &name)
//{
//    try
//    {
//        FileBuffer *buffer = new FileBuffer(400000);
//        unsigned int size = gam->Save(buffer);
//        SaveGame(name, buffer, size);
//        delete buffer;
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::Save");
//        throw;
//    }
//}

//bool
//FileManager::ResourceExists(const std::string &name)
//{
//    try
//    {
//        ResourceFile resfile;
//        resfile.Open(name, false);
//        resfile.Close();
//        return true;
//    }
//    catch (Exception &e1)
//    {
//        ResourceIndexData resIdxData = {0, 0, 0};
//        return (resIndex.Find(name, resIdxData) && (resIdxData.size != 0));
//    }
//    return false;
//}

void cFileManager::load(cResourceData *res, const QString& name)
{
	try
	{
		cFileBuffer *buffer;
		buffer = loadResource(name);
		res->load(buffer);
		delete buffer;
	}
	catch (cException &e)
	{
		e.print("FileManager::Load");
		throw;
	}
}

//void
//FileManager::Save(ResourceData *res, const std::string &name)
//{
//    try
//    {
//        FileBuffer *buffer = new FileBuffer(0x20000);
//        unsigned int size = res->Save(buffer);
//        SaveResource(name, buffer, size);
//        delete buffer;
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::Save");
//        throw;
//    }
//}

//void
//FileManager::ExtractResource(const std::string &name)
//{
//    try
//    {
//        FileBuffer *buffer;
//        buffer = LoadResource(name);
//        SaveResource(name, buffer);
//        delete buffer;
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::ExtractResource");
//        throw;
//    }
//}

//void
//FileManager::ExtractAllResources()
//{
//    try
//    {
//        std::string resName;
//        ResourceIndexData resIdxData = {0, 0, 0};
//        if (resIndex.GetFirst(resName, resIdxData))
//        {
//            do
//            {
//                FileBuffer *buffer = new FileBuffer(resIdxData.size);
//                resArchive.LoadResource(*buffer, resIdxData.offset);
//                SaveResource(resName, buffer);
//                delete buffer;
//            }
//            while (resIndex.GetNext(resName, resIdxData));
//        }
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::ExtractAllResources");
//        throw;
//    }
//}

//void
//FileManager::ArchiveAllResources()
//{
//    try
//    {
//        std::string resName;
//        ResourceIndexData resIdxData = {0, 0, 0};
//        FileBuffer *archiveBuffer = new FileBuffer(0x1000000);
//        if (resIndex.GetFirst(resName, resIdxData))
//        {
//            do
//            {
//                FileBuffer *buffer = new FileBuffer(resIdxData.size);
//                resArchive.LoadResource(*buffer, resIdxData.offset);
//                archiveBuffer->PutString(resName, RES_FILENAME_LEN);
//                archiveBuffer->PutUint32LE(resIdxData.size);
//                archiveBuffer->CopyFrom(buffer, resIdxData.size);
//                delete buffer;
//            }
//            while (resIndex.GetNext(resName, resIdxData));
//        }
//        SaveResource(resIndex.GetResourceFilename(), archiveBuffer, archiveBuffer->GetBytesDone());
//        resIndex.Save("krondor.rmf");
//        delete archiveBuffer;
//    }
//    catch (Exception &e)
//    {
//        e.Print("FileManager::ArchiveAllResources");
//        throw;
//    }
//}
