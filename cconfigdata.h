#ifndef CCONFIGDATA_H
#define CCONFIGDATA_H


#include "cfilebuffer.h"


class cConfigData
{
public:
	cConfigData()
	{};
	virtual ~cConfigData()
	{};
	virtual void			load(cFileBuffer* buffer ) = 0;
	virtual unsigned int	save(cFileBuffer* buffer ) = 0;
};


#endif // CCONFIGDATA_H
