//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "../include/entity.h"
#include "../include/inputmanager.h"
#include "../include/mousecontroller.h"
#include "../include/keyboardcontroller.h"

#include "../include/u-gine.h"

int main() {
	Screen::Instance().Open(800, 600, false);
	Image * alienImg = ResourceManager::Instance().LoadImage("data/alien.png");
	alienImg->SetMidHandle();
	CEntity * entity = new CEntity(alienImg);
	CMouseController mouseController;
	CKeyboardController keyboardController;

	entity->Register(EEC_MOUSE, 0);
	entity->Register(EEC_MOUSE, 1);
	entity->Register(EEC_MOUSE, 2);
	entity->Register(EEC_MOUSE, 3);
	entity->Register(EEC_KEYBOARD, 0);

	while (Screen::Instance().IsOpened() && !Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {
		Renderer::Instance().Clear();

		mouseController.Update();
		keyboardController.Update();

		CInputManager::Instance().ManageEvents();

		entity->GetSprite()->Update(Screen::Instance().ElapsedTime());
		entity->GetSprite()->Render();

		Screen::Instance().Refresh();
	}

	delete entity;

	ResourceManager::Instance().FreeResources();
}