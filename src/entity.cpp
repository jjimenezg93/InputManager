#include "../include/controlui.h"
#include "../include/buttonui.h"
#include "../include/entity.h"
#include "../include/nsinputmanagerentity.h"

#include "../include/sprite.h"
#include "../include/string.h"
#include "../include/resourcemanager.h"

double genRandomF(double min, double max);

CEntity::CEntity(const String &filename) {
	m_sprite = new Sprite(ResourceManager::Instance().LoadImage(filename));
}

CEntity::CEntity(Image * const img) {
	m_sprite = new Sprite(img);
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

//void CEntity::OnClick(CControlUI * sender) {
//	switch (sender->GetType()) {
//	case ECT_BUTTON:
//		m_sprite->SetX(m_sprite->GetX() + 50);
//		break;
//	}
//}

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