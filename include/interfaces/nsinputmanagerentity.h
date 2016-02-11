#ifndef _I_INPUT_MANAGER_ENTITY_H
#define _I_INPUT_MANAGER_ENTITY_H

namespace IInputManagerEntity {
	void Register(IRegistrable *obj, EEventController controller, void(IRegistrable::*func)());
	bool Unregister(IRegistrable *obj, EEventController controller);
};

#endif //!_I_INPUT_MANAGER_ENTITY_H