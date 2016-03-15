//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "../include/entity.h"
#include "../include/controlmanagerui.h"
#include "../include/buttonui.h"
#include "../include/inputmanager.h"
#include "../include/clickgesture.h"
#include "../include/mousecontroller.h"
#include "../include/keyboardcontroller.h"

#include "../include/u-gine.h"

#include <assert.h>

int main() {
	Screen::Instance().Open(800, 600, false);
	Image * alienImg = ResourceManager::Instance().LoadImage("data/alien.png");
	alienImg->SetMidHandle();
	CEntity entity(alienImg);

	CInputManager * inputManager = &CInputManager::Instance();

	assert(inputManager != nullptr);

	CControlManagerUI * controlManager = new CControlManagerUI();

	CButtonUI * button = new CButtonUI();
	controlManager->AddControl(button);

	entity.Register(EEC_MOUSE, EME_LMB_PRESS);
	entity.Register(EEC_MOUSE, EME_LMB_RELEASE);
	entity.Register(EEC_MOUSE, EME_LMB_CLICK);
	entity.Register(EEC_MOUSE, EME_RMB_PRESS);
	entity.Register(EEC_KEYBOARD, EKE_SPACE);

	while (Screen::Instance().IsOpened() && !Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {
		Renderer::Instance().Clear();

		inputManager->Update();

		entity.GetSprite()->Update(Screen::Instance().ElapsedTime());
		entity.GetSprite()->Render();

		Screen::Instance().Refresh();
	}

	ResourceManager::Instance().FreeResources();
}