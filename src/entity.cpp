#include "../include/entity.h"
#include "../include/nsinputmanagerentity.h"

#include "../include/sprite.h"
#include "../include/string.h"
#include "../include/resourcemanager.h"

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
		m_sprite->MoveTo(ev->GetX(), ev->GetY(), 50);
	}
}

void CEntity::ManageKeyboard(CEvent * ev) {

}

void CEntity::Register(EEventController controller, uint32 id) {
	IInputManagerEntity::Register(this, controller, id);
}