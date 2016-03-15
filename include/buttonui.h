#ifndef _C_BUTTON_UI_H
#define _C_BUTTON_UI_H

#include "array.h"
#include "controlui.h"
#include "guirender.h"

class SMessage;
class IEventListener;
class CGUIRender;

class CButtonUI: public CControlUI {
public:
	CButtonUI() {}

	virtual uint8 Init();
	uint8 Init(int32 x, int32 y);
	uint8 Init(int32 x, int32 y, Image * default, Image * onHover, Image * inactive = nullptr);

	CGUIRender & GetGUIRender();

	void SetState(EGUICurrentState newState);

	virtual void ManageEvent(const CEvent * const ev);

	virtual void Update();
	virtual void Render();
private:
	bool MouseIsOver(const CEvent * const ev);

	CGUIRender m_guirender;
	EGUICurrentState m_currentState;
	int32 m_x, m_y;
};

#endif //!_C_BUTTON_UI_H