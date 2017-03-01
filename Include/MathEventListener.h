#ifndef __MATHEVENTLISTENER_H__
#define __MATHEVENTLISTENER_H__
 
#include "EventListener.h"

class MathEventListener : public EventListener
{
public:

	virtual bool OnLButtonDown(double x, int y, size_t Keys) { return false; }
	virtual bool OnLButtonUp(double x, double y, size_t Keys) { return false; }
	virtual bool OnLButtonDblClick(double x, double y, size_t Keys) { return false; }
	virtual bool OnLButtonDrag(double x, double y, size_t Keys) { return false; }
	virtual bool OnRButtonDown(double x, double y, size_t Keys) { return false; }
	virtual bool OnRButtonUp(double x, double y, size_t Keys) { return false; }
	virtual bool OnRButtonDblClick(double x, double y, size_t Keys) { return false; }
	virtual bool OnRButtonDrag(double x, double y, size_t Keys) { return false; }
	virtual bool OnMButtonDown(double x, double y, size_t Keys) { return false; }
	virtual bool OnMButtonUp(double x, double y, size_t Keys) { return false; }
	virtual bool OnMButtonDblClick(double x, double y, size_t Keys) { return false; }
	virtual bool OnMButtonDrag(double x, double y, size_t Keys) { return false; }
	virtual bool OnMouseMove(double x, double y, size_t Keys) { return false; }
};

#endif