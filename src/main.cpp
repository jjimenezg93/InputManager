//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "../include/entity.h"
#include "../include/buttonui.h"
#include "../include/clickgesture.h"
#include "../include/checkboxui.h"
#include "../include/checkboxgroup.h"
#include "../include/controlmanagerui.h"
#include "../include/inputmanager.h"
#include "../include/mousecontroller.h"
#include "../include/keyboardcontroller.h"
#include "../include/sliderui.h"
#include "../include/windowui.h"

#include "../include/u-gine.h"

#include <assert.h>

int main() {
	Screen::Instance().Open(800, 600, false);

	//Entity
	Image * alienImg = ResourceManager::Instance().LoadImage("data/alien.png");
	alienImg->SetMidHandle();
	CEntity entity(alienImg);
	entity.GetSprite()->SetPosition(350, 340);

	//Windows
	Image * backgroundImg = ResourceManager::Instance().LoadImage("data/background.jpg");
	Image * windowImg = ResourceManager::Instance().LoadImage("data/window4.png");

	//button Imgs
	Image * buttonImgDefault = ResourceManager::Instance().LoadImage("data/button_default.png");
	buttonImgDefault->SetMidHandle();
	Image * buttonImgOnClick = ResourceManager::Instance().LoadImage("data/button_onclick.png");
	buttonImgOnClick->SetMidHandle();
	Image * buttonImgInactive = ResourceManager::Instance().LoadImage("data/button_inactive.png");
	buttonImgInactive->SetMidHandle();

	//checkbox Imgs
	Image * checkboxImgDefault = ResourceManager::Instance().LoadImage(
	"data/checkbox_disabled.png");
	checkboxImgDefault->SetMidHandle();
	Image * checkboxImgOnClick = ResourceManager::Instance().LoadImage(
	"data/checkbox_enabled.png");
	checkboxImgOnClick->SetMidHandle();

	//slider Imgs
	Image * sliderBallImg = ResourceManager::Instance().LoadImage("data/slider_ball.png");	
	sliderBallImg->SetHandle(0,
		static_cast<float>(sliderBallImg->GetHeight() * sliderBallImg->GetVFrames()));
	
	Image * sliderBarImg = ResourceManager::Instance().LoadImage("data/slider_bar.png");
	sliderBarImg->SetHandle(0,
		static_cast<float>(sliderBarImg->GetHeight() * sliderBarImg->GetVFrames()));
	
	Image * sliderLeftDefaultImg = ResourceManager::Instance().LoadImage(
		"data/slider_left_default.png");
	sliderLeftDefaultImg->SetMidHandle();
	
	Image * sliderRightDefaultImg = ResourceManager::Instance().LoadImage(
		"data/slider_right_default.png");
	sliderRightDefaultImg->SetMidHandle();
	
	Image * sliderLeftOnClickImg = ResourceManager::Instance().LoadImage(
		"data/slider_left_onclick.png");
	sliderLeftOnClickImg->SetMidHandle();
	
	Image * sliderRightOnClickImg = ResourceManager::Instance().LoadImage(
		"data/slider_right_onclick.png");
	sliderRightOnClickImg->SetMidHandle();

	//Input & Control managers
	CInputManager * inputManager = &CInputManager::Instance();

	assert(inputManager != nullptr);

	CControlManagerUI controlManager;

	controlManager.Init();

	String str;
	//Controls
	CWindowUI background;
	background.Init(0, 0, backgroundImg);
	background.SetId(0);
	controlManager.AddControl(&background);

	CWindowUI windowSlider;
	windowSlider.Init(100, 0, windowImg);
	windowSlider.SetId(1);
	controlManager.AddControl(&windowSlider);

	CButtonUI button;
	button.Init(350, 80, buttonImgDefault, buttonImgOnClick, buttonImgInactive);
	button.SetId(0);
	str = "Inactive";
	button.SetText(str);
	controlManager.AddControl(&button);
	button.SetCurrentState(EGUICS_INACTIVE);

	CButtonUI button2;
	button2.Init(350, 140, buttonImgDefault, buttonImgOnClick, buttonImgInactive);
	button2.SetId(1);
	str = "Click";
	button2.SetText(str);
	controlManager.AddControl(&button2);

	CSliderUI slider;
	slider.Init(200, 400, 0, 10, sliderBarImg, sliderBallImg, sliderLeftDefaultImg,
		sliderLeftOnClickImg, sliderRightDefaultImg, sliderRightOnClickImg);
	slider.SetId(0);
	controlManager.AddControl(&slider);

	CCheckBoxUI checkbox;
	checkbox.Init(300, 220, checkboxImgDefault, checkboxImgOnClick);
	checkbox.SetId(0);

	CCheckBoxUI checkbox2;
	checkbox2.Init(340, 220, checkboxImgDefault, checkboxImgOnClick);
	checkbox2.SetId(1);

	CCheckBoxUI checkbox3;
	checkbox3.Init(380, 220, checkboxImgDefault, checkboxImgOnClick);
	checkbox3.SetId(2);

	CCheckBoxGroup cbGroup;
	cbGroup.Init();
	cbGroup.AddControl(&checkbox);
	cbGroup.AddControl(&checkbox2);
	cbGroup.AddControl(&checkbox3);
	controlManager.AddControl(&cbGroup);

	checkbox.SetCurrentState(EGUICS_ONCLICK);

	button2.AddEventListener(&entity);
	slider.AddEventListener(&entity);
	entity.GetSprite()->SetColor(entity.GetSprite()->GetRed(), entity.GetSprite()->GetGreen(),
		entity.GetSprite()->GetBlue(), 0);
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

		entity.GetSprite()->Update(Screen::Instance().ElapsedTime());
		entity.GetSprite()->Render();

		Screen::Instance().Refresh();
	}

	ResourceManager::Instance().FreeResources();
}