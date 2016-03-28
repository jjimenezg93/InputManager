#ifndef _C_ENTITY_H
#define _C_ENTITY_H

#include "ieventlistener.h"
#include "iregistrable.h"
#include "types.h"

class CControlUI;
class CEvent;
class Image;
class Sprite;
class String;

enum EEventController;

class CEntity: public IRegistrable, public IEventListener {
public:
	CEntity(const String &filename);
	CEntity(Image * const img);
	~CEntity();

	Sprite * GetSprite() const { return m_sprite; }

	virtual void Notify(const CEvent * const ev);

	virtual void ManageControlEvent(CControlUI * const sender);
	
	void ManageMouse(const CEvent * const ev);
	void ManageKeyboard(const CEvent * const ev);

	void Register(const EEventController controller, const uint32 id);
	bool MouseIsOver(const CEvent * const ev);
private:
	Sprite * m_sprite;
	bool m_mustMove;
};

#endif //!_C_ENTITY_H
