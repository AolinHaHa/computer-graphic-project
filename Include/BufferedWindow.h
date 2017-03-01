#ifndef __BUFFEREDWINDOW_H__
#define __BUFFEREDWINDOW_H__

#include "AppWindow.h"
#include "Bitmap.h"
 
class BufferedWindow : public EventListener, public WinObject, public Bitmap
{
public:
	BufferedWindow();
	BufferedWindow(BOOL Visible);
	BufferedWindow(int x, int y, int width, int height, BOOL Visible = TRUE, char *cName = NULL);
	BufferedWindow(int x, int y, int width, int height, double bgr, double bgg, double bgb, 
		BOOL Visible = TRUE, char *cName = NULL);
	BufferedWindow(Window &parent, int x, int y, int width, int height, BOOL Visible = TRUE, char *cName = NULL);
	BufferedWindow(Window &parent, int x, int y, int width, int height, double bgr, double bgg, double bgb, 
		BOOL Visible = TRUE, char *cName = NULL);
	virtual ~BufferedWindow();

	void Setup(Window &Parent, int Width, int Height);
	void Setup(Window *parent, int x, int y, int width, int height, BOOL Visible = TRUE, char *cName = NULL);
	void Setup(int x, int y, int width, int height, BOOL Visible = TRUE, char *cName = NULL)
	{ Setup(NULL, x, y, width, height, Visible, cName); }

	virtual int XPos() { return win.XPos(); }
	virtual int YPos() { return win.YPos(); }

    virtual void SetBorder(bool flag = true) { win.SetBorder(flag); }
	virtual void SetParent(Window &Win, int x = -1, int y = -1, int w = -1, int h = -1)
	{ win.SetParent(Win, x, y, w, h); }
	virtual void SetParent(int x = -1, int y = -1, int w = -1, int h = -1)
	{ win.SetParent(x, y, w, h); }
	virtual void SetParent(Window *Win, int x = -1, int y = -1, int w = -1, int h = -1)
	{ win.SetParent(Win, x, y, w, h); }
	virtual void SetTitle(char *text)
	{ win.SetTitle(text); }

	virtual int SetText(char *Format, ...)
	{ va_list l; va_start(l, Format); char text[255]; vsprintf(text, Format, l); 
	  return win.SetText(text); }

	virtual void Move(int X, int Y, int Width, int Height, bool repaint = TRUE);
	virtual void Move(int X, int Y, bool repaint = TRUE)
	{ win.Move(X, Y, repaint); }
	virtual void Resize(int Width, int Height, bool repaint = TRUE);
	virtual BOOL Show(int Cmd = SW_SHOW) 
	{ return win.Show(Cmd); }
	virtual void Update(void);

	virtual void Print(void)
	{ win.Print(); }

	virtual void AddEventListener(EventListener *l)
	{ win.AddEventListener(l); }
	virtual void RemoveEventListener(EventListener *l)
	{ win.RemoveEventListener(l); }

	virtual bool OnClose(void) { delete this; return true; }
	virtual bool OnSize(size_t Width, size_t Height, size_t Type) 
    { 
    	Bitmap::Resize(Width, Height, true);
        return true; 
    }
	virtual bool OnPaint(intRect rect);
	virtual void Refresh(void);

    virtual void AddMainMenu(void)
	{ win.AddMainMenu(); }
	virtual void AddSubMenu(char *name)
	{ win.AddSubMenu(name); }
	virtual void AddFileMenu(void)
	{ win.AddFileMenu(); }
	virtual void AddMenuItem(char *name, char *subMenuName, void (*handler)(void))
	{ win.AddMenuItem(name, subMenuName, handler); }

	template <class T>
	void AddMenuItem(char *name, char *subMenuName, T *hObj, void (T::*handler)(void))
	{ win.AddMenuItem(name, subMenuName, hObj, handler); }

	// The following may be used if you will be handling command events manually.
	virtual void AddMenuItem(char *name, char *subMenuName, int ID) 
	{ win.AddMenuItem(name, subMenuName, ID); }

