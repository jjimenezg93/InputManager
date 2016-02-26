#ifndef _C_EVENT_H
#define _C_EVENT_H

#include "types.h"

enum EEventController {
	EEC_MOUSE,
	EEC_KEYBOARD,
	EEC_PAD,
	EEC_NONE };

enum EMouseEventID {
	EME_LMB_PRESS,
	EME_LMB_RELEASE,
	EME_LMB_CLICK,
	EME_RMB_PRESS,
	EME_RMB_RELEASE,
	EME_RMB_CLICK };

enum EKeyboardEventID {
	EKE_SPACE
};

class CEvent {
public:
	CEvent(const EEventController controller, const uint32 id,
			const double x = 0, const double y = 0);

	EEventController GetController() const { return m_controller; }
	uint32 GetId() const { return m_id; }

	void SetId(EMouseEventID newId) { m_id = newId; }
	
	double GetX() const { return m_x; }
	double GetY() const { return m_y; }
private:
	EEventController m_controller;
	uint32 m_id;
	double m_x, m_y;
};

#endif //!_C_EVENT_H