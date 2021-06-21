#ifndef BORSKILL_H_
#define BORSKILL_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/packets/chat/ChatSystemMessage.h"

//#include "templates/roleplay/RoleplayManager.h"

#include "server/db/ServerDatabase.h"

class BorSkill : public Logger {
public:
	static bool GetStringIsAttribute(string input) {
		if (input == "strength")
			return true;
		else if (input == "precision")
			return true;
		else if (input == "dexterity")
			return true;
		else if (input == "awareness")
			return true;
		else if (input == "intelligence")
			return true;
		else if (input == "charisma")
			return true;
		else if (input == "constitution")
			return true;
		else if (input == "mindfulness")
			return true;
		else
			return false;
	}

	static String GetSkillParent(String skill) {
		if (skill = "melee")
			return "strength";
		else if (skill == "intimidation")
			return "strength";
		else if (skill == "unarmed")
			return "strength";
		else if (skill == "lightsaber")
			return "strength";
		else if (skill == "ranged")
			return "precision";
		else if (skill == "mechanics")
			return "precision";
		else if (skill == "demolitions")
			return "precision";
		else if (skill == "engineering")
			return "precision";
		else if (skill == "larceny")
			return "dexterity";
		else if (skill == "stealth")
			return "dexterity";
		else if (skill == "maneuverability")
			return "dexterity";
		else if (skill == "throwing")
			return "dexterity";
		else if (skill == "investigation")
			return "awareness";
		else if (skill == "piloting")
			return "awareness";
		else if (skill == "survival")
			return "awareness";
		else if (skill == "sense")
			return "awareness";
		else if (skill == "slicing")
			return "intelligence";
		else if (skill == "computers")
			return "intelligence";
		else if (skill == "medicine")
			return "intelligence";
		else if (skill == "science")
			return "intelligence";
		else if (skill == "persuasion")
			return "charisma";
		else if (skill == "bluff")
			return "charisma";
		else if (skill == "composure")
			return "charisma";
		else if (skill == "resolve")
			return "charisma";
		else if (skill == "athletics")
			return "constitution";
		else if (skill == "lightning")
			return "constitution";
		else if (skill == "armor")
			return "constitution";
		else if (skill == "defending")
			return "constitution";
		else if (skill == "telekinesis")
			return "mindfulness";
		else if (skill == "control")
			return "mindfulness";
		else if (skill == "alter")
			return "mindfulness";
		else if (skill == "inward")
			return "mindfulness";
		else
			return "";
	}
};

#endif /*BORSKILL_H_*/