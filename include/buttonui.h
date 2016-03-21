#ifndef _C_BUTTON_UI_H
#define _C_BUTTON_UI_H

#include "controlui.h"
#include "guirender.h"
#include "types.h"

class SMessage;
class CGUIRender;

class CButtonUI: public CControlUI {
public:
	CButtonUI() {}

	virtual uint8 Init();
	uint8 Init(int32 x, int32 y);
	uint8 Init(int32 x, int32 y, Image * default, Image * onClick, Image * inactive = nullptr);

	void SetPosition(int32 x, int32 y);

	virtual bool ManageEvent(const CEvent * const ev);

	virtual void Update();
	virtual void Render();
private:
	bool MouseIsOver(const CEvent * const ev);

	int32 m_x, m_y;
	bool m_pressed;
};

#endif //!_C_BUTTON_UI_H