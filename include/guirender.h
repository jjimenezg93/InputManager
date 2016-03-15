#ifndef _C_GUI_RENDER_H
#define _C_GUI_RENDER_H

#include "../include/types.h"

class Image;

enum EGUICurrentState {
	EGUICS_DEFAULT,
	EGUICS_ONHOVER,
	EGUICS_INACTIVE
};

class CGUIRender {
public:
	CGUIRender() {}
	CGUIRender(Image * default, Image * onHover, Image * inactive); //images always with midHandle

	// all defined in .cpp in order to allow image deleting more decoupled if
	// a method to delete 1 image is added to ResourceManager
	virtual void SetDefaultImg(Image * img);
	virtual void SetOnHovertImg(Image * img);
	virtual void SetInactiveImg(Image * img);

	Image * GetCurrentImg(EGUICurrentState state);

	virtual void Render(EGUICurrentState state, int32 x, int32 y);
private:
	Image * m_defaultImg;
	Image * m_onHoverImg;
	Image * m_inactiveImg;
};

#endif //!_C_GUI_RENDER_H