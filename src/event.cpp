#include "../include/headers/event.h"

CEvent::CEvent(uint32 id, EEventController controller) {
	m_id = id;
	m_controller = controller;
}