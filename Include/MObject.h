#ifndef __MOBJECT_H__
#define __MOBJECT_H__

////////////////////////////////////////////////////////////////////////////
//  
//  MObject.h: Interface for the base class of all Math Windows
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

class MObject 
{
// Constructors

 public:
     MObject() { MObjectSetup(); }

// Destructors
     virtual ~MObject() {}

 protected:
	void MObjectSetup(void);

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
 
// Drawing State Functions

     virtual void Draw(void) = 0;
	 virtual void Refresh(void) { Draw(); }
     virtual void Erase(void) = 0;
     virtual void EraseAll(void) = 0;
     virtual void SetView(double Xll, double Yll, double Xur, double Yur) = 0;

     virtual void SetLineWidth(int w) = 0;
     virtual void SetLineStyle(int s) = 0;

// Window Attribute Accessors
       
     virtual double ViewWidth(void) = 0;
     virtual double ViewHeight(void) = 0;
     virtual double PixelWidth(void) = 0;
     virtual double PixelHeight(void) = 0;

// 2D Drawing Style Functions

     virtual void SetXor(bool flag) = 0;
     virtual void DrawToBackground(void) = 0;
     virtual void DrawToForeground(void) = 0;
     virtual void DisableBackground(void) = 0;
     virtual void ActivateBackground(void) = 0;
     virtual void SetDrawOver(void) { SetXor(false); }
     virtual void SetDrawCombine(void) { SetXor(true); }

// 2D Drawing Functions

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

// Transform Functions

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

     inline void UndoTransforms(int count = 1)
     { tCount -= count; if (tCount < 1) tCount = 1; }

// Message Handling

 public:
    virtual void SetLButtonDownMath(void (*handler)(double x, double y))
    { mlButtonDown = handler; }
    virtual void SetLButtonUpMath(void (*handler)(double x, double y))
    { mlButtonUp = handler; }
    virtual void SetLButtonDblClickMath(void (*handler)(double x, double y))
    { mlButtonDblClick = handler; }
    virtual void SetLButtonDragMath(void (*handler)(double x, double y))
    { mlButtonDrag = handler; }
    virtual void SetRButtonDownMath(void (*handler)(double x, double y))
    { mrButtonDown = handler; }
    virtual void SetRButtonUpMath(void (*handler)(double x, double y))
    { mrButtonUp = handler; }
    virtual void SetRButtonDblClickMath(void (*handler)(double x, double y))
    { mrButtonDblClick = handler; }
    virtual void SetRButtonDragMath(void (*handler)(double x, double y))
    { mrButtonDrag = handler; }
    virtual void SetMButtonDownMath(void (*handler)(double x, double y))
    { mmButtonDrag = handler; }
    virtual void SetMButtonUpMath(void (*handler)(double x, double y))
    { mmButtonUp = handler; }
    virtual void SetMButtonDblClickMath(void (*handler)(double x, double y))
    { mmButtonDblClick = handler; }
    virtual void SetMButtonDragMath(void (*handler)(double x, double y))
    { mmButtonDrag = handler; }
    virtual void SetMouseMoveMath(void (*handler)(double x, double y))
    { mmouseMove = handler; }

// 2D Helper Functions

 protected:
     virtual int xmap(double x) = 0;
     virtual int ymap(double y) = 0;
     virtual double xinvmap(int ix) = 0; 
     virtual double yinvmap(int iy) = 0; 
	 virtual int wmap(double w) = 0;
	 virtual int hmap(double h) = 0;
     
// View Data
	double xll, yll, xur, yur;
	double xMapScale, yMapScale;
	double aspect, size;

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

	JMatrix transforms[200];
	int tCount;
 
    void (*mlButtonDown)(double x, double y);
    void (*mlButtonUp)(double x, double y);
    void (*mlButtonDblClick)(double x, double y);
    void (*mlButtonDrag)(double x, double y);
    void (*mrButtonDown)(double x, double y);
    void (*mrButtonUp)(double x, double y);
    void (*mrButtonDblClick)(double x, double y);
    void (*mrButtonDrag)(double x, double y);
    void (*mmButtonDown)(double x, double y);
    void (*mmButtonUp)(double x, double y);
    void (*mmButtonDblClick)(double x, double y);
    void (*mmButtonDrag)(double x, double y);
    void (*mmouseMove)(double x, double y);

	EventListener *mlDownHandler;
    void (EventListener::*mdLButtonDown)(double x, double y);
	EventListener *mlUpHandler;
    void (EventListener::*mdLButtonUp)(double x, double y);
	EventListener *mlDblClickHandler;
    void (EventListener::*mdLButtonDblClick)(double x, double y);
	EventListener *mlDragHandler;
    void (EventListener::*mdLButtonDrag)(double x, double y);
	EventListener *mrDownHandler;
    void (EventListener::*mdRButtonDown)(double x, double y);
	EventListener *mrUpHandler;
    void (EventListener::*mdRButtonUp)(double x, double y);
	EventListener *mrDblClickHandler;
    void (EventListener::*mdRButtonDblClick)(double x, double y);
	EventListener *mrDragHandler;
    void (EventListener::*mdRButtonDrag)(double x, double y);
	EventListener *mmDownHandler;
    void (EventListener::*mdMButtonDown)(double x, double y);
	EventListener *mmUpHandler;
    void (EventListener::*mdMButtonUp)(double x, double y);
	EventListener *mmDblClickHandler;
    void (EventListener::*mdMButtonDblClick)(double x, double y);
	EventListener *mmDragHandler;
    void (EventListener::*mdMButtonDrag)(double x, double y);
	EventListener *mMoveHandler;
    void (EventListener::*mdMouseMove)(double x, double y);

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

	virtual bool OnLButtonDown(double x, double y, UINT Keys);
	virtual bool OnLButtonUp(double x, double y, UINT Keys);
	virtual bool OnLButtonDrag(double x, double y, UINT Keys);
	virtual bool OnLButtonDblClick(double x, double y, UINT Keys);
	virtual bool OnRButtonDown(double x, double y, UINT Keys);
	virtual bool OnRButtonUp(double x, double y, UINT Keys);
	virtual bool OnRButtonDrag(double x, double y, UINT Keys);
	virtual bool OnRButtonDblClick(double x, double y, UINT Keys);
	virtual bool OnMButtonDown(double x, double y, UINT Keys);
	virtual bool OnMButtonUp(double x, double y, UINT Keys);
	virtual bool OnMButtonDrag(double x, double y, UINT Keys);
	virtual bool OnMButtonDblClick(double x, double y, UINT Keys);
	virtual bool OnMouseMove(double x, double y, UINT Keys);
};

#endif










