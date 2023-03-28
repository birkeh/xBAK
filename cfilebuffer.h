#ifndef CFILEBUFFER_H
#define CFILEBUFFER_H


#include <fstream>
#include <string>


const unsigned int COMPRESSION_LZW  = 0;
const unsigned int COMPRESSION_LZSS = 1;
const unsigned int COMPRESSION_RLE  = 2;


class cFileBuffer
{
public:
	cFileBuffer(const unsigned int n);
	virtual ~cFileBuffer();

	void				load(std::ifstream &ifs);
	void				save(std::ofstream &ofs);
	void				save(std::ofstream &ofs, const unsigned int n);
	void				dump(const unsigned int n = 0);
	void				copyFrom(cFileBuffer *buf, const unsigned int n);
	void				copyTo(cFileBuffer* buf, const unsigned int n);
	void				fill(cFileBuffer* buf);
	void				rewind();
	void				seek(const unsigned int n);
	void				skip(const int n);

	void				skipBits();
	unsigned int		compressLZW(cFileBuffer* result);
	unsigned int		compressLZSS(cFileBuffer* result);
	unsigned int		compressRLE(cFileBuffer* result);
	unsigned int		compress(cFileBuffer* result, const unsigned int method);
	unsigned int		decompressLZW(cFileBuffer* result);
	unsigned int		decompressLZSS(cFileBuffer* result);
	unsigned int		decompressRLE(cFileBuffer* result);
	unsigned int		decompress(cFileBuffer* result, const unsigned int method);

	bool				atEnd() const;
	unsigned int		getSize() const;
	unsigned int		getBytesDone() const;
	unsigned int		getBytesLeft() const;
	uint8_t*			getCurrent() const;
	unsigned int		getNextBit() const;

	uint8_t				getUint8();
	uint16_t			getUint16LE();
	uint16_t			getUint16BE();
	uint32_t			getUint32LE();
	uint32_t			getUint32BE();
	int8_t				getSint8();
	int16_t				getSint16LE();
	int16_t				getSint16BE();
	int32_t				getSint32LE();
	int32_t				getSint32BE();
	std::string			getString();
	std::string			getString(const unsigned int len);
	void				getData(void* data, const unsigned int n);
	unsigned int		getBits(const unsigned int n);

	void				putUint8(const uint8_t x);
	void				putUint16LE(const uint16_t x);
	void				putUint16BE(const uint16_t x);
	void				putUint32LE(const uint32_t x);
	void				putUint32BE(const uint32_t x);
	void				putSint8(const int8_t x);
	void				putSint16LE(const int16_t x);
	void				putSint16BE(const int16_t x);
	void				putSint32LE(const int32_t x);
	void				putSint32BE(const int32_t x);
	void				putString(const std::string s);
	void				putString(const std::string s, const unsigned int len);
	void				putData(void * data, const unsigned int n);
	void				putData(const uint8_t x, const unsigned int n);
	void				putBits(const unsigned int x, const unsigned int n);

private:
	uint8_t*			m_buffer;
	uint8_t*			m_current;
	unsigned int		m_size;
	unsigned int		m_nextbit;
};

#endif // CFILEBUFFER_H
