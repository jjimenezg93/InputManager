#ifndef _C_INPUT_MANAGER_H
#define _C_INPUT_MANAGER_H

#include "../interfaces/registrable.h"
#include "event.h"
#include "../ugine/include/array.h"

class CInputManager {
public:
	CInputManager &Instance() {};
	void Register(IRegistrable *obj, EEventController eventType, void(IRegistrable::*func)());
	void Unregister(IRegistrable *obj, EEventController eventType);
private:
	struct Storable {
		Storable(EEventController e, IRegistrable *ob, void(IRegistrable::*func)());
		EEventController m_eventType;
		IRegistrable *m_observer;
		void(IRegistrable::*m_action)();
	};

	CInputManager();
	~CInputManager();

	Array<Storable *> m_observers;
	Array<CEvent> m_events;
	CInputManager * m_instance;
};

#endif //!_C_INPUT_MANAGER_H