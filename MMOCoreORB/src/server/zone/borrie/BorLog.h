#ifndef BORLOG_H_
#define BORLOG_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/packets/chat/ChatSystemMessage.h"

//#include "templates/roleplay/RoleplayManager.h"

#include "server/db/ServerDatabase.h"

class BorLog : public Logger {
public:
	static void LogDM(CreatureObject* dm, const uint64& target, String command, String message) {
		string targetName = GetTargetName(target);

		StringBuffer text;

		text << "[DM " << dm->getFirstName() << " used '" << command << "' on target " << targetName << "]: " << message;

		File* file = new File("custom_scripts/borlogs/DMLog.lua");
		FileWriter* writer = new FileWriter(file, true); // true for appending new lines

		writer->writeLine(text.toString());

		writer->close();
		delete file;
		delete writer;
	}

	String GetTargetName(const uint64& target) {
		ManagedReference<SceneObject*> object = creature->getZoneServer()->getObject(target, false);
		if (object == nullptr) {
			return "(NULL)";
		}

		if (object->isCreatureObject()) {
			if (object->asCreatureObject()->getPlayerObject() == nullptr) {
				return "Object " + object->asCreatureObject()->getFirstName();
			} else {
				return "Player " + object->asCreatureObject()->getFirstName();
			}
		} else {
			return "Object " + object->objectName();
		}
	}
};

#endif /*BORLOG_H_*/