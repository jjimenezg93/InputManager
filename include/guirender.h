#ifndef _C_GUI_RENDER_H
#define _C_GUI_RENDER_H

#include "types.h"

class Image;

enum EGUICurrentState {
	EGUICS_DEFAULT,
	EGUICS_ONCLICK,
	EGUICS_INACTIVE,
	EGUICS_COUNT //iterating purposes
};

class CGUIRender {
public:
	CGUIRender() {}
	CGUIRender(Image * default, Image * onClick, Image * inactive); //images always with midHandle

	// all defined in .cpp in order to allow image deleting more decoupled if
	// a method to delete 1 image is added to ResourceManager
	void SetDefaultImg(Image * const img);
	void SetOnClickImg(Image * const img);
	void SetInactiveImg(Image * const img);

	Image * GetCurrentImg(EGUICurrentState state) const;
	uint16 GetCurrImgWidth(EGUICurrentState state) const;
	uint16 GetCurrImgHeight(EGUICurrentState state) const;

	void Render(EGUICurrentState state, int32 x, int32 y);
private:
	Image * m_defaultImg;
	Image * m_onClickImg;
	Image * m_inactiveImg;
};

#endif //!_C_GUI_RENDER_H