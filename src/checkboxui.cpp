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
	SetType(ECT_CHECKBOX);
	SetCurrentState(EGUICS_DEFAULT);
	return 0;
}

uint8 CCheckBoxUI::Init(int32 x, int32 y, Image * default, Image * onHover, Image * inactive) {
	Init(x, y);
	GetGUIRender().SetDefaultImg(default);
	GetGUIRender().SetOnClickImg(onHover);
	GetGUIRender().SetInactiveImg(inactive);
	return 0;
}

bool CCheckBoxUI::ManageEvent(const CEvent * const ev) {
	bool ret = false;
	if (GetCurrentState() != EGUICS_INACTIVE) {
		if (ev->GetController() == EEC_MOUSE) {
			switch (ev->GetId()) {
			case EME_LMB_CLICK:
				if (MouseIsOver(ev)) {
					if (GetCurrentState() == EGUICS_DEFAULT)
						SetCurrentState(EGUICS_ONCLICK);
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
	GetGUIRender().Render(GetCurrentState(), m_x, m_y);
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
		if ((*itr)->GetCurrentState() == EGUICS_ONCLICK) {
			SetCurrentState(EGUICS_DEFAULT);
		}

		++itr;
	}
}

bool CCheckBoxUI::MouseIsOver(const CEvent * const ev) {
	uint16 width = GetGUIRender().GetCurrImgWidth(GetCurrentState());
	uint16 height = GetGUIRender().GetCurrImgHeight(GetCurrentState());

	if (ev->GetX() >= m_x - (width / 2) && ev->GetX() <= m_x + (width / 2)
		&& ev->GetY() >= m_y - (height / 2) && ev->GetY() <= m_y + (height / 2)) {
		return true;
	} else {
		return false;
	}
}
