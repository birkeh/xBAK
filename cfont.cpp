#include "cexception.h"
#include "cfont.h"
#include "cmediatoolkit.h"


cFont::cFont() :
	m_first(0),
	m_height(0)
{
}

cFont::~cFont()
{
	m_fontGlyphs.clear();
}

unsigned int cFont::getFirst() const
{
	return(m_first);
}

void cFont::setFirst(unsigned int n)
{
	m_first = n;
}

int cFont::getHeight() const
{
	return(m_height);
}

void cFont::setHeight(int h)
{
	m_height = h;
}

int cFont::getWidth(unsigned int n) const
{
	if(n < m_fontGlyphs.size())
		return(m_fontGlyphs[n].width);
	else
		throw cIndexOutOfRange(__FILE__, __LINE__);
}

unsigned int cFont::getSize() const
{
	return(m_fontGlyphs.size());
}

FontGlyph& cFont::getGlyph(unsigned int n)
{
	if(n < m_fontGlyphs.size())
		return(m_fontGlyphs[n]);
	else
		throw cIndexOutOfRange(__FILE__, __LINE__);
}

void cFont::addGlyph(FontGlyph& glyph)
{
	m_fontGlyphs.push_back(glyph);
}

void cFont::drawChar(int x, int y, int ch, int color, bool italic)
{
//	Video *video = cMediaToolkit::getInstance()->getVideo();

//	if((int)(ch - m_first) >= 0)
//	{
//		if(italic)
//			video->drawGlyphItalic(x, y, fontGlyphs[ch - first].width, height, color, fontGlyphs[ch - first].data);
//		else
//			video->drawGlyph (x, y, fontGlyphs[ch - first].width, height, color, fontGlyphs[ch - first].data);
//	}
}
