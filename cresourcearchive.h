#ifndef CRESOURCEARCHIVE_H
#define CRESOURCEARCHIVE_H


#include "cresourcefile.h"


#define RES_FILENAME_LEN 13


class cResourceArchive : public cResourceFile
{
public:
	cResourceArchive();
	virtual ~cResourceArchive();
	void					loadResource(cFileBuffer& buffer, const std::streamoff offset);
};

#endif // CRESOURCEARCHIVE_H
