/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef CREATUREOBJECTIMPLEMENTATION_H_
#define CREATUREOBJECTIMPLEMENTATION_H_

#include "engine/engine.h"

//#include "../../packets.h"

#include "../../packets/creature/CreatureObjectDeltaMessage3.h"

#include "../scene/SceneObject.h"
#include "../scene/SceneObjectImplementation.h"

#include "../../objects/player/Races.h"
#include "../../objects/tangible/CustomizationVariables.h"

#include "skills/Skill.h"
#include "../../managers/skills/SkillManager.h"
#include "skillmods/SkillModList.h"

#include "buffs/BuffList.h"
#include "buffs/BuffObject.h"

#include "../guild/Guild.h"

#include "../../../chat/ChatManager.h"

class CombatManager;

class Player;
//class Npc;

class Inventory;
class HairObject;
class TangibleObject;
class Weapon;
class Armor;
class Instrument;

class GroupObject;
class MountCreature;
class DizzyFallDownEvent;
class WoundTreatmentOverEvent;
class InjuryTreatmentOverEvent;
class StateTreatmentOverEvent;
class ConditionTreatmentOverEvent;

class MountCreature;
class BuildingObject;
class CreatureObjectServant;
class CreatureInventory;

class CreatureObjectImplementation : public CreatureObjectServant {
protected:
	unicode characterName; //character name
	string terrainName;

	CustomizationVariables customization;
	//string customization;
	string raceName; //species
	string speciesName; //species
	string gender;

	string hairObject; //hair object iff string
	CustomizationVariables hairCustomization;
	//string hairData; //hair customization string

	string stfName;

	string meatType;
	string hideType;
	string boneType;
	int milk;
	int hideMax;
	int boneMax;
	int meatMax;

	string creatureFaction;

	int xp;

	int healer;

	int pack;
	int herd;
	int stalker;
	int killer;
	int aggressive;

	string behaviorScript;

	string creatureWeapon;
	string creatureWeaponName;
	string creatureWeaponTemp;
	string creatureWeaponClass;
	int creatureWeaponEquipped;
	int creatureWeaponMinDamage;
	int creatureWeaponMaxDamage;
	float creatureWeaponAttackSpeed;
	string creatureWeaponDamageType;
	string creatureWeaponArmorPiercing;

	float internalNPCDamageModifier;

	string lootGroup;

	float tame;


	uint32 positionCounter;
	uint32 actionCounter;

	VectorMap<uint32, Skill*> creatureSkills;
	uint32 creatureSkillsCount;

	//creature objects
	Inventory* inventory;
	CreatureInventory* lootContainer;
	HairObject* hairObj;

	Time lastCombatAction;

	Vector<BaseMessage*> broadcastBuffer;

	// modifiers
	int weaponSpeedModifier;

	int centeredBonus;

	//CREO1 operands
	uint32 skillBoxesUpdateCounter;

	uint32 cashCredits;
	uint32 bankCredits;

 	//CREO3 operands
	uint8 postureState;

	uint64 stateBitmask;
	uint64 oldStateBitmask;

	uint32 creatureBitmask;

	MountCreature* mount;
	int conditionDamage;
	int maxCondition;
	Time mountCooldown;

	uint64 creatureLinkID;

	Time knockdownRecoveryTime;

	Time dizzyRecoveryTime;
	Time stunRecoveryTime;
	Time blindRecoveryTime;
	Time intimidateRecoveryTime;

	Time fireRecoveryTime;
	Time poisonRecoveryTime;
	Time bleedingRecoveryTime;
	Time diseasedRecoveryTime;

 	//CREO4 operands
	float speed;
	float acceleration;
	float height;
	SkillModList creatureSkillMods;
	SkillModList creatureSkillModBonus;
	BuffList creatureBuffs;

	uint32 skillModsCounter;
	string skillMod;

	uint32 skillModBonusCounter;

	//CREO6 operands
	uint32 defenderUpdateCounter;
	uint64 defenderID;

	string mood;
	uint8 moodid;

	Weapon* weaponObject;
	ManagedReference<SceneObject> targetObject;

	// HAM variables
	uint32 hamUpdateCounter;
	uint32 hamMaxUpdateCounter;
	uint32 hamBaseUpdateCounter;
	uint32 hamEncumbUpdateCounter;
	uint32 woundsUpdateCounter;

	//CREO1 HAM variables
	uint32 baseHealth;
	uint32 baseStrength;
	uint32 baseConstitution;
	uint32 baseAction;
	uint32 baseQuickness;
	uint32 baseStamina;
	uint32 baseMind;
	uint32 baseFocus;
	uint32 baseWillpower;

	uint32 health;
	uint32 strength;
	uint32 constitution;
	uint32 action;
	uint32 quickness;
	uint32 stamina;
	uint32 mind;
	uint32 focus;
	uint32 willpower;

	int healthMax;
	int strengthMax;
	int constitutionMax;
	int actionMax;
	int quicknessMax;
	int staminaMax;
	int mindMax;
	int focusMax;
	int willpowerMax;

	uint32 healthEncumbrance;
	uint32 actionEncumbrance;
	uint32 mindEncumbrance;

	// Inherent Armor,Resists
	uint32 armor;

	float kinetic;
	float energy;
	float electricity;
	float stun;
	float blast;
	float heat;
	float cold;
	float acid;
	float lightSaber;

	// WOUND vars
	uint32 healthWounds;
	uint32 strengthWounds;
	uint32 constitutionWounds;
	uint32 actionWounds;
	uint32 quicknessWounds;
	uint32 staminaWounds;
	uint32 mindWounds;
	uint32 focusWounds;
	uint32 willpowerWounds;

	// AKA Battle Fatigue
	uint32 shockWounds;

	// misc
	uint32 pvpStatusBitmask;
	uint32 faction;
	uint8 factionRank;

	// combat
	int fireDotType;
	int fireDotStrength;

	int poisonDotType;
	int poisonDotStrength;

	int diseaseDotType;
	int diseaseDotStrength;

	int bleedingDotType;
	int bleedingDotStrength;

	Time nextBleedingTick;
	Time nextFireTick;
	Time nextPoisonTick;
	Time nextDiseaseTick;

	Time knockdownRecovery;
	Time postureDownRecovery;
	Time postureUpRecovery;

	Time nextAttackDelay;
	Time nextAttackDelayRecovery;

	bool meditating;

	int accuracy;

	Time burstRunCooldown;
	int damageBonus;
	int defenseBonus;

	VectorMap<uint32, uint32> queuedStates; // TODO: make SortedVector for basic types

	DizzyFallDownEvent* dizzyFallDownEvent;

	Vector<ManagedReference<SceneObject> > defenderList;

	VectorMap<CreatureObject*, uint32> damageMap;

	//group stuff
	uint64 groupId;
	uint64 groupInviteCount;
	uint64 groupInviterID;

	GroupObject* group;

	// Entertainer stuff
	string performanceAnimation;
	uint32 performanceCounter;
	string performanceName;

	int instrumentID; // instrument + song

	bool doDancing;
	bool doPlayingMusic;
	bool doListening;
	bool doWatching;

	// TODO: Deprecate
	bool healthBuff;
	bool strengthBuff;
	bool constitutionBuff;
	bool actionBuff;
	bool quicknessBuff;
	bool staminaBuff;
	bool mindBuff;
	bool focusBuff;
	bool willpowerBuff;

	uint64 watchID;
	uint64 listenID;

	ManagedSortedVector<CreatureObject> listeners;
	ManagedSortedVector<CreatureObject> watchers;

	float danceBuffDuration; // track the duration
	float musicBuffDuration;

	float danceBuffStrength; // track the duration
	float musicBuffStrength;

	bool sittingOnObject;

	Guild* guild;

