#include "../include/headers/entity.h"

#include "../ugine/include/sprite.h"
#include "../ugine/include/string.h"
#include "../ugine/include/resourcemanager.h"

CEntity::CEntity(String &filename) {
	ResourceManager::Instance().LoadImage(filename);
}

void CEntity::Notify(CEvent * ev) {

}