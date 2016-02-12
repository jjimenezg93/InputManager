#ifndef _I_INPUT_MANAGER_ENTITY_H
#define _I_INPUT_MANAGER_ENTITY_H

namespace IInputManagerEntity {
	void Register(IRegistrable *obj, EEventController controller, uint32 id);
	//Unregister() returns true if obj was found
	bool Unregister(IRegistrable *obj, EEventController controller, uint32 id);
};

#endif //!_I_INPUT_MANAGER_ENTITY_H