#ifndef _C_CONTROL_UI_H
#define _C_CONTROL_UI_H

#include "../include/types.h"

#include <vector>

class CEvent;
class SMessage;
class IEventListener;

class CControlUI {
public:
	virtual uint8 Init() = 0;
	virtual void Update();
	virtual void Render();
	virtual void ManageEvent(const CEvent * const ev); //manages input event and then reproduces it
	//ManageEvent should return uint8 to inform if control consumes event
	virtual void AddEventListener(IEventListener * const eventListener);
	virtual void RemoveEventListener(IEventListener * const eventListener);
	virtual void AddControl(CControlUI * const control);
	virtual void RemoveControl(CControlUI * const control);
protected:
	std::vector<IEventListener *> m_listeners;
	std::vector<CControlUI *> m_controls;
};

#endif //!_C_CONTROL_UI_H