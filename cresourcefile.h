#ifndef CRESOURCEFILE_H
#define CRESOURCEFILE_H


#include "cbasicfile.h"


class cResourceFile : public cBasicFile
{
public:
	cResourceFile();
	virtual ~cResourceFile();
	QString					getDefaultPath() const;
	QString					getAlternatePath() const;
	QString					getLastResortPath() const;
	QString					getStoragePath() const;
};

#endif // CRESOURCEFILE_H
