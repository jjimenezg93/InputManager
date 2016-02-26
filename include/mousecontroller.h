#ifndef _C_MOUSE_CONTROLLER_H
#define _C_MOUSE_CONTROLLER_H

#include "types.h"

class CMouseController {
public:
	CMouseController();
	uint8 Init();
	~CMouseController();
	
	void Update();
private:
	void SendEvent(const uint32 id);
	
	int32 m_mouseX;
	int32 m_mouseY;
};

#endif //!_C_MOUSE_CONTROLLER_H