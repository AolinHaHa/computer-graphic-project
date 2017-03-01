#ifndef __ComboBox_H__
#define __ComboBox_H__

#include "Window.h"

typedef void (EventListener::*ComboBoxCallBack)(void);
 
class ComboBox : public Window
{
public:
	
	enum ComboBoxType { Simple = 0, DropDown = 1, DropDownList = 2 };
	enum ComboOptions { Normal = 0, Sorted = 1 };
	enum ComboBoxReturnCodes { Error = CB_ERR };

	ComboBox() { }
	ComboBox(Window &parent, int xPos, int yPos, int w, int h, ComboBoxType Type = Simple,
		ComboOptions option = Normal );
	ComboBox(Window &parent, int xPos, int yPos, int w, int h,
			void (*ChooseHandler)(int), ComboBoxType Type = Simple, ComboOptions option = Normal);

	void Setup(Window &parent, int xPos, int yPos, int w, int h, ComboBoxType Type = Simple, 
			ComboOptions option = Normal);

	void SetChooseEvent(void (*ChooseHandler)(int)) { chooseHandler = ChooseHandler; }

	template <class T>
	void SetChooseEvent(T *ChooseListener, void (T::*ChooseHandler)(int))
	{ chooseListener = (EventListener *)ChooseListener; dChooseHandler = (void (EventListener::*)(int))ChooseHandler; }

	int ItemLength(int index);

	int SetSelection(int k, bool value = true);
	void SetSelection(int *k, int n);

	int GetText(int Index, char *buffer, int maxLen);
	jstring GetText(int Index);
	int AddItem(const jstring& newItem);
	int InsertItem(const jstring& newItem, int after);
	int DeleteItem(int item);
	int DeleteItem(const jstring& item);
	int ItemIndex(const jstring& item, int startIndex = -1);
	int FindContaining(const jstring& item, int startIndex = -1);
	
	int Count(void);

	int SelectedIndex(void);
	int SelectedItem(char *buffer, int maxLength);
	jstring SelectedItem(void);

	bool IsSingleSelect(void) { return (((BaseStyle & LBS_MULTIPLESEL) == 0) && (BaseStyle & LBS_EXTENDEDSEL) == 0); }

	void Clear(void);


private:

	// The changeHandler is called whenever the text in the box is changed
	// The acceptHandler is called when the user presses the enter key
	// Or changes the focus to another window, implicitly accepting the
	// New value of the box.
	void (*chooseHandler)(int item);
	EventListener *chooseListener;
	void (EventListener::*dChooseHandler)(int item);

	LONG MessageHandler(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
	LONG ProcessMessage(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
};

#endif