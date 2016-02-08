#ifndef _C_ENTITY_H
#define _C_ENTITY_H

#ifndef UGINE_TYPES_H
#include "../../ugine/include/types.h"
#endif

#include "../interfaces/registrable.h"

class CEntity: public IRegistrable {
public:
	virtual void OnEvent();
private:
	
};

#endif //!_C_ENTITY_H
