#ifndef __HOLDBUTTON_H__
#define __HOLDBUTTON_H__

#include "Window.h"
#include "Button.h"

class HoldButton : public Window
{
public:
	 
	enum HoldButtonStyle { PushHoldButton = 0, Default = 1, CheckBox = 2, RadioHoldButton = 3, ThreeState = 4,
						GroupBox = 5 };
	// Note, the next styles to not apply to PushHoldButtons
	enum AlignmentType { Left = 0, Right = 1 };

	HoldButton() { }
	HoldButton(Window &parent, int xPos, int yPos, int w, int h,
			char *text, int Style = PushHoldButton, int Alignment = Right);
	HoldButton(Window &parent, int xPos, int yPos, int w, int h,
			char *text, void (*holdHandler)(void), int Style = PushHoldButton, 
			int Alignment = Right);

	void Setup(Window &parent, int xPos, int yPos, int w, int h, char *text, 
		int Style = PushHoldButton, int Alignment = Right);

	void SetAlignment(int align);
	void SetBorder(int border);

	void SetCheck(bool check);
	bool Checked(void);
	void Click(void);

	void SetHoldEvent(void (*HoldHandler)(void)) { holdHandler = HoldHandler; }

	template <class T>
	void SetHoldEvent(T *HoldListener, void (T::*holdHandler)(void))
	{ holdListener = (EventListener *)HoldListener; dHoldHandler = (void (EventListener::*)(void))holdHandler; }

private:

	void OnCommand(size_t Id, size_t Code, HWND hControl);

	HoldButtonStyle style;

	void (*holdHandler)(void);
	EventListener *holdListener;
	void (EventListener::*dHoldHandler)(void);

	LONG MessageHandler(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
	LONG ProcessMessage(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
};

#endif