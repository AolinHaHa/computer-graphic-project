#ifndef __MWIN_H__
#define __MWIN_H__

////////////////////////////////////////////////////////////////////////////
//  
//  MWin.h: Interface for the base class of all Math Windows
//
////////////////////////////////////////////////////////////////////////////

#include "window.h"
#include "JMatrix.h"

class coordinate 
{
 public:
     double x, y;
};

typedef coordinate doublePoint;

class WColor
{
 public:
     double r, g, b;
     
     WColor(double R = 0.0, double G = 0.0, double B = 0.0)
	  { r = R; g = G; b = B; }
};

WColor WColorArray(WColor First, WColor Last, double RangeB, double RangeT, double Index);

#define NUM_COLORS		256

class MWin : public Window  
{
// Constructors

 public:
     MWin() : Window() { MWinSetup(); }
     MWin(int x, int y, int width, int height, bool Visible = true) :
	  Window(x, y, width, height, Visible) { MWinSetup(); }
     MWin(Window &parent, int x, int y, int width, int height, bool Visible = true) :
	  Window(parent, x, y, width, height, Visible) { MWinSetup(); }

// Destructors
     virtual ~MWin() {}

 protected:
	void MWinSetup(void);

// Color Functions

 public:
     virtual void SetupColor(void) = 0;
     virtual void SetColorref(COLORREF col) = 0;
     virtual void SetColor(int col) = 0;
     virtual void SetColor(int r, int g, int b) = 0;
     virtual void SetColor(double r, double g, double b) = 0;
     virtual void SetColor(WColor color) = 0;
     virtual void SetColor(WColor First, WColor Last, double BIndex, double TIndex, double Index) = 0;

	 virtual void SetMapColor(double bottom, double top, double index) { }

     virtual void SetBackgroundColorref(COLORREF col) = 0;
     virtual void SetBackgroundColor(int col) = 0;
     virtual void SetBackgroundColor(int r, int g, int b) = 0;
     virtual void SetBackgroundColor(double r, double g, double b) = 0;

// Loading and Saving

     virtual void SaveWindow(char *fileName) = 0;
     virtual void LoadWindow(char *fileName, bool toBackground) = 0;
	 virtual void ActivateMetafile(char *name, double XSize, double YSize, int DPI) { }
	 virtual void DisableMetafile() { }
 
// Drawing State Functions

 public:
     virtual void Draw(void) = 0;
     virtual void Erase(void) = 0;
     virtual void EraseAll(void) = 0;
     virtual void SetView(double Xll, double Yll, double Xur, double Yur) = 0;

     virtual void SetLineWidth(int w) = 0;
     virtual void SetLineStyle(int s) = 0;

// Window Attribute Accessors
       
	  public:
     virtual double GetWidth(void) = 0;
     virtual double GetHeight(void) = 0;
     virtual int GetIntWidth(void) = 0;
     virtual int GetIntHeight(void) = 0;
     virtual double GetPixelWidth(void) = 0;
     virtual double GetPixelHeight(void) = 0;

// 2D Drawing Style Functions

 public:
     virtual void SetXor(bool flag) = 0;
     virtual void DrawToBackground(void) = 0;
     virtual void DrawToForeground(void) = 0;
     virtual void DisableBackground(void) = 0;
     virtual void ActivateBackground(void) = 0;
     virtual void SetDrawOver(void) { SetXor(false); }
     virtual void SetDrawCombine(void) { SetXor(true); }

// 2D Drawing Functions

 public:
     virtual void DrawAxes(int col = -1) = 0;

     virtual void DrawPoint(double x, double y, int col = -1) = 0;
     virtual void DrawPoint(int x, int y, int col = -1) = 0;
     virtual void DrawPoint(double x, double y, double CScaleB, double CScaleT, double Index) = 0;
     virtual void DrawPoint(int x, int y, double CScaleB, double CScaleT, double Index) = 0;

