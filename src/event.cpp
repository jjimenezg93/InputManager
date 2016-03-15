#include "../include/event.h"

CEvent::CEvent(EEventController controller, uint32 id, int32 x, int32 y) {
	m_controller = controller;
	m_id = id;
	m_x = x;
	m_y = y;
}