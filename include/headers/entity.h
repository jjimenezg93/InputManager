#ifndef _C_ENTITY_H
#define _C_ENTITY_H

#ifndef UGINE_TYPES_H
#include "../../ugine/include/types.h"
#endif

#include "../interfaces/registrable.h"

class Sprite;
class String;

class CEntity: public IRegistrable {
public:
	CEntity(String &filename);

	virtual void Notify(CEvent * ev);
private:
	
	Sprite * m_sprite;
};

#endif //!_C_ENTITY_H
