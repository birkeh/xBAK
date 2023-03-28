#ifndef CCONFIGFILE_H
#define CCONFIGFILE_H


#include "cbasicfile.h"

#include <QString>


class cConfigFile : public cBasicFile
{
public:
	cConfigFile();
	virtual ~cConfigFile();
	QString					getDefaultPath() const;
	QString					getAlternatePath() const;
	QString					getLastResortPath() const;
	QString					getStoragePath() const;
};

#endif // CCONFIGFILE_H
