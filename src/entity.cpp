#include "../include/entity.h"
#include "../include/nsinputmanagerentity.h"

#include "../include/sprite.h"
#include "../include/string.h"
#include "../include/resourcemanager.h"

double genRandomF(double min, double max);

CEntity::CEntity(String &filename) {
	m_sprite = new Sprite(ResourceManager::Instance().LoadImage(filename));
}

CEntity::CEntity(Image * img) {
	m_sprite = new Sprite(img);
}

void CEntity::Notify(CEvent * ev) {
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

void CEntity::ManageMouse(CEvent * ev) {
	if (ev->GetId() == 0) {
		m_mustMove = true;
		m_sprite->MoveTo(ev->GetX(), ev->GetY(), 150);
	}
	if (ev->GetId() == 1) {
		m_mustMove = false;
		m_sprite->MoveTo(m_sprite->GetX(), m_sprite->GetY(), 150);
	}
	if (ev->GetId() == 2) {
		m_sprite->SetColor(static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			255);
	}
}

void CEntity::ManageKeyboard(CEvent * ev) {
	if (ev->GetId() == 0) {
		m_sprite->SetColor(static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			static_cast<uint8>(genRandomF(0, 255)),
			255);
	}
}

void CEntity::Register(EEventController controller, uint32 id) {
	IInputManagerEntity::Register(this, controller, id);
}