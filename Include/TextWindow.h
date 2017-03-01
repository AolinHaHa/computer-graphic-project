#ifndef __TEXTWINDOW_H__
#define __TEXTWINDOW_H__
 
#include "AppWindow.h"
#include "LinkedList.h"
#include "jstring.h"

class TextWindow : public AppWindow
{
public:

    TextWindow(int width, int height, int xloc, int yloc);

    TextWindow& operator<<(jstring s);
    TextWindow& operator<<(const char *s) { jstring tmp; tmp << s; (*this) << tmp; return *this; }
    TextWindow& operator<<(const char s) { jstring tmp; tmp << s; (*this) << tmp; return *this; }
    TextWindow& operator<<(double d) { jstring tmp; tmp << d; (*this) << tmp; return *this; }
    TextWindow& operator<<(short k) { jstring tmp; tmp << k; (*this) << tmp; return *this; }
    TextWindow& operator<<(int k) { jstring tmp; tmp << k; (*this) << tmp; return *this; }
    TextWindow& operator<<(long k) { jstring tmp; tmp << k; (*this) << tmp; return *this; }
    TextWindow& operator<<(unsigned short k) { jstring tmp; tmp << k; (*this) << tmp; return *this; }
    TextWindow& operator<<(unsigned int k) { jstring tmp; tmp << k; (*this) << tmp; return *this; }
    TextWindow& operator<<(unsigned long k) { jstring tmp; tmp << k; (*this) << tmp; return *this; }

	bool inputReady(void);
	void setInputDelimiter(const jstring& source) { inputDelimiter = source; }
	TextWindow& operator>>(jstring& dest);
	TextWindow& operator>>(char *dest);
	TextWindow& operator>>(double& d);
	TextWindow& operator>>(short& d);
	TextWindow& operator>>(int& d);
	TextWindow& operator>>(long& d);
	TextWindow& operator>>(unsigned short& d);
	TextWindow& operator>>(unsigned int& d);
	TextWindow& operator>>(unsigned long& d);
	
	void setTabSize(int newSize) { tabSize = newSize; }
    
    void Backspace(void);

protected:

    virtual bool OnPaint();
    virtual bool OnSize(size_t Width, size_t Height, size_t Type);
    virtual bool OnHScroll(HWND Scrollbar, size_t Code, unsigned short nPos);
    virtual bool OnVScroll(HWND Scrollbar, size_t Code, unsigned short nPos);
    virtual bool OnCommand(HWND hControl, size_t Id, size_t Code);
    virtual bool OnChar(size_t Value, size_t Repeat);
    virtual bool OnTimer(size_t timerId);

    virtual bool OnQuit(void);
    virtual void OnSaveAs(void);
    
    void ResizeBuffer(int newSize);
    void InsertLine(int location);

    void AdjustScrollBars(void);
    int vScrollMax, vScrollMin;
    int hScrollMax, hScrollMin;

    HFONT font;
    char fontName[40];
    int fontSize;
    int textWidth;
    int textHeight;
    int charWidth;
    int charHeight;
    int widthInChars;
    int heightInChars;

    jstring *buffer;
    int bufferSize; // The current size of the buffer array
    int nLines; // The current number of used lines in the buffer array
	int tabSize;

    jstring inputBuffer;
    int curInputLength; // This controls how many characters can be deleted with backspace
	jstring inputDelimiter;

    int curX;
    int curY;
    int oldCurX;
    int oldCurY;
    bool cursorState;

    int leftX;
    int topY;
};

#endif