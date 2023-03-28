#ifndef CEXCEPTION_H
#define CEXCEPTION_H


#include <QString>

class cException
{
public:
	cException(const QString& file, const quint32 line, const QString& msg);
	cException(const QString& file, const quint32 line, const QString& msg, const quint32 val);

	virtual ~cException() throw();

	void			print(const QString& handler) const throw();
	QString			what() const throw();

private:
	QString			m_filename;
	unsigned int	m_linenr;
	QString			m_message;
public:
};

class cBufferEmpty: public cException
{
public:
	cBufferEmpty(const QString& file, const unsigned int line, const QString& msg = "");
	virtual ~cBufferEmpty() throw();
};

class cBufferFull: public cException
{
public:
	cBufferFull(const QString& file, const unsigned int line, const QString& msg = "");
	virtual ~cBufferFull() throw();
};

class cCompressionError: public cException
{
public:
	cCompressionError(const QString& file, const unsigned int line, const QString& msg = "");
	cCompressionError(const QString& file, const unsigned int line, const QString& msg, const unsigned int value);
	virtual ~cCompressionError() throw ();
};

class cDataCorruption: public cException
{
public:
	cDataCorruption(const QString& file, const unsigned int line, const QString& msg = "");
	cDataCorruption(const QString& file, const unsigned int line, const QString& msg, const unsigned int value);
	virtual ~cDataCorruption() throw ();
};

class cFileNotFound: public cException
{
public:
	cFileNotFound(const QString& file, const unsigned int line, const QString& msg);
	virtual ~cFileNotFound() throw ();
};

class cIndexOutOfRange: public cException
{
public:
	cIndexOutOfRange(const QString& file, const unsigned int line, const QString& msg = "");
	cIndexOutOfRange(const QString& file, const unsigned int line, const QString& msg, const unsigned int value);
	virtual ~cIndexOutOfRange() throw ();
};

class cIOError: public cException
{
public:
	cIOError(const QString& file, const unsigned int line, const QString& msg = "");
	virtual ~cIOError() throw ();
};

class cNullPointer: public cException
{
public:
	cNullPointer(const QString& file, const unsigned int line, const QString& msg = "");
	virtual ~cNullPointer() throw ();
};

class cOpenError: public cException
{
public:
	cOpenError(const QString& file, const unsigned int line, const QString& msg = "");
	virtual ~cOpenError() throw ();
};

class cSDL_Exception: public cException
{
public:
	cSDL_Exception(const QString& file, const unsigned int line, const QString& msg = "");
	virtual ~cSDL_Exception() throw ();
};

class cUnexpectedValue: public cException
{
public:
	cUnexpectedValue(const QString& file, const unsigned int line, const QString& value);
	cUnexpectedValue(const QString& file, const unsigned int line, const unsigned int value);
	virtual ~cUnexpectedValue() throw ();
};

#endif // CEXCEPTION_H
