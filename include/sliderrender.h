#ifndef _C_SLIDER_RENDER_H
#define _C_SLIDER_RENDER_H

#include "ieventlistener.h"
#include "types.h"
#include "guirender.h"

class Image;
class CButtonUI;

enum ESliderImg {
	ESI_BAR,
	ESI_BALL,
	ESI_LEFT_BUTTON,
	ESI_RIGHT_BUTTON
};

class CSliderRender {
public:
	CSliderRender() {}

	uint8 Init(Image * bar, Image * ball, Image * lDefault,
		Image * lOnClick, Image * rDefault, Image * rOnClick); //images always with midHandle

	void SetBarImg(Image * const img);
	void SetBallImg(Image * const img);
	void SetLButtonImg(Image * defaultImg, Image * onClickImg);
	void SetRButtonImg(Image * defaultImg, Image * onClickImg);

	Image * GetImage(ESliderImg eImg);

	int32 GetImageWidth(ESliderImg eImg);

	CButtonUI & GetLButton() { return *m_leftButton; }
	CButtonUI & GetRButton() { return *m_rightButton; }
	
	bool MangeEventButtons(const CEvent * const ev);

	void Render(ESliderImg eImg, int32 x, int32 y);
private:
	Image * m_barImg;
	Image * m_ballImg;

	CButtonUI * m_leftButton;
	CButtonUI * m_rightButton;
};

#endif //!_C_SLIDER_RENDER_H