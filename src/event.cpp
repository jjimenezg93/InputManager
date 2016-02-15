#include "../include/event.h"

CEvent::CEvent(EEventController controller, uint32 id, double x, double y) {
	m_controller = controller;
	m_id = id;
	m_x = x;
	m_y = y;
}