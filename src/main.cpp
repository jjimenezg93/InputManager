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
	/*Image * alienImg = ResourceManager::Instance().LoadImage("data/alien.png");
	alienImg->SetMidHandle();
	CEntity entity(alienImg);*/

	Image * buttonImgDefault = ResourceManager::Instance().LoadImage("data/button_default.png");
	buttonImgDefault->SetMidHandle();
	Image * buttonImgOnHover = ResourceManager::Instance().LoadImage("data/button_onHover.png");
	buttonImgOnHover->SetMidHandle();

	CInputManager * inputManager = &CInputManager::Instance();

	assert(inputManager != nullptr);

	CControlManagerUI controlManager;

	controlManager.Init();

	CButtonUI button;
	button.Init(50, 50, buttonImgDefault, buttonImgOnHover);
	controlManager.AddControl(&button);

	CButtonUI button2;
	button2.Init(100, 50, buttonImgDefault, buttonImgOnHover);
	controlManager.AddControl(&button2);

	/*entity.Register(EEC_MOUSE, EME_LMB_PRESS);
	entity.Register(EEC_MOUSE, EME_LMB_RELEASE);
	entity.Register(EEC_MOUSE, EME_LMB_CLICK);
	entity.Register(EEC_MOUSE, EME_RMB_PRESS);
	entity.Register(EEC_KEYBOARD, EKE_SPACE);*/

	Renderer::Instance().SetBlendMode(Renderer::BlendMode::ALPHA);

	while (Screen::Instance().IsOpened() && !Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {
		Renderer::Instance().Clear();

		inputManager->Update();

		controlManager.Update();
		controlManager.Render();

		//entity.GetSprite()->Update(Screen::Instance().ElapsedTime());
		//entity.GetSprite()->Render();

		Screen::Instance().Refresh();
	}

	ResourceManager::Instance().FreeResources();
}