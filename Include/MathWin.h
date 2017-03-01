#ifndef __MATHWIN_H__
#define __MATHWIN_H__ 

//////////////////////////////////////////////////////////////////////
//
// MathWin.h: interface for the MathWin class.
//
//////////////////////////////////////////////////////////////////////
 
#include "AppWindow.h"
#include "MObject.h"
#include "Bitmap.h"

class MathWin : public AppWindow, public MObject  
{
// Constructors

 public:
	 MathWin() { }
     MathWin(int Width, int Height);
     MathWin(int x, int y, int width, int height, bool Visible = true);
     MathWin(Window &parent, int x, int y, int width, int height, bool Visible = true);
     virtual ~MathWin();

	 virtual void Setup(Window &Parent, int x, int y, int w, int h, bool Visible = true);
	 virtual void Setup(int x, int y, int w, int h, bool Visible = true);
     virtual void Setup(int width, int height);
     virtual void SetupBitmap();

// Color Functions

 public:
     virtual void SetColorref(COLORREF col);
     virtual void SetColor(int col);
     virtual void SetColor(int r, int g, int b);
     virtual void SetColor(double r, double g, double b);
     virtual void SetColor(WColor color);
     virtual void SetColor(WColor First, WColor Last, double BIndex, double TIndex, 
			    double Index);
     virtual void SetBackgroundColorref(COLORREF col);
     virtual void SetBackgroundColor(int col);
     virtual void SetBackgroundColor(int r, int g, int b);
     virtual void SetBackgroundColor(double r, double g, double b);

	 virtual void Refresh(void) { MObject::Refresh(); }

 protected:
     virtual void SetupColor(void);
//	 virtual void CreatePen(void);


// Metafile Functions


// Drawing State Functions

 public:
     virtual void Draw(void);
     virtual void Erase(void);
     virtual void EraseAll(void);
     virtual void SetView(double Xll, double Yll, double Xur, double Yur);
	 virtual void SetViewPreserveAspect(double Xll, double Xur, double CenterY);
     virtual void SetLineWidth(int w);
     virtual void SetLineStyle(int s) { }

// Window Attribute Accessors

 public:
     virtual double ViewWidth(void) { return(xur - xll); }
     virtual double ViewHeight(void) { return(yur - yll); }
     virtual double PixelWidth(void) { return((xur - xll) / width); }
     virtual double PixelHeight(void) { return((yur - yll) / height); }

// 2D Drawing Style Functions

 public:
     virtual void SetXor(bool flag) 
	  { if (flag) SetROP2(pdc, R2_XORPEN); else SetROP2(pdc, R2_COPYPEN); }
     virtual void DrawToBackground(void)
	  { pdc = memdc2; backgroundActive = true; }
     virtual void DrawToForeground(void)
	  { pdc = memdc; }
     virtual void DisableBackground(void)
	  { pdc = memdc; backgroundActive = false; }
     virtual void ActivateBackground(void)
	  { backgroundActive = true; }

// 2D Saving Functions

 public:
     virtual void SaveWindow(char *fileName);
     virtual void LoadWindow(char *fileName, bool toBackground = false);
	 virtual void ActivateMetafile(char *name, double XSize, double YSize, int DPI);
	 virtual void DisableMetafile();

	 inline int mfxmap(double x) { return((int)((x - xll) * mfXMapScale)); }
     inline int mfymap(double y) { return((int)((yur - y) * mfYMapScale)); }
     inline double mfxinvmap(int ix) 
	  { return((double)ix / (mfXSize * 2540) * (xur - xll) + xll); }
     inline double mfyinvmap(int iy) 
	  { return((double)(1 - (double)iy / (mfYSize * 2540)) * (yur - yll) + yll); }

// 2D Drawing Functions

 protected:
    
     static const int trigN;
     double cosines[512];
     double sines[512];

 public:
     virtual void DrawAxes(int col = -1);

     virtual void DrawPoint(double x, double y, int col = -1);
     virtual void DrawPoint(int x, int y, int col = -1);
     virtual void DrawPoint(double x, double y, double CScaleB, double CScaleT, double Index);
     virtual void DrawPoint(int x, int y, double CScaleB, double CScaleT, double Index);

