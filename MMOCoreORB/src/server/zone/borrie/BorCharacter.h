#ifndef BORCHARACTER_H_
#define BORCHARACTER_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/packets/chat/ChatSystemMessage.h"

//#include "templates/roleplay/RoleplayManager.h"

#include "server/zone/borrie/BorrieRPG.h"
#include "server/zone/borrie/BorSkill.h"

#include "server/db/ServerDatabase.h"

class BorCharacter : public Logger {
public:
	static bool GetStringIsPool(String pool) {
		if (pool == "health")
			return true;
		else if (pool == "action")
			return true;
		else if (pool == "force")
			return true;
		else if (pool == "will")
			return true;
		else
			return false;
	}

	static void ModPool(CreatureObject* creature, String pool, int mod) {
		int max = 0;
		int current = 0;
		int finalPool = 0;
		int poolID = GetHAMFromPool(pool);
		if (poolID == -1) {
			creature->sendSystemMessage("ERROR: You've not specified an actual pool. Valid pools are: health, action, will, and force.");
			return;
		}
		if (poolID > 8) { //If above 8, its a force pool.
			if (creature->isPlayerCreature()) {
				max = creature->getPlayerObject()->getForcePowerMax();
				current = creature->getPlayerObject()->getForcePower();
				if (current + mod > max)
					finalPool = 0;
				else if (current + mod > max)
					finalPool = max;
				else
					finalPool = current + mod;

				creature->getPlayerObject()->setForcePower(finalPool, true);
				BorrieRPG::BroadcastMessage(creature, creature->getFirstName() + "'s " + pool + " pool has changed by " + String::valueOf(mod) + "! (Was: " + String::valueOf(current) + ")");
			} 
		} else {
			max = creature->getMaxHAM(poolID);
			current = creature->getHAM(poolID);
			if (current + mod > max)
				finalPool = 0;
			else if (current + mod > max)
				finalPool = max;
			else
				finalPool = current + mod;

			creature->setHAM(poolID, finalPool, true);	
			BorrieRPG::BroadcastMessage(creature, creature->getFirstName() + "'s " + pool + " pool has changed by " + String::valueOf(mod) + "! (Was: " + String::valueOf(current) + ")");
			if (poolID == 0 && finalPool == 0) {
				BorrieRPG::BroadcastMessage(creature, creature->getFirstName() + " has run out of health!");
			}
		}			
	}

	static void FillPool(CreatureObject* creature, String pool, bool suppressMessage = false) {
		int max = 0;
		int current = 0;
		int poolID = GetHAMFromPool(pool);
		if (poolID != -1) {
			if (poolID > 8) { //Force Power
				max = creature->getPlayerObject()->getForcePowerMax();
				current = creature->getPlayerObject()->getForcePower();
				creature->getPlayerObject()->setForcePower(max, true);
				if (!suppressMessage)
					BorrieRPG::BroadcastMessage(creature, creature->getFirstName() + "'s " + pool + " pool has been filled! (Was: " + String::valueOf(current) + ")");
			} else {
				max = creature->getMaxHAM(poolID);
				current = creature->getHAM(poolID);
				creature->setHAM(poolID, max, true);	
				if (!suppressMessage)
					BorrieRPG::BroadcastMessage(creature, creature->getFirstName() + "'s " + pool + " pool has been filled! (Was: " + String::valueOf(current) + ")");
			}
		} else {
			creature->sendSystemMessage("ERROR: You've not specified an actual pool. Valid pools are: health, action, will, and force.");
		}
	}

	static void FillAllPools(CreatureObject* creature,  bool suppressMessage = false) {
		int lastHealth = creature->getHAM(0);
		int lastAction = creature->getHAM(3);
		int lastWill = creature->getHAM(6);
		int lastForce = 0;
		if (creature->isPlayerCreature()) {
			lastForce = creature->getPlayerObject()->getForcePower(); 
		}

		FillPool(creature, "health", true);
		FillPool(creature, "action", true);
		FillPool(creature, "will", true);
		FillPool(creature, "force", true);

		String report = creature->getFirstName() + " has fully rested, filling all of their pools.";
		report += " (Was H:" + String::valueOf(lastHealth);
		report += ", A:" + String::valueOf(lastAction);
		report += ", W:" + String::valueOf(lastWill);

		if (creature->isPlayerCreature()) {
			if (creature->getPlayerObject()->getForcePowerMax() > 0) {
				report += ", F:" + String::valueOf(lastForce) + ")";
			} else {
				report += ")";
			}
		} else {
			report += ")";
		}

		

		if (!suppressMessage)
			BorrieRPG::BroadcastMessage(creature, report);
	}

