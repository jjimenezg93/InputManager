#include "../include/headers/event.h"

CEvent::CEvent(EEventController controller, uint32 id, double x = 0, double y = 0) {
	m_controller = controller;
	m_id = id;
	m_x = x;
	m_y = y;
}