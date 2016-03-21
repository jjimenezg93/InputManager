#include "../include/buttonui.h"
#include "../include/event.h"
#include "../include/ieventlistener.h"
#include "../include/image.h"
#include "../include/types.h"

#include "../include/renderer.h"

#include <iostream>

double genRandomF(double min, double max);

uint8 CButtonUI::Init() {
	m_pressed = false;
	SetType(ECT_BUTTON);
	SetCurrentState(EGUICS_DEFAULT);
	return 0;
}

uint8 CButtonUI::Init(int32 x, int32 y) {
	Init();
	m_x = x;
	m_y = y;
	return 0;
}

uint8 CButtonUI::Init(int32 x, int32 y, Image * default, Image * onHover, Image * inactive) {
	Init(x, y);
	GetGUIRender().SetDefaultImg(default);
	GetGUIRender().SetOnClickImg(onHover);
	GetGUIRender().SetInactiveImg(inactive);
	return 0;
}

void CButtonUI::SetPosition(int32 x, int32 y) {
	m_x = x;
	m_y = y;
}

bool CButtonUI::ManageEvent(const CEvent * const ev) {
	bool ret = false;
	if (GetCurrentState() != EGUICS_INACTIVE) {
		if (ev->GetController() == EEC_MOUSE) {
			switch (ev->GetId()) {
			case EME_LMB_PRESS:
				if (MouseIsOver(ev)) {
					m_pressed = true;
					SetCurrentState(EGUICS_ONCLICK);
					ret = true;
				}
				break;
			case EME_LMB_RELEASE:
				if (m_pressed && MouseIsOver(ev)) {
					m_pressed = false;
					std::cout << "CLICK!" << std::endl;
					NotifyListeners(this);
					SetCurrentState(EGUICS_DEFAULT);
					ret = true;
				}
				break;
			case EME_MOUSE_MOVED:
				if (!MouseIsOver(ev)) {
					m_pressed = false;
					SetCurrentState(EGUICS_DEFAULT);
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
	GetGUIRender().Render(GetCurrentState(), m_x, m_y);
	CControlUI::Render();
}

bool CButtonUI::MouseIsOver(const CEvent * const ev) {
	uint16 width = GetGUIRender().GetCurrImgWidth(GetCurrentState());
	uint16 height = GetGUIRender().GetCurrImgHeight(GetCurrentState());

	if (ev->GetX() >= m_x - (width / 2) && ev->GetX() <= m_x + (width / 2)
	&& ev->GetY() >= m_y - (height / 2) && ev->GetY() <= m_y + (height / 2)) {
		return true;
	} else {
		return false;
	}
}
