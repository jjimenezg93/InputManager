#ifndef _S_MESSAGES_UI_H
#define _S_MESSAGES_UI_H

enum EMessageType { EMT_BASE_MESSAGE, EMT_POINTER_MOVE };

class Sprite;

struct SMessage {
	SMessage() { m_type = EMT_BASE_MESSAGE; }
	virtual ~SMessage() {}

	EMessageType m_type;
};

struct SClickMessage {
	SClickMessage(float x, float y) {
		m_x = x;
		m_y = y;
	}
	float m_x, m_y;
};

#endif //!_S_MESSAGES_UI_H