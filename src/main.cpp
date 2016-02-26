//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "../include/entity.h"
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

	entity.Register(EEC_MOUSE, 0);
	entity.Register(EEC_MOUSE, 1);
	entity.Register(EEC_MOUSE, 2);
	entity.Register(EEC_MOUSE, 3);
	entity.Register(EEC_KEYBOARD, 0);

	while (Screen::Instance().IsOpened() && !Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {
		Renderer::Instance().Clear();

		inputManager->Update();

		entity.GetSprite()->Update(Screen::Instance().ElapsedTime());
		entity.GetSprite()->Render();

		Screen::Instance().Refresh();
	}

	ResourceManager::Instance().FreeResources();
}