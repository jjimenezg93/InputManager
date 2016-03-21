#include "../include/buttonui.h"
#include "../include/event.h"
#include "../include/image.h"
#include "../include/sliderui.h"

#include <assert.h>
#include <iostream>

uint8 CSliderUI::Init(int32 x, int32 y, int32 minVal, int32 maxVal,	Image * bar, Image * ball,
		Image * lDefault, Image * lOnClick, Image * rDefault, Image * rOnClick) {
	m_x = x;
	m_y = y;

	m_sliderRender.Init(bar, ball, lDefault, lOnClick, rDefault, rOnClick);

	m_sliderRender.GetLButton().AddEventListener(this); //id 0
	m_sliderRender.GetRButton().AddEventListener(this); //id 1

	assert(minVal != maxVal);

	m_minValue = minVal;
	m_maxValue = maxVal;

	m_ballValue = 0;
	//ball rate = ImgSize / (max - min)
	m_ballRate = static_cast<int32>(bar->GetWidth() * bar->GetHFrames())
		% static_cast<int32>(m_maxValue - m_minValue);
	m_ballRate = 1.f; // ballRate is calculated wrong, provisional
	return 0;
}

void CSliderUI::ManageControlEvent(CControlUI * sender) {
	switch (sender->GetType()) {
	case ECT_BUTTON:
		if (sender->GetId() == 0) { //left
			std::cout << "SLIDER LEFT!" << std::endl;
			if (m_ballValue - m_ballRate >= 0)
				m_ballValue -= m_ballRate;
			else
				m_ballValue = 0.f;
			NotifyListeners(this);
		} else if (sender->GetId() == 1) { //right
			std::cout << "SLIDER RIGHT!" << std::endl;
			if (m_ballValue + m_ballRate <= m_maxValue)
				m_ballValue += m_ballRate;
			else
				m_ballValue = static_cast<float>(m_maxValue);
			NotifyListeners(this);
		}
	}
}

bool CSliderUI::ManageEvent(const CEvent * const ev) {
	bool ret = false;

	ret = m_sliderRender.MangeEventButtons(ev);

	return ret;
}

void CSliderUI::Update() {
	CControlUI::Update();
}

void CSliderUI::Render() {
	int32 offset = 0;

	//lButton
	m_sliderRender.Render(ESI_LEFT_BUTTON, m_x + offset, m_y);
	offset += m_sliderRender.GetImageWidth(ESI_LEFT_BUTTON);

	//bar
	m_sliderRender.Render(ESI_BAR, m_x + offset, m_y);
	
	//ball
	int32 ballPos = static_cast<int32>((m_sliderRender.GetImageWidth(ESI_BAR)
		/ (m_maxValue - m_minValue)) * m_ballValue);
	m_sliderRender.Render(ESI_BALL, m_x + offset + ballPos, m_y);
	offset += m_sliderRender.GetImageWidth(ESI_BAR);

	//rButton
	m_sliderRender.Render(ESI_RIGHT_BUTTON, m_x + offset, m_y);
}
