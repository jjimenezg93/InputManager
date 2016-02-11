#include "../include/headers/inputmanager.h"
#include "../include/interfaces/registrable.h"

CInputManager * CInputManager::inputmanager = nullptr;

CInputManager &CInputManager::Instance() {
	if (!inputmanager)
		inputmanager = new CInputManager();
	return *inputmanager;
}

void CInputManager::Register(IRegistrable *obj, EEventController controller, uint32 eventId,
		void(IRegistrable::*func)()) {
	uint32 i = 0;
	bool alreadyIn = false;
	while (i < m_observers.Size()) {		//inefficient -> sort array (binary search)
		if (m_observers[i]->m_observer == obj && m_observers[i]->m_controller == controller) {
			alreadyIn = true;
		}
		i++;
	}

	if (!alreadyIn)
		m_observers.Add(new Storable(obj, controller, eventId/*, func*/));
}

/* returns false if obj was not in the list */
bool CInputManager::Unregister(IRegistrable *obj, EEventController controller, uint32 eventId) {
	uint32 i = 0;
	while (i < m_observers.Size()) { //inefficient -> sort array (binary search)
		if (m_observers[i]->m_observer == obj && m_observers[i]->m_controller == controller) {    
			m_observers.RemoveAt(i);
			return true;
		}
		i++;
	}
	return false;
}

void CInputManager::Update() {

}

void CInputManager::ManageEvent(CEvent * ev) {
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

void CInputManager::ManageMouse(CEvent * ev) {
	for (uint32 i = 0; i < m_observers.Size(); i++) {
		if (ev->GetController() == m_observers[i]->m_controller
				&& ev->GetId() == m_observers[i]->m_id) {
			m_observers[i]->m_observer->Notify(ev);
		}
	}
	//switch (ev.GetId()) {
	//case 0:
	//	//LMB press
	//case 1:
	//	//LMB release
	//}
}

void CInputManager::ManageKeyboard(CEvent * ev) {

}

CInputManager::Storable::Storable(IRegistrable *ob, EEventController e, uint32 id/*,
		void(IRegistrable::*func)()*/) {
	m_observer = ob;
	m_controller = e;
	m_id = id;
	//m_action = func;
}

CInputManager::~CInputManager() {
	for (uint32 i = 0; i < m_observers.Size(); i++) {
		delete m_observers[i];
	}
}