	virtual void MoveDrawPointTo(double x, double y);
	virtual void DrawLineTo(double x, double y, int col = -1);
    virtual void DrawLine(double x1, double y1, double x2, double y2, int col = -1);
    virtual void DrawLine(coordinate c1, coordinate c2, int col = -1);
	virtual void DrawArrow(double x1, double y1, double x2, double y2, double hAngle = 10,
						   double hLength = .1, int col = -1);
	virtual void DrawScaleArrow(double x1, double y1, double x2, double y2, double hAngle = 10,
						   double hLength = .1, int col = -1);

     virtual void DrawLines(double *x, double *y, int N, int col = -1);
     virtual void DrawLines(double *c, int N, int col = -1);
     virtual void DrawLines(coordinate *c, int N, int col = -1);
     virtual void DrawLines(double *x, double *y, int N, int *cols);
     virtual void DrawLines(double *c, int N, int *cols);
     virtual void DrawLines(coordinate *c, int N, int *cols);
     virtual void DrawLines(double *x, double *y, int N, double BIndex, double TIndex, double *Indices);
     virtual void DrawLines(double *c, int N, double BIndex, double TIndex, double *Indices);
     virtual void DrawLines(coordinate *c, int N, double BIndex, double TIndex, double *Indices);
     virtual void DrawLines(double *x, double *y, int N, double *r, double *g, double *b);
     virtual void DrawLines(double *c, int N, double *r, double *g, double *b);
     virtual void DrawLines(coordinate *c, int N, double *r, double *g, double *b);

     virtual void DrawRectangle(double xll, double yll, double xur, double yur, int col = -1);
     virtual void FillRectangle(double xll, double yll, double xur, double yur, int col = -1);
     virtual void DrawFilledRectangle(double xll, double yll, double xur, double yur, int col = -1)
	  { FillRectangle(xll, yll, xur, yur, col); }

     virtual void DrawTriangle(double x1, double y1, double x2, double y2,
				double x3, double y3, int col = -1);
     virtual void FillTriangle(double x1, double y1, double x2, double y2, 
				double x3, double y3, int col = -1);
     virtual void DrawFilledTriangle(double x1, double y1, double x2, double y2, 
				      double x3, double y3, int col = -1)
	  { FillTriangle(x1, y1, x2, y2, x3, y3, col); }

     virtual void DrawPolygon(double *x, double *y, int N, int col = -1);
     virtual void DrawPolygon(double *c, int N, int col = -1);
     virtual void DrawPolygon(coordinate *c, int N, int col = -1);
     virtual void FillPolygon(double *x, double *y, int N, int col = -1);
     virtual void FillPolygon(double *c, int N, int col = -1);
     virtual void FillPolygon(coordinate *c, int N, int col = -1);
     virtual void DrawFilledPolygon(double *x, double *y, int N, int col = -1)
	  { FillPolygon(x, y, N, col); }
     virtual void DrawFilledPolygon(double *c, int N, int col = -1)
	  { FillPolygon(c, N, col); }
     virtual void DrawFilledPolygon(coordinate *c, int N, int col = -1)
	  { FillPolygon(c, N, col); }

     virtual void DrawCircle(double xcenter, double ycenter, double radius, int col = -1);
     virtual void FillCircle(double xcenter, double ycenter, double radius, int col = -1);

     virtual void DrawBall(double xcenter, double ycenter, int radius, int col = -1);
     virtual void FillBall(double xcenter, double ycenter, int radius, int col = -1);

     virtual void DrawFilledCircle(double xcenter, double ycenter, double radius, int col = -1)
	  { FillCircle(xcenter, ycenter, radius, col); }

     virtual void DrawEllipse(double xcenter, double ycenter, double majorAxis, double minorAxis, int col = -1);
     virtual void FillEllipse(double xcenter, double ycenter, double majorAxis, double minorAxis, int col = -1);
     virtual void DrawFilledEllipse(double xcenter, double ycenter, double majorAxis, double minorAxis, int col = -1)
	  { FillEllipse(xcenter, ycenter, majorAxis, minorAxis, col); }
	 virtual void DrawBitmap(const Bitmap& b, double x, double y, double ratio = 1.0, 
							 bool XAlign = true);
	 virtual void Print(double x, double y, jstring& s);
	 virtual void Print(double x, double y, char *s);

