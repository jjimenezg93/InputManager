#include "../include/inputmanager.h"
#include "../include/registrable.h"

CInputManager &CInputManager::Instance() {
	if (!m_instance)
		m_instance = new CInputManager();
	return *m_instance;
}

CInputManager::Storable::Storable(EEventController e, IRegistrable *ob, void(IRegistrable::*func)()) {
	m_eventType = e;
	m_observer = ob;
	m_action = func;
}

void CInputManager::Register(IRegistrable *obj, EEventController eventType, void(IRegistrable::*func)()) {
	m_observers.Add(new Storable(eventType, obj, func));
}