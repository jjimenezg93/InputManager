#include "../include/guirender.h"
#include "../include/image.h"
#include "../include/resourcemanager.h"
#include "../include/types.h"
#include "../include/image.h"
#include "../include/renderer.h"

CGUIRender::CGUIRender(Image * default, Image * onHover, Image * inactive) {
	m_defaultImg = default;
	m_onClickImg = onHover;
	m_inactiveImg = inactive;
}

void CGUIRender::SetDefaultImg(Image * img) {
	if (img)
		img->SetMidHandle();
	m_defaultImg = img;
}

void CGUIRender::SetOnClickImg(Image * img) {
	if (img)
		img->SetMidHandle();
	m_onClickImg = img;
}

void CGUIRender::SetInactiveImg(Image * img) {
	if (img)
		img->SetMidHandle();
	m_inactiveImg = img;
}

Image * CGUIRender::GetCurrentImg(EGUICurrentState state) {
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

void CGUIRender::Render(EGUICurrentState state, int32 x, int32 y) {
	Renderer::Instance().DrawImage(GetCurrentImg(state), static_cast<double>(x),
	static_cast<double>(y));
}