     virtual void DrawLine(double x1, double y1, double x2, 
			    double y2, int col = -1) = 0;
     virtual void DrawLine(coordinate c1, coordinate c2, int col = -1) = 0;

     virtual void DrawLines(double *x, double *y, int N, int col = -1) = 0;
     virtual void DrawLines(double *c, int N, int col = -1) = 0;
     virtual void DrawLines(coordinate *c, int N, int col = -1) = 0;
     virtual void DrawLines(double *x, double *y, int N, int *cols) = 0;
     virtual void DrawLines(double *c, int N, int *cols) = 0;
     virtual void DrawLines(coordinate *c, int N, int *cols) = 0;
     virtual void DrawLines(double *x, double *y, int N, double BIndex, double TIndex, double *Indices) = 0;
     virtual void DrawLines(double *c, int N, double BIndex, double TIndex, double *Indices) = 0;
     virtual void DrawLines(coordinate *c, int N, double BIndex, double TIndex, double *Indices) = 0;
     virtual void DrawLines(double *x, double *y, int N, double *r, double *g, double *b) = 0;
     virtual void DrawLines(double *c, int N, double *r, double *g, double *b) = 0;
     virtual void DrawLines(coordinate *c, int N, double *r, double *g, double *b) = 0;

     virtual void DrawRectangle(double xll, double yll, double xur, double yur, int col = -1) = 0;
     virtual void FillRectangle(double xll, double yll, double xur, double yur, int col = -1) = 0;
     virtual void DrawFilledRectangle(double xll, double yll, double xur, double yur, int col = -1) = 0;

     virtual void DrawTriangle(double x1, double y1, double x2, double y2,
				double x3, double y3, int col = -1) = 0;
     virtual void FillTriangle(double x1, double y1, double x2, double y2, 
				double x3, double y3, int col = -1) = 0;
     virtual void DrawFilledTriangle(double x1, double y1, double x2, double y2, 
				      double x3, double y3, int col = -1) = 0;

     virtual void DrawPolygon(double *x, double *y, int N, int col = -1) = 0;
     virtual void DrawPolygon(coordinate *c, int N, int col = -1) = 0;
     virtual void DrawPolygon(double *coord, int N, int col = -1) = 0;
     virtual void FillPolygon(double *x, double *y, int N, int col = -1) = 0;
     virtual void FillPolygon(coordinate *c, int N, int col = -1) = 0;
     virtual void FillPolygon(double *coord, int N, int col = -1) = 0;
     virtual void DrawFilledPolygon(double *x, double *y, int N, int col = -1) = 0;
     virtual void DrawFilledPolygon(coordinate *c, int N, int col = -1) = 0;
     virtual void DrawFilledPolygon(double *coord, int N, int col = -1) = 0;

     virtual void DrawCircle(double xcenter, double ycenter, double radius, int col = -1) = 0;
     virtual void FillCircle(double xcenter, double ycenter, double radius, int col = -1) = 0;
     virtual void DrawFilledCircle(double xcenter, double ycenter, double radius, int col = -1) = 0;

     virtual void DrawEllipse(double xcenter, double ycenter, double majorAxis, double minorAxis, int col = -1) = 0;
     virtual void FillEllipse(double xcenter, double ycenter, double majorAxis, double minorAxis, int col = -1) = 0;
     virtual void DrawFilledEllipse(double xcenter, double ycenter, double majorAxis, double minorAxis, int col = -1) = 0;

     virtual void DrawBall(double xcenter, double ycenter, int radius, int col = -1) = 0;
     virtual void FillBall(double xcenter, double ycenter, int radius, int col = -1) = 0;
	 virtual void DrawBitmap(const class Bitmap& b, double x, double y, double ratio = 1.0, 
		 bool XAlign = true) { };

// 2D Helper Functions

