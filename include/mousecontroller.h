#ifndef _C_MOUSE_CONTROLLER_H
#define _C_MOUSE_CONTROLLER_H

#include "types.h"

class CMouseController {
public:
	CMouseController();
	~CMouseController();
	void Update();
private:
	void SendEvent(uint32 id);

	int32 m_mouseX;
	int32 m_mouseY;
	bool m_leftBPressed;
	bool m_rightBPressed;
};

#endif //!_C_MOUSE_CONTROLLER_H