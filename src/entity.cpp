#include "../include/buttonui.h"
#include "../include/controlui.h"
#include "../include/checkboxgroup.h"
#include "../include/checkboxui.h"
#include "../include/entity.h"
#include "../include/event.h"
#include "../include/image.h"
#include "../include/nsinputmanagerentity.h"
#include "../include/resourcemanager.h"
#include "../include/sliderui.h"
#include "../include/sprite.h"
#include "../include/string.h"

#include <iostream>

double genRandomF(double min, double max);

CEntity::CEntity(const String &filename) {
	m_sprite = new Sprite(ResourceManager::Instance().LoadImage(filename));
}

CEntity::CEntity(Image * const img) {
	m_sprite = new Sprite(img);
}

CEntity::~CEntity() {
	delete m_sprite; //sprite's img should be cleaned in ResourceManager::FreeResources()
}

void CEntity::Notify(const CEvent * const ev) {
	switch (ev->GetController()) {
	case EEC_MOUSE:
		ManageMouse(ev);
		break;
	case EEC_KEYBOARD:
		ManageKeyboard(ev);
		break;
	default:
		break;
	}
}

void CEntity::ManageControlEvent(CControlUI * const sender) {
	uint8 alpha;
	switch (sender->GetType()) {
	case ECT_BUTTON:
		std::cout << "ENTITY received Button" << std::endl;
		m_sprite->SetColor(255, 0, 255, m_sprite->GetAlpha());
		break;
	case ECT_SLIDER:
		std::cout << "ENTITY received Slider" << std::endl;
		if (static_cast<CSliderUI *>(sender)->GetValue() >= 255)
			alpha = 255;
		else
			alpha = static_cast<uint8>(static_cast<CSliderUI *>(sender)->GetValue());
		m_sprite->SetColor(m_sprite->GetRed(), m_sprite->GetGreen(), m_sprite->GetBlue(),
			alpha);
		break;
	case ECT_CHECKBOX_GROUP:
	{
		std::cout << "ENTITY received CheckBox Group" << std::endl;
		CCheckBoxGroup * cb = reinterpret_cast<CCheckBoxGroup *>(sender);
		if (cb->GetActive()->GetId() == 0) {
			m_sprite->SetScale(1.f, 1.f);
		} else if (cb->GetActive()->GetId() == 1) {
			m_sprite->SetScale(1.5f, 1.5f);
		} else if (cb->GetActive()->GetId() == 2) {
			m_sprite->SetScale(2.f, 2.f);
		}
		break;
	}
	default:
		break;
	}
}

void CEntity::ManageMouse(const CEvent * const ev) {
	if (ev->GetId() == EME_LMB_PRESS) {
		m_mustMove = true;
		m_sprite->MoveTo(ev->GetX(), ev->GetY(), 150);
	}
	if (ev->GetId() == EME_LMB_RELEASE) {
		m_mustMove = false;
		m_sprite->MoveTo(m_sprite->GetX(), m_sprite->GetY(), 150);
	}
	if (ev->GetId() == EME_RMB_PRESS) {
		m_sprite->SetColor(static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			255);
	}
	if (ev->GetId() == EME_LMB_DRAG && MouseIsOver(ev)) {
		m_sprite->SetPosition(ev->GetX(), ev->GetY());
	}
}

void CEntity::ManageKeyboard(const CEvent * const ev) {
	if (ev->GetId() == EKE_SPACE) {
		m_sprite->SetColor(static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			255);
	}
}

void CEntity::Register(const EEventController controller, const uint32 id) {
	IInputManagerEntity::Register(this, controller, id);
}

bool CEntity::MouseIsOver(const CEvent * const ev) {
	uint16 width = m_sprite->GetImage()->GetWidth() * m_sprite->GetImage()->GetHFrames();
	uint16 height = m_sprite->GetImage()->GetHeight() * m_sprite->GetImage()->GetVFrames();

	if (ev->GetX() >= m_sprite->GetX() - (width / 2) && ev->GetX() <= m_sprite->GetX() + (width / 2)
		&& ev->GetY() >= m_sprite->GetY() - (height / 2) && ev->GetY() <= m_sprite->GetY() + (height / 2)) {
		return true;
	} else {
		return false;
	}
}
