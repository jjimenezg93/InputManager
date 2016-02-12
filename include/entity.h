#ifndef _C_ENTITY_H
#define _C_ENTITY_H

#include "types.h"

#include "event.h"
#include "registrable.h"

class Sprite;
class String;
class Image;

class CEntity: public IRegistrable {
public:
	CEntity(String &filename);
	CEntity(Image * img);

	Sprite * GetSprite() { return m_sprite; }

	virtual void Notify(CEvent * ev);
	
	void ManageMouse(CEvent * ev);
	void ManageKeyboard(CEvent * ev);

	void Register(EEventController controller, uint32 id);
private:
	
	Sprite * m_sprite;
};

#endif //!_C_ENTITY_H
