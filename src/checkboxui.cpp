#include "..\include\checkboxui.h"
#include "../include/event.h"
#include "../include/ieventlistener.h"
#include "../include/image.h"
#include "../include/types.h"

#include "../include/renderer.h"

uint8 CCheckBoxUI::Init() {
	return 0;
}

uint8 CCheckBoxUI::Init(int32 x, int32 y) {
	m_x = x;
	m_y = y;
	m_type = ECT_CHECKBOX;
	m_currentState = EGUICS_DEFAULT;
	return 0;
}

uint8 CCheckBoxUI::Init(int32 x, int32 y, Image * default, Image * onHover, Image * inactive) {
	Init(x, y);
	m_guirender.SetDefaultImg(default);
	m_guirender.SetOnClickImg(onHover);
	m_guirender.SetInactiveImg(inactive);
	return 0;
}

bool CCheckBoxUI::ManageEvent(const CEvent * const ev) {
	bool ret = false;
	if (m_currentState != EGUICS_INACTIVE) {
		if (ev->GetController() == EEC_MOUSE) {
			switch (ev->GetId()) {
			case EME_LMB_CLICK:
				if (MouseIsOver(ev)) {
					if (m_currentState == EGUICS_DEFAULT)
						m_currentState = EGUICS_ONCLICK;
					else if (m_currentState == EGUICS_ONCLICK)
						m_currentState = EGUICS_DEFAULT;
					std::vector<CControlUI *>::iterator itr = m_complementaries.begin();
					while (itr != m_complementaries.end()) {
						if ((*itr)->GetType() == ECT_CHECKBOX) {
							((CCheckBoxUI*)(*itr))->UpdateComplementariesState();
						}
						itr++;
					}
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

void CCheckBoxUI::Update() {
	CControlUI::Update();
}

void CCheckBoxUI::Render() {
	m_guirender.Render(m_currentState, m_x, m_y);
	CControlUI::Render();
}

void CCheckBoxUI::AddComplementary(CControlUI * compl) {
	m_complementaries.push_back(compl);
}

void CCheckBoxUI::RemoveComplementary(CControlUI * compl) {
}

void CCheckBoxUI::UpdateComplementariesState() {
	std::vector<CControlUI *>::iterator itr = m_complementaries.begin();
	while (itr != m_complementaries.end()) {
		if ((*itr)->GetState() == EGUICS_ONCLICK) {
			m_currentState = EGUICS_DEFAULT;
		}

		++itr;
	}
}

bool CCheckBoxUI::MouseIsOver(const CEvent * const ev) {
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
