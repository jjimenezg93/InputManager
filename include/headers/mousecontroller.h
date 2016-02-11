#ifndef _C_MOUSE_CONTROLLER_H
#define _C_MOUSE_CONTROLLER_H

#ifndef UGINE_TYPES_H
#include "../../ugine/include/types.h"
#endif

class CMouseController {
public:
	CMouseController();
	~CMouseController();
	void Update();
private:
	void SendEvent(uint32 id);

	int32 m_mouseX;
	int32 m_mouseY;
	uint8 buttons;
};

#endif //!_C_MOUSE_CONTROLLER_H