	static int GetHAMFromPool(String pool) {
		if (pool == "health")
			return 0;
		else if (pool == "action")
			return 3;
		else if (pool == "will")
			return 6;
		else if (pool == "force")
			return 999;
		else
			return -1;
	}

	static int GetPlayerLevel(CreatureObject* creature) {
		int level = 1;

		level += GetSkillLevelValue(creature, "melee");
		level += GetSkillLevelValue(creature, "intimidation");
		level += GetSkillLevelValue(creature, "unarmed");
		level += GetSkillLevelValue(creature, "lightsaber");
		level += GetSkillLevelValue(creature, "ranged");
		level += GetSkillLevelValue(creature, "mechanics");
		level += GetSkillLevelValue(creature, "demolitions");
		level += GetSkillLevelValue(creature, "engineering");
		level += GetSkillLevelValue(creature, "larceny");
		level += GetSkillLevelValue(creature, "stealth");
		level += GetSkillLevelValue(creature, "maneuverability");
		level += GetSkillLevelValue(creature, "throwing");
		level += GetSkillLevelValue(creature, "investigation");
		level += GetSkillLevelValue(creature, "piloting");
		level += GetSkillLevelValue(creature, "survival");
		level += GetSkillLevelValue(creature, "sense");
		level += GetSkillLevelValue(creature, "slicing");
		level += GetSkillLevelValue(creature, "computers");
		level += GetSkillLevelValue(creature, "medicine");
		level += GetSkillLevelValue(creature, "science");
		level += GetSkillLevelValue(creature, "persuasion");
		level += GetSkillLevelValue(creature, "bluff");
		level += GetSkillLevelValue(creature, "composure");
		level += GetSkillLevelValue(creature, "resolve");
		level += GetSkillLevelValue(creature, "athletics");
		level += GetSkillLevelValue(creature, "lightning");
		level += GetSkillLevelValue(creature, "armor");
		level += GetSkillLevelValue(creature, "defending");
		level += GetSkillLevelValue(creature, "telekinesis");
		level += GetSkillLevelValue(creature, "control");
		level += GetSkillLevelValue(creature, "alter");
		level += GetSkillLevelValue(creature, "inward");

		return level;
	}

	static int GetSkillLevelValue(CreatureObject* creature, String skill) {
		int level = 0;
		int skillMod = creature->getSkillMod("rp_" + skill);
		if (skillMod >= 5 && skillMod < 10)
			level += 1;
		else if (skillMod == 10)
			level += 2;
		return level;
	}

	static void RewardXPForLastRoll(CreatureObject* creature, CreatureObject* dm) {
		int roll = creature.lastSkillRoll;
		String skill = creature.lastRolledSkill;
		String skillParent = BorSkill::GetSkillParent(skill);
		if (skillParent != "") { //Skill was rolled.
			//Reward Parent 10%
			int parentReward = roll / 10;
			player->getZoneServer()->getPlayerManager()->awardExperience(player, skill, roll, true); 
			player->getZoneServer()->getPlayerManager()->awardExperience(player, parentReward, roll, true); 
			dm->sendSystemMessage("Rewarded " + creature->getFirstName() + " " + String::valueOf(roll) + " @skl_n:" + skill + " experience.");
		} else { //Attribute was rolled.
			int reward = roll / 10;
			player->getZoneServer()->getPlayerManager()->awardExperience(player, skill, reward, true); 
			dm->sendSystemMessage("Rewarded " + creature->getFirstName() + " " + String::valueOf(reward) + " @skl_n:" + skill + " experience.");
		}
	}

	static void RewardXPForRoll(CreatureObject* creature, CreatureObject* dm, String skill, int roll) {
		String skillParent = BorSkill::GetSkillParent(skill);
		if (skillParent != "") { // Skill was rolled.
			// Reward Parent 10%
			int parentReward = roll / 10;
			player->getZoneServer()->getPlayerManager()->awardExperience(player, skill, roll, true);
			player->getZoneServer()->getPlayerManager()->awardExperience(player, parentReward, roll, true);
			dm->sendSystemMessage("Rewarded " + creature->getFirstName() + " " + String::valueOf(roll) + " @skl_n:" + skill + " experience.");
		} else { // Attribute was rolled.
			int reward = roll / 10;
			player->getZoneServer()->getPlayerManager()->awardExperience(player, skill, reward, true);
			dm->sendSystemMessage("Rewarded " + creature->getFirstName() + " " + String::valueOf(reward) + " @skl_n:" + skill + " experience.");
		}
	}
};

#endif /*BORCHARACTER_H_*/