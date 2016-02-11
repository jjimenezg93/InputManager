#ifndef _C_EVENT_H
#define _C_EVENT_H

#ifndef UGINE_TYPES_H
#include "../../ugine/include/types.h"
#endif

enum EEventController { EEC_MOUSE, EEC_KEYBOARD, EEC_PAD };

class CEvent {
public:
	CEvent(EEventController controller, uint32 id, double x = 0, double y = 0);

	EEventController GetController() { return m_controller; }
	uint32 GetId() { return m_id; }
	
	double GetX() { return m_x; }
	double GetY() { return m_y; }
private:
	EEventController m_controller;
	uint32 m_id;
	double m_x, m_y;
};

#endif //!_C_EVENT_H