#include "../include/headers/mousecontroller.h"
#include "../include/headers/event.h"
#include "../include/interfaces/nsinputmanagercontroller.h"
#include "../ugine/lib/glfw.h"

CMouseController::CMouseController() {
	glfwInit();
}

CMouseController::~CMouseController() {
	glfwTerminate();
}

void CMouseController::Update() {
	glfwGetMousePos(&m_mouseX, &m_mouseY);
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		SendEvent(0);
	}
}

void CMouseController::SendEvent(uint32 id) {
	CEvent ev(EEC_MOUSE, id, m_mouseX, m_mouseY);
	IInputManagerController::ManageEvent(ev);
}