#ifndef CFONT_H
#define CFONT_H


#include <vector>


const unsigned int MAX_FONT_HEIGHT = 16;

typedef uint16_t glyphData[MAX_FONT_HEIGHT];


struct FontGlyph
{
	unsigned int	width;
	glyphData		data;
};

class cFont
{
public:
	cFont();
	virtual ~cFont();
	unsigned int				getFirst() const;
	void						setFirst(unsigned int n);
	int							getHeight() const;
	void						setHeight(int h);
	int							getWidth(unsigned int n) const;
	unsigned int				getSize() const;
	FontGlyph&					getGlyph(unsigned int n);
	void						addGlyph(FontGlyph& glyph);
	void						drawChar(int x, int y, int ch, int color, bool italic);

private:
	unsigned int				m_first;
	int							m_height;
	std::vector<FontGlyph>		m_fontGlyphs;
};


#endif // CFONT_H
