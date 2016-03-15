#include "../include/controlui.h"
#include "../include/event.h"
#include "../include/ieventlistener.h"

void CControlUI::Update() {
	for (std::vector<CControlUI *>::iterator itr = m_controls.begin();
	itr != m_controls.end(); ++itr) {
		(*itr)->Update();
	}
}

void CControlUI::Render() {
	for (std::vector<CControlUI *>::iterator itr = m_controls.begin();
	itr != m_controls.end(); ++itr) {
		(*itr)->Render();
	}
}

void CControlUI::ManageEvent(const CEvent * const ev) {
	//method to be called from all childs after managing the event by themselves
	for (std::vector<CControlUI *>::iterator itr = m_controls.begin();
			itr != m_controls.end(); itr++) {
		(*itr)->ManageEvent(ev);
	}

	for (std::vector<IEventListener *>::iterator itr = m_listeners.begin();
			itr != m_listeners.end(); itr++) {
		(*itr)->ManageEvent(ev);
	}
}

void CControlUI::AddEventListener(IEventListener * const eventListener) {
	m_listeners.push_back(eventListener);
}

void CControlUI::RemoveEventListener(IEventListener * const eventListener) {
	std::vector<IEventListener *>::iterator itr = m_listeners.begin();
	while (itr != m_listeners.end()) {
		if ((*itr) == eventListener) {
			m_listeners.erase(itr);
		}
		++itr;
	}
}

void CControlUI::AddControl(CControlUI * const control) {
	m_controls.push_back(control);
}

void CControlUI::RemoveControl(CControlUI * const control) {
	std::vector<CControlUI *>::iterator itr = m_controls.begin();
	while (itr != m_controls.end()) {
		if ((*itr) == control) {
			m_controls.erase(itr);
		}
		++itr;
	}
}