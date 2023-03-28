#ifndef CBASICFILE_H
#define CBASICFILE_H


#include "cfilebuffer.h"
#include <QString>


class cBasicFile
{
public:
	cBasicFile();
	virtual ~cBasicFile();

	virtual QString			getDefaultPath() const;
	virtual QString			getAlternatePath() const;
	virtual QString			getLastResortPath() const;
	virtual QString			getStoragePath() const;

	void					open(const QString& name, const bool writable);
	void					close();
	void					seek(const std::streamoff offset);
	void					seekEnd(const std::streamoff offset);
	std::streamsize			size();
	void					load(cFileBuffer& buffer);
	void					save(cFileBuffer& buffer);
	void					save(cFileBuffer &buffer, const unsigned int n);

private:
	std::ifstream			ifs;
	std::ofstream			ofs;
};

#endif // CBASICFILE_H
