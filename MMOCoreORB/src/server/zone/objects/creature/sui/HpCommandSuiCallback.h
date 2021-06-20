#ifndef HPCOMMANDSUICALLBACK_H_
#define HPCOMMANDSUICALLBACK_H_

#include "server/zone/objects/player/sui/SuiCallback.h"
//#include "server/zone/objects/tangible/eventperk/Jukebox.h"S949US949&oq=redd&aqs=chrome.1.69i57j0i271l3j69i60l3.1129j0j1&s
//#include "server/zone/managers/player/JukeboxSong.h"
//#include "server/zone/objects/creature/commands/sovrp/sovrpfunc.h"

class HpCommandSuiCallback : public SuiCallback {
private:
	int state;
	int pool;
	uint64 target;
	int adminLevel;

public: HpCommandSuiCallback(ZoneServer* server, uint64 _target, int _state, int _pool, int _adminLevel)
		: SuiCallback(server) {
		state = _state;
		pool = _pool;
		target = _target;
		adminLevel = _adminLevel;
	}

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
		bool cancelPressed = (eventIndex == 1);

		//if (!suiBox->isListBox() || cancelPressed)
		if (cancelPressed)
			return;

		//SuiListBox* listBox = cast<SuiListBox*>(suiBox);

		PlayerManager* playerManager = player->getZoneServer()->getPlayerManager();

		if (playerManager == nullptr)
			return;

		if (args->size() < 1)
			return;

		int index = Integer::valueOf(args->get(0).toString());


		ManagedReference<CreatureObject*> targetCreature;
		if (adminLevel > 0) {
			ManagedReference<SceneObject*> object;
			if (target != 0) {
				object = player->getZoneServer()->getObject(target, false);
			}

			if (object != nullptr) {
				if (object->isCreatureObject()) {
					targetCreature = object->asCreatureObject();
				} else {
					targetCreature = player;
				}
			} else {
				targetCreature = player;
			}
			
		} else {
			targetCreature = player;
		}

		if (state == 0) { //Initial Menu
			ManagedReference<SuiListBox*> box = new SuiListBox(player, SuiWindowType::JUKEBOX_SELECTION);
			
			if (adminLevel > 0) {
				box->setPromptTitle("HP Pool Menu, Target: " + targetCreature->getFirstName());
			} else {
				box->setPromptTitle("HP Pool Menu");
			}
			
			box->setCancelButton(true, "@cancel");
			
			if (index == -1)
				return;
			else if (index == 0) {
				// Select a Pool
				box->setCallback(new HpCommandSuiCallback(player->getZoneServer(), target, 1, 0, adminLevel));
				box->setPromptText("Select the pool you wish to modify.");
				box->addMenuItem("Modify the Health pool");
				box->addMenuItem("Modify the Action pool");
				box->addMenuItem("Modify the Will pool");
				if (targetCreature->isPlayerCreature()) {
					if (targetCreature->getPlayerObject()->getJediState() > 0) {
						box->addMenuItem("Modify the Force pool");
					}
				}
				
			} else if (index == 1) {
				// Select a pool, fill
				box->setCallback(new HpCommandSuiCallback(player->getZoneServer(), target, 2, 0, adminLevel));
				box->setPromptText("Select the pool you wish to fill.");
				box->addMenuItem("Fill the Health pool");
				box->addMenuItem("Fill the Action pool");
				box->addMenuItem("Fill the Will pool");
				if (targetCreature->isPlayerCreature()) {
					if (targetCreature->getPlayerObject()->getJediState() > 0) {
						box->addMenuItem("Fill the Force pool");
					}
				}
			} else if (index == 2) {
				// Fill all pools.
				player->sendExecuteConsoleCommand("/hp fill");
			}

			player->getPlayerObject()->addSuiBox(box);
			player->sendMessage(box->generateMessage());
		
		} else if (state == 1 || state == 2) { //Select Pool to Mod
			String pool = "health";

			if (index == -1)
				return;
			else if (index == 0) { //Health
				pool = "health";
			} else if (index == 1) { //Action
				pool = "action";
			} else if (index == 2) { //Will
				pool = "will";
			} else if (index == 3) { //Force
				pool = "force";
			}

			if (state == 1) {
				//Open a new Menu 
				ManagedReference<SuiInputBox*> hpModifyBox = new SuiInputBox(player, SuiWindowType::STRUCTURE_SET_ACCESS_FEE);
				hpModifyBox->setCallback(new HpCommandSuiCallback(player->getZoneServer(), target, 3, index, adminLevel));
				hpModifyBox->setPromptTitle("Modify " + pool + " pool"); // Access Fee
				hpModifyBox->setMaxInputSize(3);
				hpModifyBox->setPromptText("Input the amount you wish to modify the " + pool + " pool. A positive number will increase the pool, a negative number will decrease it."); 
				player->getPlayerObject()->addSuiBox(hpModifyBox);
				player->sendMessage(hpModifyBox->generateMessage());

			} else {
				//Fill it
				player->sendExecuteConsoleCommand("/hp " + pool + " fill");
			}

		} else if (state == 3) { //Modify Value 
			StringBuffer newCom;
			newCom << "/hp " << pool << " " << args->get(0).toString();
			//player->sendSystemMessage(newCom.toString()); //debug
			//player->sendSystemMessage("modifying value."); //Debug too
			player->sendExecuteConsoleCommand(newCom.toString());
		} 
		 
		
	}
};

#endif /* RPCOMBATRESPONSESUICALLBACK_H_ */
