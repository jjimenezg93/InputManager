#ifndef _C_INPUT_MANAGER_H
#define _C_INPUT_MANAGER_H

#include "registrable.h"
#include "event.h"
#include "array.h"

class CInputManager {
public:
	static CInputManager &Instance();
	void Register(IRegistrable *obj, EEventController controller, uint32 eventId);
	bool Unregister(IRegistrable *obj, EEventController controller, uint32 eventId);
	void ManageEvents();
	void AddEvent(CEvent * ev);
	void Update();
private:
	struct Storable {
		Storable(IRegistrable *ob, EEventController e, uint32 id);
		EEventController m_controller;
		uint32 m_id;
		IRegistrable *m_observer;
	};

	CInputManager();
	~CInputManager();

	Array<Storable *> m_observers;
	Array<CEvent *> m_events;
	static CInputManager * inputmanager;
};

#endif //!_C_INPUT_MANAGER_H