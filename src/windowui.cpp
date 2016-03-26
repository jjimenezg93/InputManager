#include "../include/windowui.h"

uint8 CWindowUI::Init() {
	uint8 ret = 0;
	ret = GetGUIRender().Init();
	return ret;
}

uint8 CWindowUI::Init(int32 x, int32 y) {
	uint8 ret = 0;
	ret = Init();
	m_x = x;
	m_y = y;
	return ret;
}

uint8 CWindowUI::Init(int32 x, int32 y, Image * defaultImg) {
	bool ret = 0;
	ret = Init(x, y);
	GetGUIRender().SetDefaultImg(defaultImg);
	SetType(ECT_WINDOW);
	return ret;
}