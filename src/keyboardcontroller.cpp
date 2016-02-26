#include "../include/keyboardcontroller.h"
#include "../include/event.h"
#include "../include/nsinputmanagercontroller.h"

#include "../lib/glfw.h"

CKeyboardController::CKeyboardController() {}

uint8 CKeyboardController::Init() {
	uint8 ret = 0;
	if (!glfwInit()) {
		ret = 1;
	}
	return ret;
}

CKeyboardController::~CKeyboardController() {
	glfwTerminate();
}

void CKeyboardController::Update() {
	glfwGetMousePos(&m_mouseX, &m_mouseY);
	if (glfwGetKey(GLFW_KEY_SPACE) == GLFW_PRESS) {
		SendEvent(EKE_SPACE);
	}
}

void CKeyboardController::SendEvent(const uint32 id) {
	CEvent * ev = new CEvent(EEC_KEYBOARD, id, m_mouseX, m_mouseY);
	IInputManagerController::AddEvent(ev);
}