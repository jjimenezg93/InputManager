#include "../include/mousecontroller.h"
#include "../include/event.h"
#include "../include/nsinputmanagercontroller.h"

#include "../lib/glfw.h"

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
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		SendEvent(1);
	}
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		SendEvent(2);
	}
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE) {
		SendEvent(3);
	}
}

void CMouseController::SendEvent(uint32 id) {
	CEvent * ev = new CEvent(EEC_MOUSE, id, m_mouseX, m_mouseY);
	IInputManagerController::AddEvent(ev);
}