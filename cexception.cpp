#include "cexception.h"

#include <QTextStream>
#include <QDebug>


const QString BUFFER_EMPTY       = "Buffer is empty";
const QString BUFFER_FULL        = "Buffer is full";
const QString COMPRESSION_ERROR  = "Unknown compression method";
const QString DATA_CORRUPTION    = "Data corruption";
const QString FILE_NOT_FOUND     = "File not found";
const QString INDEX_OUT_OF_RANGE = "Index out of range";
const QString IO_ERROR           = "Read/write error";
const QString MEMORY_ERROR       = "Out of memory";
const QString NULL_POINTER       = "Null pointer";
const QString OPEN_ERROR         = "File not open";
const QString SDL_EXCEPTION      = "SDL error";
const QString UNEXPECTED_VALUE   = "Unexpected value";


cException::cException(const QString& file, const quint32 line, const QString& msg) :
	m_filename(file),
	m_linenr(line),
	m_message(msg)
{
}

cException::cException(const QString& file, const quint32 line, const QString& msg, const quint32 val) :
	m_filename(file),
	m_linenr(line)
{
	QTextStream	s(&m_message);

	s << msg << ": " << val;
}

cException::~cException() throw()
{
}

void cException::print(const QString& handler) const throw()
{
	qDebug() << handler << " >> " << m_filename << ":" << m_linenr << " " << m_message;
}

QString cException::what() const throw()
{
	QString		str;
	QTextStream	s(&str);

	s << m_filename << ":" << m_linenr << " " << m_message;
	return(str);
}

cBufferEmpty::cBufferEmpty(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, BUFFER_EMPTY + " " + msg)
{}

cBufferEmpty::~cBufferEmpty() throw()
{}

cBufferFull::cBufferFull(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, BUFFER_FULL + " " + msg)
{}

cBufferFull::~cBufferFull() throw()
{}

cCompressionError::cCompressionError(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, COMPRESSION_ERROR + " " + msg)
{}

cCompressionError::cCompressionError(const QString& file, const quint32 line, const QString& msg, const unsigned int value)
		: cException(file, line, COMPRESSION_ERROR + " " + msg, value)
{}

cCompressionError::~cCompressionError() throw()
{}

cDataCorruption::cDataCorruption(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, DATA_CORRUPTION + " " + msg)
{}

cDataCorruption::cDataCorruption(const QString& file, const quint32 line, const QString& msg, const unsigned int value)
		: cException(file, line, DATA_CORRUPTION + " " + msg, value)
{}

cDataCorruption::~cDataCorruption() throw()
{}

cFileNotFound::cFileNotFound(const QString& file, const quint32 line, const QString& msg) :
	cException(file, line, FILE_NOT_FOUND + " (" + msg + ")")
{}

cFileNotFound::~cFileNotFound() throw()
{}

cIndexOutOfRange::cIndexOutOfRange(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, INDEX_OUT_OF_RANGE + " " + msg)
{}

cIndexOutOfRange::cIndexOutOfRange(const QString& file, const quint32 line, const QString& msg, const unsigned int value)
		: cException(file, line, INDEX_OUT_OF_RANGE + " " + msg, value)
{}

cIndexOutOfRange::~cIndexOutOfRange() throw()
{}

cIOError::cIOError(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, IO_ERROR + " " + msg)
{}

cIOError::~cIOError() throw()
{}

cNullPointer::cNullPointer(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, NULL_POINTER + " " + msg)
{}

cNullPointer::~cNullPointer() throw()
{}

cOpenError::cOpenError(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, OPEN_ERROR + " " + msg)
{}

cOpenError::~cOpenError() throw()
{}

cSDL_Exception::cSDL_Exception(const QString& file, const quint32 line, const QString& msg)
		: cException(file, line, SDL_EXCEPTION + " " + msg)
{}

cSDL_Exception::~cSDL_Exception() throw()
{}

cUnexpectedValue::cUnexpectedValue(const QString& file, const quint32 line, const QString& value)
		: cException(file, line, UNEXPECTED_VALUE + " " + value)
{}

cUnexpectedValue::cUnexpectedValue(const QString& file, const quint32 line, const unsigned int value)
		: cException(file, line, UNEXPECTED_VALUE, value)
{}

cUnexpectedValue::~cUnexpectedValue() throw()
{}