	uint32 lastMovementUpdateStamp;
	int ignoreMovementTests;
	Time lastServerMovementStamp;

	int level;

	//Medical Timers
	bool doWoundTreatment;
	bool doInjuryTreatment;
	bool doStateTreatment;
	bool doConditionTreatment;

	WoundTreatmentOverEvent* woundTreatmentEvent;
	InjuryTreatmentOverEvent* injuryTreatmentEvent;
	StateTreatmentOverEvent* stateTreatmentEvent;
	ConditionTreatmentOverEvent* conditionTreatmentEvent;

public:
	static const float DEFAULT_SPEED = 5.376f;
	static const float DEFAULT_ACCELERATION = 1.549f;

	static const uint8 INVALID_POSTURE = 0xFF;
	static const uint8 UPRIGHT_POSTURE = 0;
	static const uint8 CROUCHED_POSTURE = 1;
	static const uint8 PRONE_POSTURE = 2;
	static const uint8 SNEAKING_POSTURE = 3;
	static const uint8 BLOCKING_POSTURE = 4;
	static const uint8 CLIMBING_POSTURE = 5;
	static const uint8 FLYING_POSTURE = 6;
	static const uint8 LYINGDOWN_POSTURE = 7;
	static const uint8 SITTING_POSTURE = 8;
	static const uint8 SKILLANIMATING_POSTURE = 9;
	static const uint8 DRIVINGVEHICLE_POSTURE = 10;
	static const uint8 RIDINGCREATURE_POSTURE = 11;
	static const uint8 KNOCKEDDOWN_POSTURE = 12;
	static const uint8 INCAPACITATED_POSTURE = 13;
	static const uint8 DEAD_POSTURE = 14;

	static const uint64 INVALID_STATE = 0x00;
	static const uint64 COVER_STATE = 0x01;
	static const uint64 COMBAT_STATE = 0x02;
	static const uint64 PEACE_STATE = 0x04;
	static const uint64 AIMING_STATE = 0x08;
	static const uint64 ALERT_STATE = 0x10;
	static const uint64 BERSERK_STATE = 0x20;
	static const uint64 FEIGNDEATH_STATE = 0x40;
	static const uint64 COMBATATTITUDEEVASIVE_STATE = 0x80;
	static const uint64 COMBATATTITUDENORMAL_STATE = 0x100;
	static const uint64 COMBATATTITUDEAGGRESSIVE_STATE = 0x200;
	static const uint64 TUMBLING_STATE = 0x400;
	static const uint64 RALLIED_STATE = 0x800;
	static const uint64 STUNNED_STATE = 0x1000;
	static const uint64 BLINDED_STATE = 0x2000;
	static const uint64 DIZZY_STATE = 0x4000;
	static const uint64 INTIMIDATED_STATE = 0x8000;
	static const uint64 IMMOBILIZED_STATE = 0x10000;
	static const uint64 FROZEN_STATE = 0x20000;
	static const uint64 SWIMMING_STATE = 0x40000;
	static const uint64 SITTINGONCHAIR_STATE = 0x80000;
	static const uint64 CRAFTING_STATE = 0x100000;
	static const uint64 GLOWINGJEDI_STATE = 0x200000;
	static const uint64 MASKSCENT_STATE = 0x400000;
	static const uint64 POISONED_STATE = 0x800000;
	static const uint64 BLEEDING_STATE = 0x1000000;
	static const uint64 DISEASED_STATE = 0x2000000;
	static const uint64 ONFIRE_STATE = 0x4000000;
	static const uint64 RIDINGMOUNT_STATE = 0x8000000;
	static const uint64 MOUNTEDCREATURE_STATE = 0x10000000;
	static const uint64 PILOTSHIP_STATE = 0x20000000;
	static const uint64 SHIPOPERATIONS_STATE = 0x40000000;
	static const uint64 SHIPGUNNER_STATE = 0x80000000;
	//static const uint64 SHIPINTERIOR_STATE = 0x100000000;
	//static const uint64 PILOTINGPOBSHIP_STATE = 0x200000000;

	static const uint32 NULL_FLAG = 0x00;
	static const uint32 ATTACKABLE_FLAG = 0x01;
	static const uint32 AGGRESSIVE_FLAG = 0x02;
	static const uint32 OVERT_FLAG = 0x04;
	static const uint32 TEF_FLAG = 0x08;
	static const uint32 PLAYER_FLAG = 0x10;
	static const uint32 ENEMY_FLAG = 0x20;
	static const uint32 DUEL_FLAG = 0x40;

public:
	CreatureObjectImplementation(uint64 oid);

	virtual ~CreatureObjectImplementation();

	// opdarand Update methods
	void doCombatAnimation(CreatureObject* defender, uint32 animcrc, uint8 hit = 0);
	void doAnimation(const string& anim);
	void playEffect(const string& file, const string& aux = "");
	void showFlyText(const string& file, const string& aux, uint8 red, uint8 green, uint8 blue);
	void sendCombatSpam(CreatureObject* defender, TangibleObject* item, uint32 damage, const string& skill, bool areaSpam = true);

	void setPosture(uint8 state, bool overrideDizzy = false, bool objectInteraction = false, float objX = 0, float objY = 0, float objZ = 0);

	void setDefender(SceneObject* defender);
	void addDefender(SceneObject* defender);
	void removeDefender(SceneObject* defender);
	void removeDefenders();
	bool hasDefender(SceneObject* defender);

	void setCombatState();
	void clearCombatState(bool removeDefenders = true);

	bool setState(uint64 state);
	bool clearState(uint64 state);
	void updateStates();
	void clearStates();

	bool takeHealthDamage(int32 damage); // Instead of having to pass negative damage values
	bool takeActionDamage(int32 damage); // we can now pass damage to a damage function
	bool takeMindDamage(int32 damage);   // using positive values for damage

	bool changeHAMBars(int32 hp, int32 ap, int32 mp, bool forcedChange = false);
	bool changeHAMWounds(int32 hpwnd, int32 apwnd, int32 mpwnd, bool forcedChange = false);
	void changeMaxHAMBars(int32 hp, int32 ap, int32 mp);

	// Change Current HAM
	bool changeHealthBar(int32 hp, bool forcedChange = false);
	bool changeStrengthBar(int32 st, bool forcedChange = false);
	bool changeConstitutionBar(int32 cs, bool forcedChange = false);
	bool changeMindBar(int32 mp, bool forcedChange = false);
	bool changeFocusBar(int32 fc, bool forcedChange = false);
	bool changeWillpowerBar(int32 wl, bool forcedChange = false);
	bool changeActionBar(int32 ap, bool forcedChange = false);
	bool changeQuicknessBar(int32 qc, bool forcedChange = false);
	bool changeStaminaBar(int32 st, bool forcedChange = false);

	// Change Max HAM
	void changeMaxHealthBar(int32 hp, bool updateClient = true);
	void changeMaxStrengthBar(int32 st, bool updateClient = true);
	void changeMaxConstitutionBar(int32 cs, bool updateClient = true);
	void changeMaxActionBar(int32 ap, bool updateClient = true);
	void changeMaxQuicknessBar(int32 qc, bool updateClient = true);
	void changeMaxStaminaBar(int32 st, bool updateClient = true);
	void changeMaxMindBar(int32 mp, bool updateClient = true);
	void changeMaxFocusBar(int32 fc, bool updateClient = true);
	void changeMaxWillpowerBar(int32 wl, bool updateClient = true);

	// Change HAM Wounds
	bool changeHealthWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeStrengthWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeConstitutionWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeActionWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeQuicknessWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeStaminaWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeMindWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeFocusWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeWillpowerWoundsBar(int32 wounds, bool forcedChange = false);

	void changeConditionDamage(int amount);

	void changeShockWounds(int bf);

	void resetHAMBars(bool doUpdateClient);

