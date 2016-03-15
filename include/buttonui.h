#ifndef _C_BUTTON_UI_H
#define _C_BUTTON_UI_H

#include "array.h"
#include "controlui.h"

class SMessage;
class IEventListener;

class CButtonUI: public CControlUI {
public:
	virtual uint8 Init();
	virtual void Update();
	virtual void Render();
private:

};

#endif //!_C_BUTTON_UI_H