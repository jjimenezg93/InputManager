#include "../include/buttonui.h"
#include "../include/event.h"
#include "../include/ieventlistener.h"
#include "../include/image.h"
#include "../include/types.h"

#include "../include/renderer.h"

#include <iostream>

double genRandomF(double min, double max);

uint8 CButtonUI::Init() {
	return 0;
}

uint8 CButtonUI::Init(int32 x, int32 y) {
	m_x = x;
	m_y = y;
	m_pressed = false;
	m_type = ECT_BUTTON;
	m_currentState = EGUICS_DEFAULT;
	return 0;
}

uint8 CButtonUI::Init(int32 x, int32 y, Image * default, Image * onHover, Image * inactive) {
	Init(x, y);
	m_guirender.SetDefaultImg(default);
	m_guirender.SetOnClickImg(onHover);
	m_guirender.SetInactiveImg(inactive);
	return 0;
}

bool CButtonUI::ManageEvent(const CEvent * const ev) {
	bool ret = false;
	if (m_currentState != EGUICS_INACTIVE) {
		if (ev->GetController() == EEC_MOUSE) {
			switch (ev->GetId()) {
			case EME_LMB_PRESS:
				if (MouseIsOver(ev)) {
					m_pressed = true;
					m_currentState = EGUICS_ONCLICK;
					ret = true;
				}
				break;
			case EME_LMB_RELEASE:
				if (m_pressed && MouseIsOver(ev)) {
					//click!
					m_pressed = false;
					std::cout << "CLICK!" << std::endl;
					std::vector<IEventListener *>::iterator itr = m_listeners.begin();
					while (itr != m_listeners.end()) {
						(*itr)->OnClick(this);
						++itr;
					}
					m_currentState = EGUICS_DEFAULT;
					ret = true;
				}
				break;
			case EME_MOUSE_MOVED:
				if (!MouseIsOver(ev)) {
					m_pressed = false;
					m_currentState = EGUICS_DEFAULT;
					ret = true;
				}
				break;
			default:
				break;
			}
		}
	}
	return ret;
}

void CButtonUI::Update() {
	CControlUI::Update();
}

void CButtonUI::Render() {
	m_guirender.Render(m_currentState, m_x, m_y);
	CControlUI::Render();
}

bool CButtonUI::MouseIsOver(const CEvent * const ev) {
	Image * img = m_guirender.GetCurrentImg(m_currentState);
	uint16 width = img->GetWidth() * img->GetHFrames();
	uint16 height = img->GetHeight() * img->GetVFrames();

	if (ev->GetX() >= m_x - (width / 2) && ev->GetX() <= m_x + (width / 2)
	&& ev->GetY() >= m_y - (height / 2) && ev->GetY() <= m_y + (height / 2)) {
		return true;
	} else {
		return false;
	}
}