	void setMaxHAMBars(uint32 hp, uint32 ap, uint32 mp);
	void setHAMBars(uint32 hp, uint32 ap, uint32 mp);
	void setHAMWoundsBars(uint32 hpwnds, uint32 acwnds, uint32 mpwnds);

	// Set Current HAM
	void setHealthBar(uint32 hp);
	void setStrengthBar(uint32 st);
	void setConstitutionBar(uint32 cst);
	void setActionBar(uint32 ap);
	void setQuicknessBar(uint32 qck);
	void setStaminaBar(uint32 sta);
	void setMindBar(uint32 mp);
	void setFocusBar(uint32 fc);
	void setWillpowerBar(uint32 will);

	// Set Base HAM
	void setBaseHealthBar(uint32 hp, bool updateClient = true);
	void setBaseStrengthBar(uint32 st, bool updateClient = true);
	void setBaseConstitutionBar(uint32 cst, bool updateClient = true);
	void setBaseActionBar(uint32 ap, bool updateClient = true);
	void setBaseQuicknessBar(uint32 qck, bool updateClient = true);
	void setBaseStaminaBar(uint32 sta, bool updateClient = true);
	void setBaseMindBar(uint32 mp, bool updateClient = true);
	void setBaseFocusBar(uint32 fc, bool updateClient = true);
	void setBaseWillpowerBar(uint32 will, bool updateClient = true);

	// Set Max HAM
	void setMaxHealthBar(uint32 hp, bool updateClient = true);
	void setMaxStrengthBar(uint32 st, bool updateClient = true);
	void setMaxConstitutionBar(uint32 cst, bool updateClient = true);
	void setMaxActionBar(uint32 ap, bool updateClient = true);
	void setMaxQuicknessBar(uint32 qck, bool updateClient = true);
	void setMaxStaminaBar(uint32 sta, bool updateClient = true);
	void setMaxMindBar(uint32 mp, bool updateClient = true);
	void setMaxFocusBar(uint32 fc, bool updateClient = true);
	void setMaxWillpowerBar(uint32 will, bool updateClient = true);

	// Set HAM Wounds
	void setHealthWoundsBar(uint32 wounds);
	void setStrengthWoundsBar(uint32 wounds);
	void setConstitutionWoundsBar(uint32 wounds);
	void setActionWoundsBar(uint32 wounds);
	void setQuicknessWoundsBar(uint32 wounds);
	void setStaminaWoundsBar(uint32 wounds);
	void setMindWoundsBar(uint32 wounds);
	void setFocusWoundsBar(uint32 wounds);
	void setWillpowerWoundsBar(uint32 wounds);

	void calculateHAMregen();
	float calculateBFRatio();

	void activateBurstRun();
	void deactivateBurstRun();

	void updateTarget(uint64 targ);
	void updateTarget(SceneObject* targ);

	void clearTarget();

	void setDizziedState();
	void setStunnedState();
	void setBlindedState();
	void setIntimidatedState();

	bool setNextAttackDelay(int del);

	void setMeditateState();

	void addDamage(CreatureObject* creature, uint32 damage);
	void removeFromDamageMap(CreatureObject* target);

	bool isLootOwner(CreatureObject* creature);
	CreatureObject* getLootOwner();

	virtual bool isAttackable() {
		return !isIncapacitated() && !isDead();
	}

	virtual void handleDeath() {
		setPosture(DEAD_POSTURE);
	}

	bool isAttackableBy(CreatureObject* creature) {
		if (creature->hatesFaction(this->getFaction()))
			return true;

		return (pvpStatusBitmask & ATTACKABLE_FLAG);
	}

	bool hasAttackDelay() {
		return !nextAttackDelay.isPast();
	}

	void clearAttackDelay() {
		nextAttackDelay.update();
	}

	void setRebel() {
		faction = String::hashCode("rebel");
	}

	void setImperial() {
		faction = String::hashCode("imperial");
	}

	void setNeutral() {
		faction = 0;
	}

	void setFaction(uint32 fac) {
		faction = fac;
	}

	void setLastMovementUpdateStamp(uint32 tme) {
		lastMovementUpdateStamp = tme;
	}

	void setIgnoreMovementTests(int times) {
		ignoreMovementTests = times;
	}

	void sendFactionStatusTo(Player* player, bool doTwoWay = false);

	int getCreatureSkillsSize() {
		return creatureSkills.size();
	}

	void addSkill(Skill* skill) {
		creatureSkills.put(skill->getNameCRC(), skill);
	}

	Skill* getSkill(const string& name) {
		return creatureSkills.get(String::hashCode(name));
	}

	inline string& getSkill(int idx) {
		return creatureSkills.get(idx)->getSkillName();
	}

	void removeSkill(Skill* skill) {
		creatureSkills.drop(skill->getNameCRC());
	}

	bool hasSkill(uint32 skillCRC) {
		return creatureSkills.contains(skillCRC);
	}

	void addSkills(Vector<Skill*>& skills, bool updateClient);
	void removeSkills(Vector<Skill*>& skills, bool updateClient);

	inline uint32 getCreatureSkillsCount() {
		return creatureSkillsCount;
	}

	inline uint32 getNewCreatureSkillsCount(int cnt) {
		return creatureSkillsCount += cnt;
	}

	inline uint32 getDamage(CreatureObject* creature) {
		return damageMap.get(creature);
	}

	uint32 getMitigation(const string& mit);

	virtual void activateRecovery() {
	}

	// dots
	void setPoisonedState(int str, int type, int duration);
	void setBleedingState(int str, int type, int duration);
	void setDiseasedState(int str, int type, int duration);
	void setOnFireState(int str, int type, int duration);

	void doPoisonTick();
	void doBleedingTick();
	void doDiseaseTick();
	void doFireTick();

	virtual void doIncapacitate() {
	}

	bool isOnFullHealth() {
		return (getHealth() == getHealthMax() - getHealthWounds()) && (getAction() == getActionMax() - getActionWounds()) && (getMind() == getMindMax() - getMindWounds());
	}

	void setGroup(GroupObject* Group) {
		group = Group;
	}

	void removeGroup() {
		group = NULL;
	}

	bool isInAGroup() {
		return group != NULL;
	}

	inline uint64 getGroupID() {
		return groupId;
	}

	inline void setGroupID(uint64 gid) {
		groupId = gid;
	}

	inline bool isIncapacitated() {
		return postureState == INCAPACITATED_POSTURE;
	}

	inline bool isDead() {
		return postureState == DEAD_POSTURE;
	}

	inline bool isKnockedDown() {
		return postureState == KNOCKEDDOWN_POSTURE;
	}

	inline bool isKneeled() {
		return postureState == CROUCHED_POSTURE;
	}

	inline bool isProne() {
		return postureState == PRONE_POSTURE;
	}

	inline bool isSitting() {
		return postureState == SITTING_POSTURE;
	}

	inline bool isInCombat() {
		return stateBitmask & COMBAT_STATE;
	}

	inline bool isDizzied() {
		return stateBitmask & DIZZY_STATE;
	}

	inline bool isStunned() {
		return stateBitmask & STUNNED_STATE;
	}

	inline bool isBlinded() {
		return stateBitmask & BLINDED_STATE;
	}

	inline bool isIntimidated() {
		return stateBitmask & INTIMIDATED_STATE;
	}

	inline bool isDiseased() {
		return stateBitmask & DISEASED_STATE;
	}

	inline bool isPoisoned() {
		return stateBitmask & POISONED_STATE;
	}

	inline bool isBleeding() {
		return stateBitmask & BLEEDING_STATE;
	}

	inline bool isOnFire() {
		return stateBitmask & ONFIRE_STATE;
	}

	inline bool isMounted() {
		return stateBitmask & RIDINGMOUNT_STATE;
	}

