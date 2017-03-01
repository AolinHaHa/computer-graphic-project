#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

#include "Window.h"
 
class TextBox : public Window
{
public:
	
	enum BorderStyle { None = 0, Flat = 1, Sunken = 2 };
	// Note, the following styles apply only to Multiline controls
	// in Windows95 and NT4.0
	enum AlignmentType { Left = 0, Right = 1, Center = 2 };
	enum TextBoxType { SingleLine = 0, MultiLine = 1 };

	TextBox() { }
	TextBox(Window &parent, int xPos, int yPos, int w, int h, char *text, 
			BorderStyle Border = Sunken, TextBoxType Type = SingleLine, AlignmentType Alignment = Left);
	TextBox(Window &parent, int xPos, int yPos, int w, int h,
			char *text, void (*AcceptHandler)(char *), void (*ChangeHandler)(char *) = NULL, 
			BorderStyle Border = Sunken, TextBoxType Type = SingleLine, AlignmentType Alignment = Left);
	
	void Setup(Window &parent, int xPos, int yPos, int w, int h, char *text, 
			BorderStyle Border = Sunken, TextBoxType Type = SingleLine, AlignmentType Alignment = Left);

	void SetChangeEvent(void (*ChangeHandler)(char *)) { changeHandler = ChangeHandler; }
	void SetAcceptEvent(void (*AcceptHandler)(char *)) { acceptHandler = AcceptHandler; }

	template <class T>
	void SetChangeEvent(T *ChangeListener, void (T::*ChangeHandler)(char *))
	{ changeListener = (EventListener *)ChangeListener; dChangeHandler = (void (EventListener::*)(char *))ChangeHandler; }
	template <class T>
	void SetAcceptEvent(T *AcceptListener, void (T::*AcceptHandler)(char *))
	{ acceptListener = (EventListener *)AcceptListener; dAcceptHandler = (void (EventListener::*)(char *))AcceptHandler; }

	void SetSelection(int start = -1, int end = -1);
	jstring GetText(void);
	void Clear(void);

	operator const jstring() { return GetText(); }

private:

	// The changeHandler is called whenever the text in the box is changed
	// The acceptHandler is called when the user presses the enter key
	// Or changes the focus to another window, implicitly accepting the
	// New value of the box.
	void CallAcceptEvent(void);
	void (*acceptHandler)(char *);
	EventListener *acceptListener;
	void (EventListener::*dAcceptHandler)(char *newText);

	void (*changeHandler)(char *);
	EventListener *changeListener;
	void (EventListener::*dChangeHandler)(char *newText);

	bool changed;

	LONG MessageHandler(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
	LONG ProcessMessage(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
};

TextBox& operator<<(TextBox& t, const jstring& text);
TextBox& operator<<(TextBox& t, int k);
TextBox& operator<<(TextBox& t, double d);
TextBox& operator<<(TextBox& t, char *d);

TextBox& operator>>(TextBox& t, jstring& text);
TextBox& operator>>(TextBox& t, int &k);
TextBox& operator>>(TextBox& t, double &d);
TextBox& operator>>(TextBox& t, char *d);

#endif