	virtual void SetCloseEvent(void (*handler)(void))
	{ win.SetCloseEvent(handler); }
	virtual void SetSizeEvent(void (*handler)(size_t w, size_t h))
	{ win.SetSizeEvent(handler); }
	virtual void SetMoveEvent(void (*handler)(size_t xPos, size_t yPos))
	{ win.SetMoveEvent(handler); }
	virtual void SetCharPressedEvent(void (*handler)(char c, size_t repeat))
	{ win.SetCharPressedEvent(handler); }
	virtual void SetKeyDownEvent(void (*handler)(size_t key))
	{ win.SetKeyDownEvent(handler); }
	virtual void SetKeyUpEvent(void (*handler)(size_t key))
	{ win.SetKeyUpEvent(handler); }
	virtual void SetLButtonDownEvent(void (*handler)(int x, int y))
	{ win.SetLButtonDownEvent(handler); }
    virtual void SetLButtonUpEvent(void (*handler)(int x, int y))
	{ win.SetLButtonUpEvent(handler); }
    virtual void SetLButtonDblClickEvent(void (*handler)(int x, int y))
	{ win.SetLButtonDblClickEvent(handler); }
    virtual void SetLButtonDragEvent(void (*handler)(int x, int y))
	{ win.SetLButtonDragEvent(handler); }
    virtual void SetRButtonDownEvent(void (*handler)(int x, int y))
	{ win.SetRButtonDownEvent(handler); }
    virtual void SetRButtonUpEvent(void (*handler)(int x, int y))
	{ win.SetRButtonUpEvent(handler); }
    virtual void SetRButtonDblClickEvent(void (*handler)(int x, int y))
	{ win.SetRButtonDblClickEvent(handler); }
    virtual void SetRButtonDragEvent(void (*handler)(int x, int y))
	{ win.SetRButtonDragEvent(handler); }
    virtual void SetMButtonDownEvent(void (*handler)(int x, int y))
	{ win.SetMButtonDownEvent(handler); }
    virtual void SetMButtonUpEvent(void (*handler)(int x, int y))
	{ win.SetMButtonUpEvent(handler); }
    virtual void SetMButtonDblClickEvent(void (*handler)(int x, int y))
	{ win.SetMButtonDblClickEvent(handler); }
    virtual void SetMButtonDragEvent(void (*handler)(int x, int y))
	{ win.SetMButtonDragEvent(handler); }
    virtual void SetMouseMoveEvent(void (*handler)(int x, int y))
	{ win.SetMouseMoveEvent(handler); }
	virtual void SetPaintEvent(void (*handler)(intRect rect))
	{ win.SetPaintEvent(handler); }
	virtual void SetGotFocusEvent(void (*handler)(void))
	{ win.SetGotFocusEvent(handler); }
	virtual void SetLostFocusEvent(void (*handler)(void))
	{ win.SetLostFocusEvent(handler); }
	virtual void SetCommandEvent(void (*handler)(size_t id))
	{ win.SetCommandEvent(handler); }
	virtual void SetTimerEvent(void (*handler)(size_t id))
	{ win.SetTimerEvent(handler); }

	template <class T> void SetCloseEvent(EventListener *hObj, void (T::*handler)(void))
	{ win.SetCloseEvent(hObj, handler); }
	template <class T> void SetSizeEvent(EventListener *hObj, void (T::*handler)(size_t w, size_t h))
	{ win.SetSizeEvent(hObj, handler); }
	template <class T> void SetMoveEvent(EventListener *hObj, void (T::*handler)(size_t xPos, size_t yPos))
	{ win.SetMoveEvent(hObj, handler); }
	template <class T> void SetCharPressedEvent(EventListener *hObj, void (T::*handler)(char c, size_t repeat))
	{ win.SetCharPressedEvent(hObj, handler); }
	template <class T> void SetKeyDownEvent(EventListener *hObj, void (T::*handler)(size_t key))
	{ win.SetKeyDownEvent(hObj, handler); }
	template <class T> void SetKeyUpEvent(EventListener *hObj, void (T::*handler)(size_t key))
	{ win.SetKeyUpEvent(hObj, handler); }
	template <class T> void SetLButtonDownEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetLButtonDownEvent(hObj, handler); }
    template <class T> void SetLButtonUpEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetLButtonUpEvent(hObj, handler); }
    template <class T> void SetLButtonDblClickEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetLButtonDblClickEvent(hObj, handler); }
    template <class T> void SetLButtonDragEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetLButtonDragEvent(hObj, handler); }
    template <class T> void SetRButtonDownEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetRButtonDownEvent(hObj, handler); }
    template <class T> void SetRButtonUpEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetRButtonUpEvent(hObj, handler); }
    template <class T> void SetRButtonDblClickEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetRButtonDblClickEvent(hObj, handler); }
    template <class T> void SetRButtonDragEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetRButtonDragEvent(hObj, handler); }
    template <class T> void SetMButtonDownEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetMButtonDownEvent(hObj, handler); }
    template <class T> void SetMButtonUpEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetMButtonUpEvent(hObj, handler); }
    template <class T> void SetMButtonDblClickEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetMButtonDblClickEvent(hObj, handler); }
    template <class T> void SetMButtonDragEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetMButtonDragEvent(hObj, handler); }
    template <class T> void SetMouseMoveEvent(EventListener *hObj, void (T::*handler)(int x, int y))
	{ win.SetMouseMoveEvent(hObj, handler); }
	template <class T> void SetPaintEvent(EventListener *hObj, void (T::*handler)(intRect rect))
	{ win.SetPaintEvent(hObj, handler); }
	template <class T> void SetGotFocusEvent(EventListener *hObj, void (T::*handler)(void))
	{ win.SetGotFocusEvent(hObj, handler); }
	template <class T> void SetLostFocusEvent(EventListener *hObj, void (T::*handler)(void))
	{ win.SetLostFocusEvent(hObj, handler); }
	template <class T> void SetCommandEvent(EventListener *hObj, void (T::*handler)(size_t id))
	{ win.SetCommandEvent(hObj, handler); }
	template <class T> void SetTimerEvent(EventListener *hObj, void (T::*handler)(size_t id))
	{ win.SetTimerEvent(hObj, handler); }

	virtual operator HWND()
	{ return HWND(win); }

	virtual operator Window&() { return win; }

protected:

	AppWindow win;
};

#endif 