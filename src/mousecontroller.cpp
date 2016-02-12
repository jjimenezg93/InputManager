#include "../include/mousecontroller.h"
#include "../include/event.h"
#include "../include/nsinputmanagercontroller.h"

#include "../lib/glfw.h"

CMouseController::CMouseController() {
	glfwInit();
	m_leftBPressed = m_rightBPressed = false;
}

CMouseController::~CMouseController() {
	glfwTerminate();
}

void CMouseController::Update() {
	glfwGetMousePos(&m_mouseX, &m_mouseY);
	if (m_leftBPressed == false && glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		m_leftBPressed = true;
		SendEvent(0);
	}
	if (m_leftBPressed == true && glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		m_leftBPressed = false;
		SendEvent(1);
	}
	if (m_rightBPressed == false && glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		m_rightBPressed = true;
		SendEvent(2);
	}
	if (m_rightBPressed == true && glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE) {
		m_rightBPressed = false;
		SendEvent(3);
	}
}

void CMouseController::SendEvent(uint32 id) {
	CEvent * ev = new CEvent(EEC_MOUSE, id, m_mouseX, m_mouseY);
	IInputManagerController::AddEvent(ev);
}