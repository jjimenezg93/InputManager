#include "../include/headers/inputmanager.h"
#include "../include/headers/entity.h"

#include "../ugine/include/u-gine.h"

int main() {
	Screen::Instance().Open(800, 600, false);
	CEntity * entity = new CEntity(String("data/alien.png"));

	while (Screen::Instance().IsOpened() && !Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {
		Renderer::Instance().Clear();

		Screen::Instance().Refresh();
	}

	delete entity;

	ResourceManager::Instance().FreeResources();
}