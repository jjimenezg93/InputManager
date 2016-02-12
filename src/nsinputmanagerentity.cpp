#include "../include/inputmanager.h"
#include "../include/nsinputmanagerentity.h"
#include "../include/event.h"

namespace IInputManagerEntity {
	void Register(IRegistrable *obj, EEventController controller, uint32 id) {
		CInputManager::Instance().Register(obj, controller, id);
	}

	bool Unregister(IRegistrable *obj, EEventController controller, uint32 id) {
		return CInputManager::Instance().Unregister(obj, controller, id);
	}
}