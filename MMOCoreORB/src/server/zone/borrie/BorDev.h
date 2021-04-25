#ifndef BORDEV_H_
#define BORDEV_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/packets/chat/ChatSystemMessage.h"


#include "server/db/ServerDatabase.h"

class BorDev : public Logger {
public:

	static void SendHelloWorld(CreatureObject* owner) {
		owner->sendSystemMessage("Hello World!");
	}

};

#endif 