#ifndef CFONTRESOURCE_H
#define CFONTRESOURCE_H


#include "cfont.h"
#include "ctaggedresource.h"


class cFontResource : public cTaggedResource
{
public:
	cFontResource();
	virtual ~cFontResource();
	cFont*					getFont() const;
	void					clear();
	void					load(cFileBuffer *buffer);
	unsigned int			save(cFileBuffer *buffer);

private:
	cFont*					m_font;
};

#endif // CFONTRESOURCE_H
