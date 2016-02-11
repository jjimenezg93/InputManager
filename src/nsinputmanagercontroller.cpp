#include "../include/headers/inputmanager.h"
#include "../include/interfaces/nsinputmanagercontroller.h"

namespace IInputManagerController {
	void ManageEvent(CEvent ev) {
		CInputManager::Instance().ManageEvent(ev);
	}
}