	inline bool isRidingCreature() {
		return stateBitmask & MOUNTEDCREATURE_STATE;
	}

	inline bool isPeaced() {
		return stateBitmask & PEACE_STATE;
	}

	inline bool isMeditating() {
		return meditating;
	}

	// misc methods
	void updateKnockdownRecovery() {
		knockdownRecovery.update();
		knockdownRecovery.addMiliTime(30000);
	}

	bool checkKnockdownRecovery() {
		return knockdownRecovery.isPast();
	}

	void updatePostureDownRecovery() {
		postureDownRecovery.update();
		postureDownRecovery.addMiliTime(30000);
	}

	void updatePostureUpRecovery() {
		postureUpRecovery.update();
		postureUpRecovery.addMiliTime(30000);
	}

	bool checkPostureDownRecovery() {
		return postureDownRecovery.isPast();
	}

	bool checkPostureUpRecovery() {
		return postureUpRecovery.isPast();
	}

	// item methods
	void equipItem(TangibleObject* item);
	void unequipItem(TangibleObject* item);

	void addInventoryItem(TangibleObject* item);
	void addInventoryResource(ResourceContainer* rcno);

	SceneObject* getInventoryItem(uint64 oid);

	void removeInventoryItem(SceneObject* item);
	void removeInventoryItem(uint64 oid);

	void addLootItem(TangibleObject* item);

	TangibleObject* getLootItem(uint64 oid);

	void removeLootItem(SceneObject* item);
	void removeLootItem(uint64 oid);

	// Entertainer methods
	void startDancing(const string& anim, bool changeDance = false);
	void startPlayingMusic(const string& anim, bool changeMusic = false);

	void stopDancing();
	void stopPlayingMusic();

	void startWatch(uint64 entid);
	void startListen(uint64 entid);
	void stopWatch(uint64 entid, bool doSendPackets = true, bool forced = false, bool doLock = true);
	void stopListen(uint64 entid, bool doSendPackets = true, bool forced = false, bool doLock = true);
	void activateEntertainerBuff(int performanceType);

	void doFlourish(const string& modifier = "");
	void addEntertainerFlourishBuff();
	// Rename to Tick Patron?
	void doEntertainerPatronEffects(bool healShock = false, bool healWounds = false, bool addBuff = false);
	void doPerformanceAction();

	bool isInBuilding();
	SceneObject* getBuilding();
	int getBuildingType();
	bool canGiveEntertainBuff();

	// guild methods
	void sendGuildTo();

	// mount methods
	void mountCreature(MountCreature* mnt, bool lockMount = true);
	void dismount(bool lockMount = true, bool ignoreCooldown = false);

	// buffing methods
	void addBuff(int buffCRC, float duration); // Mostly Debugging purposes
	//void applyBuff(const string& type, int value, float duration);
	void applyBuff(Buff *buff);
	void applyBuff(BuffObject *bo);
	//void removeBuff(const string& type, int value, Event* event);
	void removeBuff(const uint32 buffCRC, bool remove = true);


	void removeBuffs(bool doUpdateCreature = true);

	// cash transaction methods
	void addCashCredits(uint32 credits);
	void addBankCredits(uint32 credits);
	void updateCashCredits(uint32 credits);
	void updateBankCredits(uint32 credits);
	void subtractCashCredits(uint32 credits);
	void subtractBankCredits(uint32 credits);

	bool verifyCashCredits(uint32 creditsToRemove);
	bool verifyBankCredits(uint32 creditsToRemove);

	// misc
	virtual uint64 getNewItemID() {
		return 0;
	}

	// client level methods
	void sendToOwner(Player* player, bool doClose = true);

	void sendTo(Player* player, bool doClose = true);

	void sendItemsTo(Player* player);

	void sendDestroyTo(Player* player);

	void broadcastMessages(Vector<BaseMessage*>& msgs, int range = 128, bool doLock = true);

	void sendSystemMessage(const string& message);
	void sendSystemMessage(const string& file, const string& str, uint64 targetid = 0);

	void updateSpeed(float speed, float acceleration);

	void updateGroupId(uint64 id);
	void updateGroupInviterId(uint64 id);

	float getDistanceTo(CreatureObject* targetCreature);

	void updateMood(const string& md);

	inline void updateServerMovementStamp() {
		lastServerMovementStamp.update();
	}

	inline uint64 getLastServerMovementStamp() {
		return lastServerMovementStamp.miliDifference();
	}

protected:
	void sendEntertainingUpdate(uint32 entval, const string& performance, uint32 perfcntr, int instrid);
	void sendEntertainmentUpdate(uint64 entid, const string& mood, bool updateEntVal = false);

public:
	// setters and getters
	void addSkillMod(const string& name, int mod, bool updateClient = false);
	void removeSkillMod(const string& name, bool updateClient = false);

	void addSkillModBonus(const string& name, int mod, bool updateClient = false);
	void removeSkillModBonus(const string& name, bool updateClient = false);

	bool hasQueuedState(uint32 skillCRC) {
		return queuedStates.contains(skillCRC);
	}

	bool removeQueuedState(uint32 skillCRC) {
		return queuedStates.drop(skillCRC);
	}

	bool addQueuedState(uint32 skillCRC) {
		return queuedStates.put(skillCRC, skillCRC);
	}

	SkillModList* getSkillModList() {
		return &creatureSkillMods;
	}

	SkillModList* getSkillModBonusList() {
		return &creatureSkillModBonus;
	}

	BuffList* getBuffsList() {
		return &creatureBuffs;
	}

	void setGroupInviterID(uint64 oid) {
		groupInviterID = oid;
	}

	int getSkillMod(const string& name) {
		// TODO: Add Buffs
		int bonus = creatureSkillModBonus.get(name);
		if (bonus > 25)
			bonus = 25;
		return creatureSkillMods.get(name) + bonus;
	}

	bool hasSkillMod(const string& name) {
		return creatureSkillMods.containsKey(name);
	}

	void removeSkillMod(string& name) {
		creatureSkillMods.remove(name);
	}

	Buff* getBuff(const uint32& buffCRC) {
		Buff *b = creatureBuffs.get(buffCRC);
		return b;
	}

	BuffObject* getBuffObject(const uint32& buffCRC) {
		BuffObject *bo = new BuffObject(creatureBuffs.get(buffCRC));
		return bo;
	}

	int getSkillModBonus(const string& name) {
		int bonus = creatureSkillModBonus.get(name);
		return bonus;
	}

	bool hasBuff(const uint32 buffCRC) {
		return creatureBuffs.contains(buffCRC);
	}

	bool hasSpice() {
		for(int i = 0; i < creatureBuffs.size(); i++)
		{
			Buff *buff = creatureBuffs.get(i);
			if(buff != NULL && buff->getBuffType() == BuffType::SPICE)
				return true;
		}
		return false;
	}

	bool hatesFaction(uint32 faction);

	bool hasSkillModBonus(const string& name) {
		return creatureSkillModBonus.containsKey(name);
	}

	void removeSkillModBonus(string& name) {
		creatureSkillModBonus.remove(name);
	}

	inline int getDamageBonus() {
		return damageBonus;
	}

	inline int getDefenseBonus() {
		return defenseBonus;
	}

	inline uint64 getGroupInviterID() {
		return groupInviterID;
	}

	inline uint64 getNewGroupInviteCounter() {
		return ++groupInviteCount;
	}

	inline uint64 getGroupInviteCounter() {
		return groupInviteCount;
	}

	inline int getConditionDamage() {
		return conditionDamage;
	}

	inline int getMaxCondition() {
		return maxCondition;
	}

	inline int getCondition() {
		return maxCondition - conditionDamage;
	}

	inline int getCenteredBonus() {
		return centeredBonus;
	}

	inline uint64 getCreatureLinkID() {
		return creatureLinkID;
	}

