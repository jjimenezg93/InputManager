#ifndef _C_ENTITY_H
#define _C_ENTITY_H

#include "types.h"

#include "event.h"
#include "ieventlistener.h"
#include "iregistrable.h"

class Sprite;
class String;
class Image;
class CControlUI;

class CEntity: public IRegistrable, public IEventListener {
public:
	CEntity(const String &filename);
	CEntity(Image * const img);

	Sprite * GetSprite() const { return m_sprite; }

	virtual void Notify(const CEvent * const ev);

	virtual void ManageControlEvent(CControlUI * sender);
	
	void ManageMouse(const CEvent * const ev);
	void ManageKeyboard(const CEvent * const ev);

	void Register(const EEventController controller, const uint32 id);
private:
	Sprite * m_sprite;
	bool m_mustMove;
};

#endif //!_C_ENTITY_H
