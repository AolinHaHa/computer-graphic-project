#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Window.h"
 
class Button : public Window
{
public:
	
	enum ButtonStyle { PushButton = 0, Default = 1, CheckBox = 2, RadioButton = 3, ThreeState = 4,
						GroupBox = 5 };
	// Note, the next styles to not apply to PushButtons
	enum AlignmentType { Left = 0, Right = 1 };

	Button() { }
	Button(Window &parent, int xPos, int yPos, int w, int h,
			char *text, int Style = PushButton, int Alignment = Right, bool Group = false);
	Button(Window &parent, int xPos, int yPos, int w, int h,
			char *text, void (*ClickHandler)(void), int Style = PushButton, 
			int Alignment = Right, bool Group = false);

	void Setup(Window &parent, int xPos, int yPos, int w, int h, char *text, 
		int Style = PushButton, int Alignment = Right, bool Group = false);

	void SetAlignment(int align);
	void SetBorder(int border);

	void SetCheck(bool check);
	bool Checked(void);
	void Click(void);

	void SetClickEvent(void (*ClickHandler)(void)) { clickHandler = ClickHandler; }

	template <class T>
	void SetClickEvent(T *ClickListener, void (T::*ClickHandler)(void))
	{ clickListener = (EventListener *)ClickListener; dClickHandler = (void (EventListener::*)(void))ClickHandler; }

private:

	void OnCommand(size_t Id, size_t Code, HWND hControl);

	ButtonStyle style;

	void (*clickHandler)(void);
	EventListener *clickListener;
	void (EventListener::*dClickHandler)(void);

	LONG MessageHandler(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
	LONG ProcessMessage(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
};


#endif