	inline uint32 getLastMovementUpdateStamp() {
		return lastMovementUpdateStamp;
	}

	inline int getIgnoreMovementTests() {
		return ignoreMovementTests;
	}

	inline void setMount(MountCreature* mnt) {
		mount = mnt;
	}

	inline MountCreature* getMount() {
		return mount;
	}

	inline void setDamageBonus(int bonus) {
		damageBonus = bonus;
	}

	inline void setDefenseBonus(int bonus) {
		defenseBonus = bonus;
	}

	inline void setCreatureLinkID(uint64 creatureID) {
		creatureLinkID = creatureID;
	}

	inline void setCharacterName(const string& name) {
		characterName = name;
	}

	inline void setCharacterName(const unicode& name) {
		characterName = name;
	}

	inline void setTerrainName(const string& name) {
		terrainName = name;
	}

	inline void setCharacterAppearance(const string& cust) {
		customization = cust;
	}

	inline void setHairAppearance(const string& cust) {
		hairCustomization = cust;
	}

	inline void setAppearanceAttribute(uint8 type, uint8 value) {
		customization.setVariable(type, value);

		// TODO send packet update?
	}

	inline void setAppearanceAttribute(string type, uint8 value) {
		customization.setVariable(type, value);

		// TODO send packet update?
	}

	inline void setHairAppearanceAttribute(uint8 type, uint8 value) {
		hairCustomization.setVariable(type, value);

		// TODO send packet update?
	}

	inline void setHairAppearanceAttribute(string type, uint8 value) {
		hairCustomization.setVariable(type, value);

		// TODO send packet update?
	}


	void updateCharacterAppearance();

	inline void setRaceName(const string& name) {
		raceName = name;
	}

	inline void setSpeciesName(const string& name) {
		speciesName = name;
	}

	inline void setGender(const string& gend) {
		gender = gend;
	}

	inline void setHeight(float h) {
		height = h;
	}

	inline void setWeapon(Weapon* wep) {
		weaponObject = wep;
	}

	inline void setMood(uint8 mdid) {
		moodid = mdid;
		mood = Races::getMood(moodid);
	}

	inline void setMood(const string& m) {
		mood = m;
	}

	inline void setPvpStatusBitmask(uint32 mask) {
		pvpStatusBitmask = mask;
	}

	inline void setFactionRank(uint8 rank, bool updateClient = true) {
		factionRank = rank;

		if (updateClient) {
			CreatureObjectDeltaMessage3* dcreo3 = new CreatureObjectDeltaMessage3((CreatureObject*) _this);
			dcreo3->updateFactionRank();
			dcreo3->close();
			this->broadcastMessage(dcreo3);
		}
	}

	void updateHAMBars();

	void updateBaseStats();

	inline void setBaseHealth(uint32 value) {
		baseHealth = value;
	}

	inline void setBaseStrength(uint32 value) {
		baseStrength = value;
	}

	inline void setBaseConstitution(uint32 value) {
		baseConstitution = value;
	}

	inline void setBaseAction(uint32 value) {
		baseAction = value;
	}

	inline void setBaseQuickness(uint32 value) {
		baseQuickness = value;
	}

	inline void setBaseStamina(uint32 value) {
		baseStamina = value;
	}

	inline void setBaseMind(uint32 value) {
		baseMind = value;
	}

	inline void setBaseFocus(uint32 value) {
		baseFocus = value;
	}

	inline void setBaseWillpower(uint32 value) {
		baseWillpower = value;
	}

	inline void setHealth(uint32 value) {
		health = value;
	}

	inline void changeHealth(int32 value) {
		health += value;
	}

	inline void setStrength(uint32 value) {
		strength = value;
	}

	inline void changeStrength(int32 value) {
		strength += value;
	}

	inline void setConstitution(uint32 value) {
		constitution = value;
	}

	inline void changeConstitution(int32 value) {
		constitution += value;
	}

	inline void setAction(uint32 value) {
		action = value;
	}

	inline void changeAction(int32 value) {
		action += value;
	}

	inline void setQuickness(uint32 value) {
		quickness = value;
	}

	inline void changeQuickness(int32 value) {
		quickness += value;
	}

	inline void setStamina(uint32 value) {
		stamina = value;
	}

	inline void changeStamina(int32 value) {
		stamina += value;
	}

	inline void setMind(uint32 value) {
		mind = value;
	}

	inline void changeMind(int32 value) {
		mind += value;
	}

	inline void setFocus(uint32 value) {
		focus = value;
	}

	inline void changeFocus(int32 value) {
		focus += value;
	}

	inline void setWillpower(uint32 value) {
		willpower = value;
	}

	inline void changeWillpower(int32 value) {
		willpower += value;
	}


	inline void setHealthMax(uint32 value) {
		healthMax = value;
	}

	inline void changeHealthMax(int32 value) {
		healthMax += value;
	}

	inline void setStrengthMax(uint32 value) {
		strengthMax = value;
	}

	inline void changeStrengthMax(int32 value) {
		strengthMax += value;
	}

	inline void setConstitutionMax(uint32 value) {
		constitutionMax = value;
	}

	inline void changeConstitutionMax(int32 value) {
		constitutionMax += value;
	}

	inline void setActionMax(uint32 value) {
		actionMax = value;
	}

	inline void changeActionMax(int32 value) {
		actionMax += value;
	}

	inline void setQuicknessMax(uint32 value) {
		quicknessMax = value;
	}

	inline void changeQuicknessMax(int32 value) {
		quicknessMax += value;
	}

	inline void setStaminaMax(uint32 value) {
		staminaMax = value;
	}

	inline void changeStaminaMax(int32 value) {
		staminaMax += value;
	}

	inline void setMindMax(uint32 value) {
		mindMax = value;
	}

	inline void changeMindMax(int32 value) {
		mindMax += value;
	}

	inline void setFocusMax(uint32 value) {
		focusMax = value;
	}

	inline void changeFocusMax(int32 value) {
		focusMax += value;
	}

	inline void setWillpowerMax(uint32 value) {
		willpowerMax = value;
	}

	inline void changeWillpowerMax(int32 value) {
		willpowerMax += value;
	}

	inline void setArmor(uint32 ar) {
		armor = ar;
	}

	inline void setKinetic(float kin) {
		kinetic = kin;
	}

	inline void setEnergy(float ene) {
		energy = ene;
	}

	inline void setElectricity(float ele) {
		electricity = ele;
	}

	inline void setStun(float stu) {
		stun = stu;
	}

	inline void setBlast(float bla) {
		blast = bla;
	}

	inline void setHeat(float hea) {
		heat = hea;
	}

	inline void setCold(float col) {
		cold = col;
	}

	inline void setAcid(float aci) {
		acid = aci;
	}

	inline void setLightSaber(float lig) {
		lightSaber = lig;
	}

	inline void setHealthWounds(uint32 wounds) {
		healthWounds = wounds;
	}

	inline void setStrengthWounds(uint32 wounds) {
		strengthWounds = wounds;
	}

	inline void setConstitutionWounds(uint32 wounds) {
		constitutionWounds = wounds;
	}

	inline void setActionWounds(uint32 wounds) {
		actionWounds = wounds;
	}

	inline void setQuicknessWounds(uint32 wounds) {
		quicknessWounds = wounds;
	}

	inline void setStaminaWounds(uint32 wounds) {
		staminaWounds = wounds;
	}

	inline void setMindWounds(uint32 wounds) {
		mindWounds = wounds;
	}

	inline void setFocusWounds(uint32 wounds) {
		focusWounds = wounds;
	}

	inline void setWillpowerWounds(uint32 wounds) {
		willpowerWounds = wounds;
	}
	inline void setShockWounds(uint32 wounds) {
		shockWounds = wounds;
	}

