#include "../include/inputmanager.h"
#include "../include/nsinputmanagercontroller.h"

namespace IInputManagerController {
	void AddEvent(CEvent * ev) {
		CInputManager::Instance().AddEvent(ev);
	}
}