#ifndef _C_INPUT_MANAGER_H
#define _C_INPUT_MANAGER_H

#include "../interfaces/registrable.h"
#include "event.h"
#include "../ugine/include/array.h"

class CInputManager {
public:
	static CInputManager &Instance();
	void Register(IRegistrable *obj, EEventController controller, uint32 eventId,
			void(IRegistrable::*func)());
	bool Unregister(IRegistrable *obj, EEventController controller, uint32 eventId);
	void ManageEvent(CEvent ev);
	void Update();
private:
	struct Storable {
		Storable(EEventController e, IRegistrable *ob, void(IRegistrable::*func)());
		EEventController m_controller;
		IRegistrable *m_observer;
		void(IRegistrable::*m_action)();
	};

	CInputManager();
	~CInputManager();

	void ManageMouse(CEvent ev);
	void ManageKeyboard(CEvent ev);

	Array<Storable *> m_observers;
	Array<CEvent> m_events;
	static CInputManager * inputmanager;
};

#endif //!_C_INPUT_MANAGER_H