	inline void setWoundsUpdateCounter(uint32 count) {
		woundsUpdateCounter = count;
	}

	inline void setDefenderID(uint64 did) {
		defenderID = did;
	}

	inline void setSpeed(float spd) {
		speed = spd;
	}

	inline void setAcceleration(float acc) {
		acceleration = acc;
	}

	// getters
	inline unicode& getCharacterName() {
		return characterName;
	}

	inline string& getTerrainName() {
		return terrainName;
	}

	inline void getCharacterAppearance(string& appearance) {
		customization.toString(appearance);
		//appearance = customization;
	}

	inline void getHairAppearance(string& appearance) {
		hairCustomization.toString(appearance);
		//appearance = customization;
	}


	inline string& getRaceName() {
		return raceName;
	}

	inline string& getSpeciesName() {
		return speciesName;
	}

	inline string& getGender() {
		return gender;
	}

	inline string& getStfName() {
		return stfName;
	}

	inline uint32 getPositionCounter() {
		return positionCounter++;
	}

	inline uint32 getDefenderListSize() {
		return defenderList.size();
	}

	inline SceneObject* getDefender(int idx) {
		return defenderList.get(idx);
	}

	inline uint32 getBankCredits() {
		return bankCredits;
	}

	inline uint32 getCashCredits() {
		return cashCredits;
	}

	inline SceneObject* getTarget() {
		return targetObject;
	}

	inline Weapon* getWeapon() {
		return weaponObject;
	}

	Instrument* getInstrument();

	Armor* getArmor(int type);

	// HAM getters
	inline uint32 getBaseHealth() {
		return baseHealth;
	}

	inline uint32 getBaseStrength() {
		return baseStrength;
	}

	inline uint32 getBaseConstitution() {
		return baseConstitution;
	}

	inline uint32 getBaseAction() {
		return baseAction;
	}

	inline uint32 getBaseQuickness() {
		return baseQuickness;
	}

	inline uint32 getBaseStamina() {
		return baseStamina;
	}

	inline uint32 getBaseMind() {
		return baseMind;
	}

	inline uint32 getBaseFocus() {
		return baseFocus;
	}

	inline uint32 getBaseWillpower() {
		return baseWillpower;
	}

	inline uint32 getHealth() {
		return health;
	}

	inline uint32 getStrength() {
		if ((int) strength < 1)
			return 1;
		else
			return strength;
	}

	inline uint32 getConstitution() {
		if ((int) constitution < 1)
			return 1;
		else
			return constitution;
	}

	inline uint32 getAction() {
		return action;
	}

	inline uint32 getQuickness() {
		if ((int) quickness < 1)
			return 1;
		else
			return quickness;
	}

	inline uint32 getStamina() {
		if ((int) stamina < 1)
			return 1;
		else
			return stamina;
	}

	inline uint32 getMind() {
		return mind;
	}

	inline uint32 getFocus() {
		if ((int) focus < 1)
			return 1;
		else
			return focus;
	}

	inline uint32 getWillpower() {
		if ((int) willpower < 1)
			return 1;
		else
			return willpower;
	}

	inline uint32 getHealthMax() {
		if(healthMax < 1)
			return 1;
		else
			return healthMax;
	}

	inline uint32 getStrengthMax() {
		if (strengthMax < 1)
			return 1;
		else
			return strengthMax;
	}

	inline uint32 getConstitutionMax() {
		if (constitutionMax < 1)
			return 1;
		else
			return constitutionMax;
	}

	inline uint32 getActionMax() {
		if(actionMax < 1)
			return 1;
		else
			return actionMax;
	}

	inline uint32 getQuicknessMax() {
		if (quicknessMax < 1)
			return 1;
		else
			return quicknessMax;
	}

	inline uint32 getStaminaMax() {
		if (staminaMax < 1)
			return 1;
		else
			return staminaMax;
	}

	inline uint32 getMindMax() {
		if(mindMax < 1)
			return 1;
		else
			return mindMax;
	}

	inline uint32 getFocusMax() {
		if (focusMax < 1)
			return 1;
		else
			return focusMax;
	}

	inline uint32 getWillpowerMax() {
		if (willpowerMax < 1)
			return 1;
		else
			return willpowerMax;
	}

	inline uint32 getArmor() {
		return armor;
	}

	inline float getKinetic() {
		return kinetic - (kinetic * calculateBFRatio());
	}

	inline float getEnergy() {
		return energy - (energy  * calculateBFRatio());
	}

	inline float getElectricity() {
		return electricity - (electricity  * calculateBFRatio());
	}

	inline float getStun() {
		return stun - (stun * calculateBFRatio());
	}

	inline float getBlast() {
		return blast - (blast * calculateBFRatio());
	}

	inline float getHeat() {
		return heat - (heat * calculateBFRatio());
	}

	inline float getCold() {
		return cold - (cold * calculateBFRatio());
	}

	inline float getAcid() {
		return acid - (acid * calculateBFRatio());
	}

	inline float getLightSaber() {
		return lightSaber - (lightSaber * calculateBFRatio());
	}

	float getArmorResist(int resistType);

	inline uint32 getHealthWounds() {
		return healthWounds;
	}

	inline uint32 getStrengthWounds() {
		return strengthWounds;
	}

	inline uint32 getConstitutionWounds() {
		return constitutionWounds;
	}

	inline uint32 getActionWounds() {
		return actionWounds;
	}

	inline uint32 getQuicknessWounds() {
		return quicknessWounds;
	}

	inline uint32 getStaminaWounds() {
		return staminaWounds;
	}

	inline uint32 getMindWounds() {
		return mindWounds;
	}

	inline uint32 getFocusWounds() {
		return focusWounds;
	}

	inline uint32 getWillpowerWounds() {
		return willpowerWounds;
	}

	inline uint32 getShockWounds() {
		return shockWounds;
	}

	inline uint32 getHAMUpdateCounter() {
		return hamUpdateCounter;
	}

	inline uint32 getNewHAMUpdateCounter(int cnt) {
			return hamUpdateCounter += cnt;
	}

	inline uint32 getHAMMaxUpdateCounter() {
		return hamMaxUpdateCounter;
	}

	inline uint32 getNewHAMMaxUpdateCounter(int cnt) {
			return hamMaxUpdateCounter += cnt;
	}

	inline uint32 getHAMBaseUpdateCounter() {
		return hamBaseUpdateCounter;
	}

	inline uint32 getNewHAMBaseUpdateCounter(int cnt) {
			return hamBaseUpdateCounter += cnt;
	}

	inline uint32 getHAMEncumbUpdateCounter() {
		return hamEncumbUpdateCounter;
	}

	inline uint32 getNewHAMEncumbUpdateCounter(int cnt) {
			return hamEncumbUpdateCounter += cnt;
	}

	inline uint32 getWoundsUpdateCounter() {
		return woundsUpdateCounter;
	}

	inline uint32 getNewWoundsUpdateCounter(int upd) {
		return woundsUpdateCounter += upd;
	}

	inline uint8 getPosture() {
		return postureState;
	}

	inline string& getMood() {
		return mood;
	}

	inline uint8 getMoodID() {
		return moodid;
	}

	inline uint64 getStateBitmask() {
		return stateBitmask;
	}

	inline float getHeight() {
		return height;
	}

	inline bool hasStates() {
		return stateBitmask != 0;
	}

	inline bool hasWounds() {
		return (healthWounds > 0 || actionWounds > 0 || mindWounds > 0);
	}

	inline bool hasShockWounds() {
		return (shockWounds > 0);
	}

	inline bool hasState(uint64 state) {
		return stateBitmask & state;
	}

	inline int getAccuracy() {
		return accuracy;
	}

	inline float getSpeed() {
		return speed;
	}

	inline float getAcceleration() {
		return acceleration;
	}

	inline bool isOvert() {
		return pvpStatusBitmask & OVERT_FLAG;
	}

