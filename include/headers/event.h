#ifndef _C_EVENT_H
#define _C_EVENT_H

#ifndef UGINE_TYPES_H
#include "../../ugine/include/types.h"
#endif

enum EEventController { EEC_MOUSE, EEC_KEYBOARD, EEC_PAD };

class CEvent {
public:
	CEvent(uint32 id, EEventController controller);
private:
	uint32 m_id;
	EEventController m_controller;
};

#endif //!_C_EVENT_H