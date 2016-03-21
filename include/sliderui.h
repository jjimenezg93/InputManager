#ifndef _C_SLIDER_UI_H
#define _C_SLIDER_UI_H

#include "controlui.h"
#include "ieventlistener.h"
#include "sliderrender.h"
#include "types.h"

class SMessage;
class CSliderRender;

class CSliderUI: public CControlUI, public IEventListener {
public:
	CSliderUI() {}

	uint8 Init() { return 0; }
	uint8 Init(int32 x, int32 y, int32 minVal, int32 maxVal, Image * bar, Image * ball,
		Image * lDefault, Image * lOnClick, Image * rDefault, Image * rOnClick);

	virtual void ManageControlEvent(CControlUI * sender);

	virtual bool ManageEvent(const CEvent * const ev);

	virtual void Update();
	virtual void Render();
private:
	int32 m_x, m_y;
	float m_ballValue, m_ballRate;
	uint32 m_minValue, m_maxValue;
	CSliderRender m_sliderRender;
};

#endif //!_C_SLIDER_UI_H