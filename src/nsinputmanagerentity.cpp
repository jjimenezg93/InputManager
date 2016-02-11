#include "../include/headers/inputmanager.h"
#include "../include/interfaces/nsinputmanagerentity.h"
#include "../include/headers/event.h"

namespace IInputManagerEntity {
	void Register(IRegistrable *obj, EEventController controller, void(IRegistrable::*func)()) {
		CInputManager::Instance().Register(obj, controller, func);
	}

	bool Unregister(IRegistrable *obj, EEventController controller) {
		return CInputManager::Instance().Unregister(obj, controller);
	}
}