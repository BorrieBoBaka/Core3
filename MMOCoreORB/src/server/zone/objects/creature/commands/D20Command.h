/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef D20COMMAND_H_
#define D20COMMAND_H_


#include "server/zone/borrie/BorrieRPG.h"
#include "server/zone/borrie/BorDice.h"
#include "server/zone/borrie/BorSkill.h"

class D20Command : public QueueCommand {

public:
	D20Command(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if (!creature->isPlayerCreature())
			return GENERALERROR;

		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		if (ghost == nullptr)
			return GENERALERROR;

		int adminLevelCheck = ghost->getAdminLevel();

		StringTokenizer args(arguments.toString());

		try {
			String command, Result, secondCommand;
			if (args.hasMoreTokens()) {
				args.getStringToken(command);
				command = command.toLowerCase();

				ManagedReference<SceneObject*> object;			  // The Target Object
				ManagedReference<CreatureObject*> targetCreature; // The Target Object as a Creature

				if (target != 0) {
					object = server->getZoneServer()->getObject(target, false);
					if (object->isCreatureObject())
						targetCreature = object->asCreatureObject();
					else
						targetCreature = creature;
				} else
					targetCreature = creature;

				if (command == "help") {
					HelpDisplay(creature);
				} else if (BorSkill::GetStringIsSkill(command)) {
					BorrieRPG::BroadcastRoll(creature, BorDice::RollSkill(creature, command));
				} else if (BorDice::GetCommandIsDie(command)) {
					if (args.hasMoreTokens()) {
						args.getStringToken(secondCommand);
						Result = BorDice::RollRPDie(creature, command, Integer::valueOf(secondCommand));
					} else
						Result = BorDice::RollRPDie(creature, command);
					if (Result == "fail") {
						creature->sendSystemMessage("ERROR: Attempted to roll die for " + command + " and failed.");
					} else
						BorrieRPG::BroadcastRoll(creature, Result);
				} else {
					throw Exception();
				}
			}
		} catch (Exception& e) {
			creature->sendSystemMessage("Invalid arguments for D20 command. Help: /d20 help");
		}

		return SUCCESS;
	}

	void HelpDisplay(CreatureObject* creature) const {
		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();
		StringBuffer text;
		text << "-D20 COMMAND-------------------" << endl;

		ManagedReference<SuiMessageBox*> box = new SuiMessageBox(creature, SuiWindowType::NONE);
		box->setPromptTitle("D20 COMMAND HELP");
		box->setPromptText(text.toString());
		ghost->addSuiBox(box);
		creature->sendMessage(box->generateMessage());
	}

};

#endif 
