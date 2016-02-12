#include "../include/inputmanager.h"
#include "../include/registrable.h"

CInputManager * CInputManager::inputmanager = nullptr;

CInputManager &CInputManager::Instance() {
	if (!inputmanager)
		inputmanager = new CInputManager();
	return *inputmanager;
}

CInputManager::CInputManager() {}

void CInputManager::Register(IRegistrable *obj, EEventController controller, uint32 eventId) {
	uint32 i = 0;
	bool alreadyIn = false;
	while (i < m_observers.Size()) {		//inefficient -> sort array (binary search)
		if (m_observers[i]->m_observer == obj && m_observers[i]->m_controller == controller) {
			alreadyIn = true;
		}
		i++;
	}

	if (!alreadyIn)
		m_observers.Add(new Storable(obj, controller, eventId));
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

void CInputManager::ManageEvents() {
	for (uint32 i = 0; i < m_events.Size(); i++) {
		for (uint32 j = 0; j < m_observers.Size(); j++) {
			if (m_events[i]->GetController() == m_observers[j]->m_controller
					&& m_events[i]->GetId() == m_observers[j]->m_id) {
				m_observers[j]->m_observer->Notify(m_events[i]);
				//(m_observers[i].*m_action)(); //syntaxis to call member function from pointer 
			}
		}
		delete m_events[i];
		m_events.RemoveAt(i);
	}
}

void CInputManager::AddEvent(CEvent * ev) {
	m_events.Add(ev);
}

CInputManager::Storable::Storable(IRegistrable *ob, EEventController e, uint32 id) {
	m_observer = ob;
	m_controller = e;
	m_id = id;
}

CInputManager::~CInputManager() {
	for (uint32 i = 0; i < m_observers.Size(); i++) {
		delete m_observers[i];
	}
}