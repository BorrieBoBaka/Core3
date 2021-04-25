#ifndef BORDEV_H_
#define BORDEV_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/packets/player/PlayMusicMessage.h"
#include "server/zone/Zone.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/packets/chat/ChatSystemMessage.h"
#include "templates/customization/AssetCustomizationManagerTemplate.h"


#include "server/db/ServerDatabase.h"

class BorDev : public Logger {
public:

	static void SendHelloWorld(CreatureObject* owner) {
		owner->sendSystemMessage("Hello World!");
	}

	static void ToggleCombat(CreatureObject* creature) {
		//Locker clock(target);
		//target->setDefender(target);
		//target->setCombatState();

		ManagedReference<CreatureObject*> target;
		Zone* zone = creature->getZone();
		CreatureManager* creatureManager = zone->getCreatureManager();
		float posX = creature->getPositionX(), posY = creature->getPositionY(), posZ = creature->getPositionZ();
		uint64 parID = creature->getParentID();
		String objName = "", tempName = "vicious_squall";
		uint32 templ = tempName.hashCode();
		uint32 objTempl = objName.length() > 0 ? objName.hashCode() : 0;
		target = creatureManager->spawnCreature(templ, objTempl, posX, posZ, posY, parID);
		if (target != nullptr)
			target->asAiAgent()->activateLoad("");
		Locker clocker(creature);
		Locker targetelocker(target);
		target->setDefender(creature);
		creature->setDefender(target);
		target->getThreatMap()->addAggro(creature, 999, 0);
		target->destroyObjectFromWorld(true);
	}

	static void StopCombat(CreatureObject* creature) {
		creature->clearCombatState(true);
	}

	static void ToggleAlwaysOnAI(CreatureObject* target, CreatureObject* commander) {
		if (target->getPvpStatusBitmask() & CreatureFlag::ALWAYSON) {
			target->setPvpStatusBitmask(0);
			commander->sendSystemMessage("Target's AI is no longer always on.");
		} else {
			target->setPvpStatusBitmask(CreatureFlag::NONE);
			commander->sendSystemMessage("Target's AI is Always On now.");
		}			
	}

	static void creatureGoto(CreatureObject* creature, const uint64& target) {
		ManagedReference<SceneObject*> object = creature->getZoneServer()->getObject(target, false);
		if (object == nullptr) {
			creature->sendSystemMessage("Target required for /dm goto commands");
			throw Exception();
		}
		Locker nlocker(object, creature);
		if (object->isCreatureObject()) {
			float x = creature->getPositionX();
			float y = creature->getPositionY();
			float z = creature->getPositionZ();
			CellObject* cell = creature->getParent().get().castTo<CellObject*>();

			object->asCreatureObject()->asAiAgent()->setTargetObject(nullptr);
			object->asCreatureObject()->asAiAgent()->setFollowState(AiAgent::PATROLLING);
			object->asCreatureObject()->asAiAgent()->clearSavedPatrolPoints();
			object->asCreatureObject()->asAiAgent()->stopWaiting();
			object->asCreatureObject()->asAiAgent()->setWait(0);
			object->asCreatureObject()->asAiAgent()->setNextPosition(x, z, y, cell);
			object->asCreatureObject()->asAiAgent()->activateMovementEvent();
		} else {
			creature->sendSystemMessage("Error: Invalid Target. Must be a creature.");
			throw Exception();
		}
	}

	static void creatureFollow(CreatureObject* creature, const uint64& target) {
		ManagedReference<SceneObject*> object = creature->getZoneServer()->getObject(target, false);

		if (object == nullptr) {
			creature->sendSystemMessage("Target required for /dm follow commands");
			throw Exception();
		}
		Locker nlocker(object, creature);
		if (object->isCreatureObject()) {
			object->asCreatureObject()->asAiAgent()->setFollowObject(creature);
			object->asCreatureObject()->asAiAgent()->storeFollowObject();
			object->asCreatureObject()->asAiAgent()->setFollowState(AiAgent::FOLLOWING);
			object->asCreatureObject()->asAiAgent()->stopWaiting();
			object->asCreatureObject()->asAiAgent()->setWait(0);
			object->asCreatureObject()->asAiAgent()->activateMovementEvent();

		} else {
			creature->sendSystemMessage("Error: Invalid Target. Must be a creature.");
			throw Exception();
		}
	}


	static void creatureStay(CreatureObject* creature, const uint64& target) {
		ManagedReference<SceneObject*> object = creature->getZoneServer()->getObject(target, false);

		if (object == nullptr) {
			creature->sendSystemMessage("Target required for /dm retreat commands");
			throw Exception();
		}
		Locker nlocker(object, creature);
		if (object->isCreatureObject()) {
			object->asCreatureObject()->asAiAgent()->setOblivious();
			object->asCreatureObject()->asAiAgent()->setFollowState(AiAgent::OBLIVIOUS);
			object->asCreatureObject()->asAiAgent()->storeFollowObject();
			object->asCreatureObject()->asAiAgent()->setHomeLocation(creature->getPositionX(), creature->getPositionZ(), creature->getPositionY(),
																	 creature->getParent().get().castTo<CellObject*>());
			object->asCreatureObject()->asAiAgent()->stopWaiting();
			object->asCreatureObject()->asAiAgent()->setWait(0);
			object->asCreatureObject()->asAiAgent()->activateMovementEvent();
		} else {
			creature->sendSystemMessage("Error: Invalid Target. Must be a creature.");
			throw Exception();
		}
	}

	static void SetCreatureClient(CreatureObject* creature, const uint64& target) {
		ManagedReference<SceneObject*> object = creature->getZoneServer()->getObject(target, false);

		if (object == nullptr) {
			creature->sendSystemMessage("Target required for /dm retreat commands");
			throw Exception();
		}
		Locker nlocker(object, creature);
		if (object->isCreatureObject()) {
			object->asCreatureObject()->setClient(creature->getClient());
			creature->getClient()->setPlayer(object->asCreatureObject());
		}
	}



};

#endif 