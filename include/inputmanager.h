#ifndef _C_INPUT_MANAGER_H
#define _C_INPUT_MANAGER_H

#include "iregistrable.h"
#include "event.h"
#include "array.h"

class IGesture;
class CMouseController;
class CKeyboardController;

class CInputManager {
public:
	static CInputManager &Instance();
	void Register(IRegistrable * const obj, const EEventController controller,
			const uint32 eventId);
	bool Unregister(IRegistrable * const obj, const EEventController controller,
			const uint32 eventId);
	void ProcessGestures();
	void ManageEvents();
	void AddEvent(CEvent * const ev);
	void Update();
private:
	struct IMObserver {
		IMObserver(IRegistrable * const ob, const EEventController e, const uint32 id);
		EEventController m_controller;
		uint32 m_id;
		IRegistrable * m_observer;
	};

	CInputManager();
	uint8 Init();
	~CInputManager();

	static CInputManager * inputmanager;

	Array<IMObserver *> m_observers;
	Array<CEvent *> m_events;
	Array<IGesture *> m_gestureManagers;

	CMouseController * m_mouseController;
	CKeyboardController * m_keyboardController;
};

#endif //!_C_INPUT_MANAGER_H