 protected:
     inline int xmap(double x) { return((int)((x - xll) * xMapScale)); }
     inline int ymap(double y) { return((int)((yur - y) * yMapScale)); }
     inline double xinvmap(int ix) 
	  { return((double)ix / width * (xur - xll) + xll); }
     inline double yinvmap(int iy) 
	  { return((double)(1 - (double)iy / (double)height) * (yur - yll) + yll); }
	 inline int wmap(double w) { return((int)(w * xMapScale)); }
	 inline int hmap(double h) { return((int)(h * yMapScale)); }
     
// View Data
     double xll, yll, xur, yur;
     double xMapScale, yMapScale;
     double aspect, size;

     JMatrix transforms[200];
     int tCount;
 
 public:

     inline void Rotate(double angle)
     { if (tCount > 200) return;
       JCopy(transforms[tCount], transforms[tCount-1]); JPreRotateZ(transforms[tCount], angle);
       tCount++; }

     inline void Translate(double dx, double dy)
     { if (tCount > 200) return;
       JCopy(transforms[tCount], transforms[tCount-1]); 
       JPreTranslate(transforms[tCount], dx, dy, 0.0);
       tCount++; }

     inline void Scale(double sx, double sy)
     { if (tCount > 200) return;
       JCopy(transforms[tCount], transforms[tCount-1]);
       JPreScale(transforms[tCount], sx, sy, 1.0);
       tCount++; }

     inline void UndoTransforms(int count)
     { tCount -= count; if (tCount < 1) tCount = 1; }

     inline void TransformCoord(double x, double y, double &rx, double &ry)
     { 
		 if (tCount > 1) { JEvaluate(transforms[tCount-1], x, y, rx, ry); } 
	 }

     inline void TransformCoord(double *x, double *rx)
     { if (tCount > 1) { JEvaluate(transforms[tCount-1], x[0], x[1], rx[0], rx[1]); } }

     inline void TransformCoord(double *x, double *rx, int N)
     { if (tCount > 1) { 
         for (int i = 0; i < N; i++) 
            JEvaluate(transforms[tCount-1], x[2*i], x[2*i+1], rx[2*i], rx[2*i+1]); } }

     inline void TransformCoord(double *x, double *y, double *rx, double *ry, int N)
     { if (tCount > 1) { 
         for (int i = 0; i < N; i++) 
            JEvaluate(transforms[tCount-1], x[i], y[i], rx[i], ry[i]); } }

// Message Handling

 public:
    virtual void SetLButtonDown(void (*handler)(double x, double y))
    { lButtonDown = handler; }
    virtual void SetLButtonDown(void (*handler)(double x, double y, void *data), void *data)
    { lButtonDown2 = handler; lDownData = data; }
    virtual void SetLButtonUp(void (*handler)(double x, double y))
    { lButtonUp = handler; }
    virtual void SetLButtonUp(void (*handler)(double x, double y, void *data), void *data)
    { lButtonUp2 = handler; lUpData = data; }
    virtual void SetLButtonDblClick(void (*handler)(double x, double y))
    { lButtonDblClick = handler; }
    virtual void SetLButtonDblClick(void (*handler)(double x, double y, void *data), void *data)
    { lButtonDblClick2 = handler; lDblClickData = data; }
    virtual void SetLButtonDrag(void (*handler)(double x, double y))
    { lButtonDrag = handler; }
    virtual void SetLButtonDrag(void (*handler)(double x, double y, void *data), void *data)
    { lButtonDrag2 = handler; lDragData = data; }
    virtual void SetRButtonDown(void (*handler)(double x, double y))
    { rButtonDown = handler; }
    virtual void SetRButtonDown(void (*handler)(double x, double y, void *data), void *data)
    { rButtonDown2 = handler; rDownData = data; }
    virtual void SetRButtonUp(void (*handler)(double x, double y))
    { rButtonUp = handler; }
    virtual void SetRButtonUp(void (*handler)(double x, double y, void *data), void *data)
    { rButtonUp2 = handler; rUpData = data; }
    virtual void SetRButtonDblClick(void (*handler)(double x, double y))
    { rButtonDblClick = handler; }
    virtual void SetRButtonDblClick(void (*handler)(double x, double y, void *data), void *data)
    { rButtonDblClick2 = handler; rDblClickData = data; }
    virtual void SetRButtonDrag(void (*handler)(double x, double y))
    { rButtonDrag = handler; }
    virtual void SetRButtonDrag(void (*handler)(double x, double y, void *data), void *data)
    { rButtonDrag2 = handler; rDragData = data; }
    virtual void SetMButtonDown(void (*handler)(double x, double y))
    { mButtonDrag = handler; }
    virtual void SetMButtonUp(void (*handler)(double x, double y))
    { mButtonUp = handler; }
    virtual void SetMButtonDblClick(void (*handler)(double x, double y))
    { mButtonDblClick = handler; }
    virtual void SetMButtonDrag(void (*handler)(double x, double y))
    { mButtonDrag = handler; }
    virtual void SetMouseMove(void (*handler)(double x, double y))
    { mouseMove = handler; }