	inline bool isAgressive() {
		return pvpStatusBitmask & AGGRESSIVE_FLAG;
	}

	inline bool isTEF() {
		return pvpStatusBitmask & TEF_FLAG;
	}

	inline bool isPlayerFlag() {
		return pvpStatusBitmask & PLAYER_FLAG;
	}

	inline bool isEnemy() {
		return pvpStatusBitmask & ENEMY_FLAG;
	}

	inline uint32 getFaction() {
		return faction;
	}

	inline bool isRebel() {
		return faction == String::hashCode("rebel");
	}

	inline bool isNeutral() {
		return faction == 0;
	}

	inline bool isImperial() {
		return faction == String::hashCode("imperial");
	}

	inline uint32 getPvpStatusBitmask() {
		return pvpStatusBitmask;
	}

	inline uint8 getFactionRank() {
		return factionRank;
	}

	inline void setCreatureBitmask(uint32 bit) {
		creatureBitmask = bit;
	}

	inline uint32 getCreatureBitmask() {
		return creatureBitmask;
	}

	uint64 getTargetID();

	uint64 getWeaponID();

	inline uint64 getDefenderID() {
		return defenderID;
	}

	inline uint32 getDefenderUpdateCounter() {
		return defenderUpdateCounter;
	}

	inline uint32 getNewDefenderUpdateCounter(int cnt) {
		return defenderUpdateCounter += cnt;
	}

	inline uint32 getNewSkillModsCounter(int cnt) {
		return skillModsCounter += cnt;
	}

	inline uint32 getSkillModsCounter() {
		return skillModsCounter;
	}

	inline uint32 getNewSkillModBonusCounter(int cnt) {
		return skillModBonusCounter += cnt;
	}

	inline uint32 getSkillModBonusCounter() {
		return skillModBonusCounter;
	}

	inline uint32 getLevel() {
		return level;
	}

	inline uint32 getHealthEncumbrance() {
		return healthEncumbrance;
	}

	inline uint32 getActionEncumbrance() {
		return actionEncumbrance;
	}

	inline uint32 getMindEncumbrance() {
		return mindEncumbrance;
	}

	inline string& getCreatureFaction() {
		return creatureFaction;
	}

	inline int getXP() {
		return xp;
	}

	inline int isHealer() {
		return healer;
	}

	inline int isPack() {
		return pack;
	}

	inline int isHerd() {
		return herd;
	}

	inline int isKiller() {
		return killer;
	}

	inline int isStalker() {
		return stalker;
	}

	inline int isAggressive() {
		return aggressive;
	}

	inline string& getBehaviorScript() {
		return behaviorScript;
	}


	//Harvesting stuff
	inline string& getMeatType() {
		return meatType;
	}

	inline string& getBoneType() {
		return boneType;
	}

	inline string& getHideType() {
		return hideType;
	}

	inline bool hasOrganics(){
		return ((hideMax + boneMax + meatMax) > 0);
	}

	inline int getMilk() {
		return milk;
	}

	inline int getHideMax() {
		return hideMax;
	}

	inline int getBoneMax() {
		return boneMax;
	}

	inline int getMeatMax() {
		return meatMax;
	}

	inline string& getLootGroup() {
		return lootGroup;
	}

	inline float getTame() {
		return tame;
	}

	//combat related

	inline float getInternalNPCDamageModifier() {
		return internalNPCDamageModifier;
	}

	inline string& getCreatureWeapon() {
		return creatureWeapon;
	}
	inline string& getCreatureWeaponName() {
		return creatureWeaponName;
	}
	inline string& getCreatureWeaponClass() {
		return creatureWeaponClass;
	}
	inline string& getCreatureWeaponTemp() {
		return creatureWeaponTemp;
	}
	inline int getCreatureWeaponEquipped() {
		return creatureWeaponEquipped;
	}
	inline int getCreatureWeaponMinDamage() {
		return creatureWeaponMinDamage;
	}
	inline int getCreatureWeaponMaxDamage() {
		return creatureWeaponMaxDamage;
	}
	inline float getCreatureWeaponAttackSpeed() {
		return creatureWeaponAttackSpeed;
	}
	inline string& getCreatureWeaponDamageType() {
		return creatureWeaponDamageType;
	}
	inline string& getCreatureWeaponArmorPiercing() {
		return creatureWeaponArmorPiercing;
	}

	//behavior
	inline string& getCreatureBehaviorScript() {
		return behaviorScript;
	}

	// modifiers
	inline int getWeaponSpeedModifier() {
		return weaponSpeedModifier;
	}

	inline Inventory* getInventory() {
		return inventory;
	}

	inline Container* getLootContainer() {
		return (Container*)lootContainer;
	}

	// entertainer
	inline void addListener(CreatureObject* creature) {
		listeners.put(creature);
	}

	inline void addWatcher(CreatureObject* creature) {
		watchers.put(creature);
	}

	inline void removeListener(CreatureObject* creature) {
		listeners.drop(creature);
		/*if (!listeners.drop(creature)); {
			cout << "SortedVector ERROR: object " << creature << " not found\n";

			for (int i = 0; i < listeners.size(); ++i) {
				CreatureObject* obj = listeners.get(i);
				cout << obj << "(0x" << obj->getObjectID() << ") ";
			}

			cout << "\n";
		}*/
	}

	inline void removeWatcher(CreatureObject* creature) {
		watchers.drop(creature);
		/*if (!watchers.drop(creature)); {
			cout << "SortedVector ERROR: object " << creature << " not found\n";

			for (int i = 0; i < watchers.size(); ++i) {
				CreatureObject* obj = watchers.get(i);
				cout << obj << "(0x" << obj->getObjectID() << ") ";
			}

			cout << "\n";
		}*/
	}

	inline string& getPerformanceAnimation() {
		return performanceAnimation;
	}

	inline uint32 getPerformanceCounter() {
		return performanceCounter;
	}

	inline int getInstrumentID() {
		return instrumentID;
	}

	inline string& getPerformanceName() {
		return performanceName;
	}

	inline uint32 getSkillBoxesUpdateCounter() {
		return skillBoxesUpdateCounter++;
	}

	inline void setAccuracy(int acc) {
		accuracy = acc;
	}


	//Harvesting stuff
	inline void setMeatType(const string& meat) {
		meatType = meat;
	}

	inline void setBoneType(const string& bone) {
		boneType = bone;
	}

	inline void setHideType(const string& hide) {
		hideType = hide;
	}

	inline void setMilk(int milkamt) {
		milk = milkamt;
	}

	inline void setHideMax(int hidemax) {
		hideMax = hidemax;
	}

	inline void setBoneMax(int bonemax) {
		boneMax = bonemax;
	}

	inline void setMeatMax(int meatmax) {
		meatMax = meatmax;
	}

	inline void setLootGroup(const string& lootgroup) {
		lootGroup = lootgroup;
	}

	inline void setTame(float tme) {
		tame = tme;
	}

	//Combat & Weapon
	inline void setInternalNPCDamageModifier(float indm) {
		internalNPCDamageModifier = indm;
	}

	inline void setCreatureWeapon(const string& wpon) {
		creatureWeapon = wpon;
	}

	inline void setCreatureWeaponName(const string& weaponname) {
		creatureWeaponName = weaponname;
	}

	inline void setCreatureWeaponTemp(const string& weapontemp) {
		creatureWeaponTemp = weapontemp;
	}

	inline void setCreatureWeaponClass(const string& weaponclass) {
		creatureWeaponClass = weaponclass;
	}

	inline void setCreatureWeaponEquipped(int weaponeq) {
		creatureWeaponEquipped = weaponeq;
	}

	inline void setCreatureWeaponMinDamage(int weaponmindam) {
		creatureWeaponMinDamage = weaponmindam;
	}