	 inline int xmap(double x) { return((int)((x - xll) * xMapScale)); }
     inline int ymap(double y) { return((int)((yur - y) * yMapScale)); }
     inline double xinvmap(int ix) 
	  { return((double)ix / width * (xur - xll) + xll); }
     inline double yinvmap(int iy) 
	  { return((double)(1 - (double)iy / (double)height) * (yur - yll) + yll); }
	 inline int wmap(double w) { return((int)(w * xMapScale)); }
	 inline int hmap(double h) { return((int)(h * yMapScale)); }

// Win32 Necessities
 protected:
     HDC			memdc, memdc2, pdc, mfdc;
     HPEN			DefPen;
     HBRUSH			BackBrush, DefBrush;
     HBITMAP		backbit, backbit2, defBit, defBit2;
     HFONT			courier;
     bool			PixmapCreated;
     RECT			CliRect;
     TEXTMETRIC	    tm;
     PALETTEENTRY 	PalEntries[NUM_COLORS];
     bool			LevelCurves;
     HPALETTE 	    Palette;
     PALETTEENTRY 	entries[NUM_COLORS];
     int            colorBits;
	 char			mfName[255];
	 double			mfXSize;
	 double			mfYSize;
	 int			mfDPI;

	 double mfXMapScale, mfYMapScale;

// Window Metrics
     int SysTextHeight;
     int SysTextWidth;
     int parentw, parenth;

// Window Background Flags

     bool backgroundActive;

// Color Tracking Data
     COLORREF CurCol, oldCurColor;  // oldCurColor for lasso

// Lasso Data
     int lassoXll, lassoYll, lassoXur, lassoYur;
     bool lasso;
	
// Message Handling Functions
	virtual bool OnPaint(intRect update);
	virtual bool OnSize(UINT Width, UINT Height, UINT Type);
	virtual bool OnLButtonDown(int x, int y, UINT Keys);
	virtual bool OnLButtonUp(int x, int y, UINT Keys);
	virtual bool OnLButtonDrag(int x, int y, UINT Keys);

    virtual bool OnLButtonDblClick(int x, int y, UINT Keys)
	{ return MObject::OnLButtonDblClick(x, y, Keys); }
    virtual bool OnRButtonDown(int x, int y, UINT Keys)
	{ return MObject::OnRButtonDown(x, y, Keys); }
    virtual bool OnRButtonUp(int x, int y, UINT Keys)
	{ return MObject::OnRButtonUp(x, y, Keys); }
    virtual bool OnRButtonDblClick(int x, int y, UINT Keys)
	{ return MObject::OnRButtonDblClick(x, y, Keys); }
    virtual bool OnRButtonDrag(int x, int y, UINT Keys)
	{ return MObject::OnRButtonDrag(x, y, Keys); }
    virtual bool OnMButtonDown(int x, int y, UINT Keys)
	{ return MObject::OnMButtonDown(x, y, Keys); }
    virtual bool OnMButtonUp(int x, int y, UINT Keys)
	{ return MObject::OnMButtonUp(x, y, Keys); }
    virtual bool OnMButtonDblClick(int x, int y, UINT Keys)
	{ return MObject::OnMButtonDblClick(x, y, Keys); }
    virtual bool OnMButtonDrag(int x, int y, UINT Keys)
	{ return MObject::OnMButtonDrag(x, y, Keys); }
    virtual bool OnMouseMove(int x, int y, UINT Keys)
	{ return MObject::OnMouseMove(x, y, Keys); }

// Math-Message Handlers
/*     virtual bool OnLButtonDown(double x, double y, UINT Keys);
     virtual bool OnLButtonUp(double x, double y, UINT Keys);
     virtual bool OnLButtonDrag(double x, double y, UINT Keys);
     virtual bool OnRButtonDown(double x, double y, UINT Keys);
     virtual bool OnRButtonUp(double x, double y, UINT Keys);
     virtual bool OnRButtonDrag(double x, double y, UINT Keys);
     virtual bool OnMButtonDown(double x, double y, UINT Keys);
     virtual bool OnMButtonUp(double x, double y, UINT Keys);
     virtual bool OnMButtonDrag(double x, double y, UINT Keys); */
};

#endif //__MathWin_H__