 protected:
    void (*lButtonDown)(double x, double y);
    void (*lButtonDown2)(double x, double y, void *data);
    void *lDownData;
    void (*lButtonUp)(double x, double y);
    void (*lButtonUp2)(double x, double y, void *data);
    void *lUpData;
    void (*lButtonDblClick)(double x, double y);
    void (*lButtonDblClick2)(double x, double y, void *data);
    void *lDblClickData;
    void (*lButtonDrag)(double x, double y);
    void (*lButtonDrag2)(double x, double y, void *data);
    void *lDragData;
    void (*rButtonDown)(double x, double y);
    void (*rButtonDown2)(double x, double y, void *data);
    void *rDownData;
    void (*rButtonUp)(double x, double y);
    void (*rButtonUp2)(double x, double y, void *data);
    void *rUpData;
    void (*rButtonDblClick)(double x, double y);
    void (*rButtonDblClick2)(double x, double y, void *data);
    void *rDblClickData;
    void (*rButtonDrag)(double x, double y);
    void (*rButtonDrag2)(double x, double y, void *data);
    void *rDragData;
    void (*mButtonDown)(double x, double y);
    void (*mButtonDown2)(double x, double y, void *data);
    void *mDownData;
    void (*mButtonUp)(double x, double y);
    void (*mButtonUp2)(double x, double y, void *data);
    void *mUpData;
    void (*mButtonDblClick)(double x, double y);
    void (*mButtonDblClick2)(double x, double y, void *data);
    void *mDblClickData;
    void (*mButtonDrag)(double x, double y);
    void (*mButtonDrag2)(double x, double y, void *data);
    void *mDragData;
    void (*mouseMove)(double x, double y);
    void (*mouseMove2)(double x, double y, void *data);
    void *moveData;

    class AppWin *ParentWin;

//     virtual bool OnPaint();
//     virtual bool OnSize(UINT Width, UINT Height, UINT Type);
    virtual bool OnKeyDown(UINT VirtKey, KEYCODES Codes);
    virtual bool OnLButtonDown(int x, int y, UINT Keys);
    virtual bool OnLButtonUp(int x, int y, UINT Keys);
    virtual bool OnLButtonDblClick(int x, int y, UINT Keys);
    virtual bool OnLButtonDrag(int x, int y, UINT Keys);
    virtual bool OnRButtonDown(int x, int y, UINT Keys);
    virtual bool OnRButtonUp(int x, int y, UINT Keys);
    virtual bool OnRButtonDblClick(int x, int y, UINT Keys);
    virtual bool OnRButtonDrag(int x, int y, UINT Keys);
    virtual bool OnMButtonDown(int x, int y, UINT Keys);
    virtual bool OnMButtonUp(int x, int y, UINT Keys);
    virtual bool OnMButtonDblClick(int x, int y, UINT Keys);
    virtual bool OnMButtonDrag(int x, int y, UINT Keys);
    virtual bool OnMouseMove(int x, int y, UINT Keys);

    friend class AppWin;

};

#endif










