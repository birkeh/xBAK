#ifndef CTAGGEDRESOURCE_H
#define CTAGGEDRESOURCE_H


#include <map>

#include "cresourcedata.h"


const uint32_t TAG_ADS = 0x3a534441;
const uint32_t TAG_APP = 0x3a505041;
const uint32_t TAG_BIN = 0x3a4e4942;
const uint32_t TAG_BMP = 0x3a504d42;
const uint32_t TAG_DAT = 0x3a544144;
const uint32_t TAG_FNT = 0x3a544e46;
const uint32_t TAG_GID = 0x3a444947;
const uint32_t TAG_INF = 0x3a464e49;
const uint32_t TAG_MAP = 0x3a50414d;
const uint32_t TAG_PAG = 0x3a474150;
const uint32_t TAG_PAL = 0x3a4c4150;
const uint32_t TAG_RES = 0x3a534552;
const uint32_t TAG_SCR = 0x3a524353;
const uint32_t TAG_SND = 0x3a444e53;
const uint32_t TAG_TAG = 0x3a474154;
const uint32_t TAG_TT3 = 0x3a335454;
const uint32_t TAG_TTI = 0x3a495454;
const uint32_t TAG_VER = 0x3a524556;
const uint32_t TAG_VGA = 0x3a414756;


class cTaggedResource : public cResourceData
{
public:
	cTaggedResource();
	virtual ~cTaggedResource();
	void										clearTags();
	void										split(cFileBuffer *buffer);
	bool										find(const unsigned label, cFileBuffer* &buffer);

private:
	std::map<const unsigned int, cFileBuffer*>	m_bufferMap;
};


#endif // CTAGGEDRESOURCE_H
