#ifndef __BITMAP_H__
#define __BITMAP_H__

#include "DCObject.h"
#include "Window.h"
   
class Bitmap : public DCObject
{
public:

	Bitmap(Window &Target, int Width = -1, int Height = -1);
	Bitmap(int Width, int Height, int bitsPerPixel = 24);
	Bitmap(char *filename);
	Bitmap(Bitmap &orig);
	virtual ~Bitmap();

	virtual int Width() { return width; }
	virtual int Height() { return height; }

	virtual void Resize(int Width, int Height, bool preserve = TRUE);

    virtual void SetTarget(Window &Target) { target = &Target; }
	virtual void Save(char *fileName, bool Compression = false);
	virtual void Load(char *fileName);
    virtual void Update(void) { }

    operator HBITMAP() { return bit; }

protected:

	Bitmap();

	void SetupBitmap(int Width, int Height);
	bool SelectDIBPalette(void);

	HBITMAP bit, defBit;
	HPALETTE hPal;
	LPBITMAPINFO bInfo;
	HBRUSH DefBrush;
	HPEN DefPen; 
	bool coreHeader;
	int colorBits;
	int width, height;
	Window *target;

};

#endif