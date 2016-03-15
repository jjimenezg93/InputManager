#include "../include/buttonui.h"
#include "../include/event.h"
#include "../include/image.h"
#include "../include/types.h"

#include "../include/renderer.h"

uint8 CButtonUI::Init() {
	return 0;
}

uint8 CButtonUI::Init(int32 x, int32 y) {
	m_x = x;
	m_y = y;
	m_currentState = EGUICS_DEFAULT;

	return 0;
}

uint8 CButtonUI::Init(int32 x, int32 y, Image * default,
		Image * onHover, Image * inactive) {
	Init(x, y);
	m_guirender.SetDefaultImg(default);
	m_guirender.SetOnHovertImg(onHover);
	m_guirender.SetInactiveImg(inactive);
	return 0;
}

CGUIRender & CButtonUI::GetGUIRender() {
	return m_guirender;
}

void CButtonUI::SetState(EGUICurrentState newState) {
	m_currentState = newState;
}

void CButtonUI::ManageEvent(const CEvent * const ev) {
	if (ev->GetController() == EEC_MOUSE) {
		switch (ev->GetId()) {
		case EME_MOUSE_MOVED:
			if (MouseIsOver(ev)) {
				m_currentState = EGUICS_ONHOVER;
			} else {
				m_currentState = EGUICS_DEFAULT;
			}
			break;
		case EME_LMB_CLICK:
			
		default:
			break;
		}

	}
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

void CButtonUI::Update() {
	CControlUI::Update();
}

void CButtonUI::Render() {
	m_guirender.Render(m_currentState, m_x, m_y);

	CControlUI::Render();
}
