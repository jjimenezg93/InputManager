#include "../include/guirender.h"
#include "../include/image.h"
#include "../include/resourcemanager.h"
#include "../include/types.h"
#include "../include/image.h"
#include "../include/renderer.h"

CGUIRender::CGUIRender(Image * default, Image * onClick, Image * inactive) {
	m_defaultImg = default;
	m_onClickImg = onClick;
	m_inactiveImg = inactive;
}

void CGUIRender::SetDefaultImg(Image * const img) {
	if (img)
		img->SetMidHandle();
	m_defaultImg = img;
}

void CGUIRender::SetOnClickImg(Image * const img) {
	if (img)
		img->SetMidHandle();
	m_onClickImg = img;
}

void CGUIRender::SetInactiveImg(Image * const img) {
	if (img)
		img->SetMidHandle();
	m_inactiveImg = img;
}

Image * CGUIRender::GetCurrentImg(EGUICurrentState state) const {
	switch (state) {
	case EGUICS_DEFAULT:
		return m_defaultImg;
		break;
	case EGUICS_ONCLICK:
		return m_onClickImg;
		break;
	case EGUICS_INACTIVE:
		return m_inactiveImg;
		break;
	default:
		return nullptr;
		break;
	}
}

uint16 CGUIRender::GetCurrImgWidth(EGUICurrentState state) const {
	return GetCurrentImg(state)->GetWidth() * GetCurrentImg(state)->GetHFrames();
}

uint16 CGUIRender::GetCurrImgHeight(EGUICurrentState state) const {
	return GetCurrentImg(state)->GetHeight() * GetCurrentImg(state)->GetVFrames();
}

void CGUIRender::Render(EGUICurrentState state, int32 x, int32 y) {
	Renderer::Instance().DrawImage(GetCurrentImg(state), static_cast<double>(x),
	static_cast<double>(y));
}