#ifndef BORDM_H_
#define BORDM_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/packets/chat/ChatSystemMessage.h"

//#include "templates/roleplay/RoleplayManager.h"

class SovDM : public Logger {
public:
	static void sendMessage(CreatureObject* creature, const uint64& target, int adminLevelCheck, String arguments) {
		ManagedReference<SceneObject*> object = creature->getZoneServer()->getObject(target, false);
		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		if (object == nullptr) {
			creature->sendSystemMessage("Target required for /dm msg commands");
			return;
		}

		if (object->asCreatureObject()->getPlayerObject() == nullptr) {
			creature->sendSystemMessage("Target must be a player.");
			return;
		}

		if (adminLevelCheck < 1) {
			creature->sendSystemMessage("You don't have permission to do that.");
			return;
		}

		object->asCreatureObject()->sendSystemMessage(arguments.subString(4, arguments.length()));
		creature->sendSystemMessage("[" + object->asCreatureObject()->getFirstName() + "] recieved: " + arguments.subString(4, arguments.length()));
	}


	/*
	static void SetSecretDM(CreatureObject* creature, CreatureObject* target) {
		String secretDMState = target->getLocalData("secretdm");
		if (secretDMState == "0") {
			SovSync::SetSyncVar(target, "secretdm", "1");
			creature->sendSystemMessage("Target is now a secret DM.");
		} else {
			SovSync::SetSyncVar(target, "secretdm", "0");
			creature->sendSystemMessage("Target is no longer a secret DM.");
		}
	}

	static void ModifyAttribute(CreatureObject* dm, const uint64& target, String attribute, int amount) {
		ManagedReference<SceneObject*> object = dm->getZoneServer()->getObject(target, false);
		if (object == nullptr) {
			dm->sendSystemMessage("Target required for /dm msg commands");
			return;
		}

		if (object->asCreatureObject()->getPlayerObject() == nullptr) {
			dm->sendSystemMessage("Target must be a player.");
			return;
		}
		String previous = object->asCreatureObject()->getLocalData(attribute);
		SovSync::AddSyncVar(object->asCreatureObject(), attribute, amount);

		dm->sendSystemMessage("Changed " + object->asCreatureObject()->getFirstName() + "'s '" + attribute + "' variable from " + previous + " to " +
							  String::valueOf((Integer::valueOf(previous) + amount)));
	} */
};

#endif /*BORDM_H_*/