#include "../include/keyboardcontroller.h"
#include "../include/event.h"
#include "../include/nsinputmanagercontroller.h"

#include "../lib/glfw.h"

CKeyboardController::CKeyboardController() {
	glfwInit();
}

CKeyboardController::~CKeyboardController() {
	glfwTerminate();
}

void CKeyboardController::Update() {
	glfwGetMousePos(&m_mouseX, &m_mouseY);
	if (glfwGetKey(GLFW_KEY_SPACE) == GLFW_PRESS) {
		SendEvent(0);
	}
}

void CKeyboardController::SendEvent(uint32 id) {
	CEvent * ev = new CEvent(EEC_KEYBOARD, id, m_mouseX, m_mouseY);
	IInputManagerController::AddEvent(ev);
}