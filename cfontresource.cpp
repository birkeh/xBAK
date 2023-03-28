#include "cexception.h"
#include "cfontresource.h"
#include "cmediatoolkit.h"


cFontResource::cFontResource() :
	cTaggedResource(),
	m_font(0)
{
}

cFontResource::~cFontResource()
{
	clear();
}

cFont* cFontResource::getFont() const
{
	return(m_font);
}

void cFontResource::clear()
{
	delete(m_font);
}

void cFontResource::load(cFileBuffer *buffer)
{
	try
	{
		clear();
		split(buffer);
		cFileBuffer *fntbuf;

		if(!find(TAG_FNT, fntbuf))
		{
			clearTags();
			throw cDataCorruption(__FILE__, __LINE__);
		}

		m_font = new cFont;
		fntbuf->skip(2);
		m_font->setHeight((unsigned int)fntbuf->getUint8());
		fntbuf->skip(1);
		m_font->setFirst((unsigned int)fntbuf->getUint8());

		unsigned int	numChars		= (unsigned int)fntbuf->getUint8();
		fntbuf->skip(2);

		if(fntbuf->getUint8() != 0x01)
		{
			clearTags();
			throw cCompressionError(__FILE__, __LINE__);
		}

		unsigned int	size			= (unsigned int)fntbuf->getUint32LE();
		cFileBuffer*	glyphbuf		= new cFileBuffer(size);
		fntbuf->decompressRLE(glyphbuf);

		unsigned int*	glyphOffset		= new unsigned int [numChars];

		for(unsigned int i = 0; i < numChars; i++)
			glyphOffset[i] = glyphbuf->getUint16LE();

		unsigned int	glyphDataStart	= glyphbuf->getBytesDone();
		for(unsigned int i = 0; i < numChars; i++)
		{
			FontGlyph	glyph;
			glyphbuf->seek(glyphDataStart + i);
			glyph.width	= (unsigned int)glyphbuf->getUint8();
			glyphbuf->seek(glyphDataStart + numChars + glyphOffset[i]);

			for(int j = 0; j < m_font->getHeight(); j++)
			{
				glyph.data[j] = (uint16_t)glyphbuf->getUint8() << 8;

				if(glyph.width > 8)
					glyph.data[j] += (uint16_t)glyphbuf->getUint8();
			}
			m_font->addGlyph(glyph);
		}
		delete[] glyphOffset;
		delete glyphbuf;
		clearTags();
	}
	catch (cException &e)
	{
		e.print("FontResource::Load");
		clearTags();
		throw;
	}
}

unsigned int cFontResource::save(cFileBuffer *buffer)
{
	try
	{
		// TODO
		buffer = buffer;
		return 0;
	}
	catch (cException &e)
	{
		e.print("FontResource::Save");
		throw;
	}
}
