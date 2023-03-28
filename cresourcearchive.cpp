#include "cexception.h"
#include "cresourcearchive.h"


cResourceArchive::cResourceArchive()
		: cResourceFile()
{
}

cResourceArchive::~cResourceArchive()
{
}

void cResourceArchive::loadResource(cFileBuffer &buffer, const std::streamoff offset)
{
	try
	{
		seek(offset);
		load(buffer);
	}
	catch (cException &e)
	{
		e.print("ResourceArchive::LoadResource");
		throw;
	}
}