	inline void setCreatureWeaponMaxDamage(int weaponmaxdam) {
		creatureWeaponMaxDamage = weaponmaxdam;
	}

	inline void setCreatureWeaponAttackSpeed(float weaponattackspeed) {
		creatureWeaponAttackSpeed = weaponattackspeed;
	}

	inline void setCreatureWeaponDamageType(const string& weapondamtype) {
		creatureWeaponDamageType = weapondamtype;
	}

	inline void setCreatureWeaponArmorPiercing(const string& weaponarmorpiercing) {
		creatureWeaponArmorPiercing = weaponarmorpiercing;
	}

	inline void setBehaviorScript(const string& behaviorscript) {
		behaviorScript = behaviorscript;
	}

	inline void setCreatureFaction(const string& cfac) {
		creatureFaction = cfac;
	}

	inline void setXP(int xxp) {
		xp = xxp;
	}

	inline void setHealer(int heale) {
		healer = heale;
	}

	inline void setPack(int pck) {
		pack = pck;
	}

	inline void setHerd(int hrd) {
		herd = hrd;
	}

	inline void setStalker(int stlker) {
		stalker = stlker;
	}

	inline void setKiller(int kller) {
		killer = kller;
	}

	inline void setAggressive(int agg) {
		aggressive = agg;
	}

	//Entertainer
	inline void addEntertainerBuffDuration(int performanceType, float duration) {
		switch(performanceType) {
		case PerformanceType::DANCE:
			danceBuffDuration += duration;
			if(danceBuffDuration > (120.0f + (10.0f/60.0f)) ) // 2 hrs 10 seconds
				danceBuffDuration = (120.0f + (10.0f/60.0f)); // 2hrs 10 seconds
			break;
		case PerformanceType::MUSIC:
			musicBuffDuration += duration;
			if(musicBuffDuration > (120.0f + (10.0f/60.0f)) ) // 2 hrs 10 seconds
				musicBuffDuration = (120.0f + (10.0f/60.0f)); // 2hrs 10 seconds
			break;
		}
	}

	inline void addEntertainerBuffStrength(int performanceType, float strength) {
		switch(performanceType) {
		case PerformanceType::DANCE:
			danceBuffStrength += strength;
			if(danceBuffStrength > 125.0f)
				danceBuffStrength = 125.0f; // 125% cap
			break;
		case PerformanceType::MUSIC:
			musicBuffStrength += strength;
			if(musicBuffStrength > 125.0f)
				musicBuffStrength = 125.0f; // 125% cap
			break;
		}
	}
	inline void setEntertainerBuffDuration(int performanceType, float duration) {
		switch(performanceType) {
		case PerformanceType::DANCE:
			danceBuffDuration = duration;
			break;
		case PerformanceType::MUSIC:
			musicBuffDuration = duration;
			break;
		}
	}

	inline void setEntertainerBuffStrength(int performanceType, float strength) {
		switch(performanceType) {
		case PerformanceType::DANCE:
			danceBuffStrength = strength;
			break;
		case PerformanceType::MUSIC:
			musicBuffStrength = strength;
			break;
		}
	}

	inline float getEntertainerBuffDuration(int performanceType) {
		switch(performanceType) {
		case PerformanceType::DANCE:
			return danceBuffDuration;
			break;
		case PerformanceType::MUSIC:
			return musicBuffDuration;
			break;
		}
		return 0.0f;
	}

	inline float getEntertainerBuffStrength(int performanceType) {
		switch(performanceType) {
		case PerformanceType::DANCE:
			return danceBuffStrength;
			break;
		case PerformanceType::MUSIC:
			return musicBuffStrength;
			break;
		}
		return 0.0f;
	}

	inline void setPerformanceAnimation(const string& performanceanimation) {
		performanceAnimation = performanceanimation;
	}

	inline void setPerformanceCounter(uint32 performancecounter) {
		performanceCounter = performancecounter;
	}

	inline void setInstrumentID(int value) {
		instrumentID = value;
	}

	inline void setPerformanceName(const string& performancename) {
		performanceName = performancename;
	}

	inline void setDancing(bool value) {
		doDancing = value;
	}

	inline void setPlayingMusic(bool value) {
		doPlayingMusic = value;
	}

	inline bool isDancing() {
		return doDancing;
	}

	inline bool isPlayingMusic() {
		return doPlayingMusic;
	}

	inline void setWatchID(uint64 oid) {
		watchID = oid;
	}

	inline void setListenID(uint64 oid) {
		listenID = oid;
	}

	inline void setWatching(bool value) {
		doWatching = value;
	}

	inline void setListening(bool value) {
		doListening = value;
	}

	inline bool isWatching() {
		return doWatching;
	}

	inline bool isListening() {
		return doListening;
	}

	inline uint64 getWatchID() {
		return watchID;
	}

	inline uint64 getListenID() {
		return listenID;
	}

	inline bool isSittingOnObject() {
		return sittingOnObject;
	}

	inline void setSittingOnObject(bool value) {
		sittingOnObject = value;
	}

	inline void setGuild(Guild* gld) {
		guild = gld;
	}

	inline void setActionCounter(uint32 actioncntr) {
		actionCounter = actioncntr;
	}

	inline void setLevel(uint32 lvl) {
		level = lvl;
	}

	inline Guild* getGuild() {
		return guild;
	}

	inline uint32 getGuildID() {
		if (guild != NULL)
			return guild->getGuildID();
		else
			return 0;
	}

	inline string& getGuildName() {
		return guild->getGuildName();
	}

	inline bool isGuilded() {
		return guild != NULL;
	}

	inline void setCashCredits(int credits) {
		cashCredits = credits;
	}

	inline void setBankCredits(int credits) {
		bankCredits = credits;
	}

	inline float getTerrainNegotiation() {
		return (float(getSkillMod("slope_move"))/float(100));
	}

	void explode(int level = 1, bool destroy = true);

	/*
	 Clean up later
	*/
	void deactivateWoundTreatment();
	void activateWoundTreatment();

	void deactivateInjuryTreatment();
	void activateInjuryTreatment();

	void deactivateStateTreatment();
	void activateStateTreatment();

	void deactivateConditionTreatment();
	void activateConditionTreatment();

	bool canTreatWounds() {
		return doWoundTreatment;
	}

	bool canTreatInjuries() {
		return doInjuryTreatment;
	}

	bool canTreatStates() {
		return doStateTreatment;
	}

	bool canTreatConditions() {
		return doConditionTreatment;
	}

	int getMedicalFacilityRating();

	inline void say(unicode& message, uint32 moodid = 0, uint32 mood2 = 0) {
		ChatManager * chatManager = this->getZone()->getChatManager();
		chatManager->broadcastMessage(_this, message, this->getTargetID(),moodid, mood2);
	}

	inline void say(const string& file, const string& str, StfParameter * param, uint32 moodid = 0, uint32 mood2 = 0) {
		ChatManager * chatManager = this->getZone()->getChatManager();
		chatManager->broadcastMessage(_this, file, str, param, this->getTargetID(),moodid, mood2);
	}

	friend class CombatManager;
	friend class SkillManager;

	friend class CreatureObjectMessage1;
	//friend class CreatureObjectMessage3;
	friend class CreatureObjectMessage4;
	friend class CreatureObjectMessage6;
	friend class PlayerObjectMessage9;

	friend class CreatureObjectDeltaMessage1;
	friend class CreatureObjectDeltaMessage3;
	friend class CreatureObjectDeltaMessage4;
	friend class CreatureObjectDeltaMessage6;
	friend class PlayerObjectDeltaMessage9;

	friend class ObjectControllerMessage;
	friend class PostureMessage;

	friend class UpdatePVPStatusMessage;

};

#endif /*CREATUREOBJECTIMPLEMENTATION_H_*/
