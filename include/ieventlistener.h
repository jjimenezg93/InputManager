#ifndef _I_EVENT_LISTENER_H
#define _I_EVENT_LISTENER_H

class CControlUI;

class IEventListener {
public:
	virtual void ManageEvent(const CEvent * const event) = 0;
protected:
	virtual void OnClick(CControlUI * sender) {}
	virtual void OnHover(CControlUI * sender) {}
	virtual void OnLostHover(CControlUI * sender) {}
	virtual void OnKeyDown(CControlUI * sender) {}
	virtual void OnKeyUp(CControlUI * sender) {}
};

#endif _I_EVENT_LISTENER_H