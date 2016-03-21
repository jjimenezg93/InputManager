#include "../include/buttonui.h"
#include "../include/event.h"
#include "../include/image.h"
#include "../include/renderer.h"
#include "../include/sliderrender.h"

uint8 CSliderRender::Init(Image * bar, Image * ball, Image * lDefault,
		Image * lOnClick, Image * rDefault, Image * rOnClick) {
	m_barImg = bar;
	m_ballImg = ball;

	m_leftButton = new CButtonUI();
	m_leftButton->Init();
	m_leftButton->SetId(0);

	m_rightButton = new CButtonUI();
	m_rightButton->Init();
	m_rightButton->SetId(1);

	SetLButtonImg(lDefault, lOnClick);
	SetRButtonImg(rDefault, rOnClick);

	return 0;
}

void CSliderRender::SetBarImg(Image * const img) {
	m_barImg = img;
}

void CSliderRender::SetBallImg(Image * const img) {
	m_ballImg = img;
}

void CSliderRender::SetLButtonImg(Image * defaultImg, Image * onClickImg) {
	m_leftButton->GetGUIRender().SetDefaultImg(defaultImg);
	m_leftButton->GetGUIRender().SetOnClickImg(onClickImg);
}

void CSliderRender::SetRButtonImg(Image * defaultImg, Image * onClickImg) {
	m_rightButton->GetGUIRender().SetDefaultImg(defaultImg);
	m_rightButton->GetGUIRender().SetOnClickImg(onClickImg);
}

Image * CSliderRender::GetImage(ESliderImg eImg) {
	switch (eImg) {
	case ESI_BALL:
		return m_ballImg;
		break;
	case ESI_BAR:
		return m_barImg;
		break;
	case ESI_LEFT_BUTTON:
		return m_leftButton->GetGUIRender().GetCurrentImg(m_leftButton->GetCurrentState());
		break;
	case ESI_RIGHT_BUTTON:
		return m_rightButton->GetGUIRender().GetCurrentImg(m_rightButton->GetCurrentState());
		break;
	default:
		break;
	}
}

int32 CSliderRender::GetImageWidth(ESliderImg eImg) {
	Image * img = GetImage(eImg);
	return img->GetWidth() * img->GetHFrames();
}

bool CSliderRender::MangeEventButtons(const CEvent * const ev) {
	bool ret = false;

	ret = m_leftButton->ManageEvent(ev);
	if (!ret)
		ret = m_rightButton->ManageEvent(ev);

	return ret;
}

void CSliderRender::Render(ESliderImg img, int32 x, int32 y) {
	switch (img) {
	case ESI_BAR:
		Renderer::Instance().DrawImage(m_barImg, x, y);
		break;
	case ESI_BALL:
		Renderer::Instance().DrawImage(m_ballImg, x, y);
		break;
	case ESI_LEFT_BUTTON:
		m_leftButton->SetPosition(x, y);
		m_leftButton->Render();
		break;
	case ESI_RIGHT_BUTTON:
		m_rightButton->SetPosition(x, y);
		m_rightButton->Render();
		break;
	default:
		break;
	}
}