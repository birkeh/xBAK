#ifndef CRESOURCEDATA_H
#define CRESOURCEDATA_H


#include "cfilebuffer.h"

class cResourceData
{
	public:
		cResourceData() {};
		virtual ~cResourceData() {};
		virtual void					clear() = 0;
		virtual void					load(cFileBuffer *buffer ) = 0;
		virtual unsigned int			save(cFileBuffer *buffer ) = 0;
};


#endif // CRESOURCEDATA_H
