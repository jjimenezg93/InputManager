#include "../include/headers/inputmanager.h"
#include "../include/interfaces/registrable.h"

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
	uint32 i = 0;
	bool alreadyIn = false;
	while (i < m_observers.Size()) {		//inefficient
		if (m_observers[i]->m_observer == obj && m_observers[i]->m_eventType == eventType) {
			alreadyIn = true;
		}
		i++;
	}

	if (!alreadyIn)
		m_observers.Add(new Storable(eventType, obj, func));
}

void CInputManager::Unregister(IRegistrable *obj, EEventController eventType) {
	for (uint32 i = 0; i < m_observers.Size(); i++) {		//inefficient -> sort array (binary search)
		if (m_observers[i]->m_observer == obj && m_observers[i]->m_eventType == eventType) {
			m_observers.RemoveAt(i);
		}
	}
}

CInputManager::~CInputManager() {
	for (uint32 i = 0; i < m_observers.Size(); i++) {
		delete m_observers[i];
	}
}