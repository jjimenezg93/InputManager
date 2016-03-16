//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "../include/entity.h"
#include "../include/buttonui.h"
#include "../include/clickgesture.h"
#include "../include/checkboxui.h"
#include "../include/controlmanagerui.h"
#include "../include/inputmanager.h"
#include "../include/mousecontroller.h"
#include "../include/keyboardcontroller.h"

#include "../include/u-gine.h"

#include <assert.h>

int main() {
	Screen::Instance().Open(800, 600, false);
	Image * alienImg = ResourceManager::Instance().LoadImage("data/alien.png");
	alienImg->SetMidHandle();
	CEntity entity(alienImg);

	Image * buttonImgDefault = ResourceManager::Instance().LoadImage("data/button_default.png");
	buttonImgDefault->SetMidHandle();
	Image * buttonImgOnClick = ResourceManager::Instance().LoadImage("data/button_onclick.png");
	buttonImgOnClick->SetMidHandle();
	Image * buttonImgInactive = ResourceManager::Instance().LoadImage("data/button_inactive.png");
	buttonImgInactive->SetMidHandle();

	Image * checkboxImgDefault = ResourceManager::Instance().LoadImage(
	"data/checkbox_disabled.png");
	checkboxImgDefault->SetMidHandle();
	Image * checkboxImgOnClick = ResourceManager::Instance().LoadImage(
	"data/checkbox_enabled.png");
	checkboxImgOnClick->SetMidHandle();

	CInputManager * inputManager = &CInputManager::Instance();

	assert(inputManager != nullptr);

	CControlManagerUI controlManager;

	controlManager.Init();

	CButtonUI button;
	button.Init(50, 50, buttonImgDefault, buttonImgOnClick, buttonImgInactive);
	controlManager.AddControl(&button);
	button.SetState(EGUICS_INACTIVE);

	CButtonUI button2;
	button2.Init(300, 250, buttonImgDefault, buttonImgOnClick, buttonImgInactive);
	controlManager.AddControl(&button2);

	CCheckBoxUI checkbox;
	checkbox.Init(400, 100, checkboxImgDefault, checkboxImgOnClick);
	controlManager.AddControl(&checkbox);

	CCheckBoxUI checkbox2;
	checkbox2.Init(560, 100, checkboxImgDefault, checkboxImgOnClick);
	controlManager.AddControl(&checkbox2);

	checkbox.AddComplementary(&checkbox2);
	checkbox2.AddComplementary(&checkbox);

	//button2.AddEventListener(&entity);
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