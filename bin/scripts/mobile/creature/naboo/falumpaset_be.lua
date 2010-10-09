falumpaset_be = Creature:new {
	templateType = NPCCREATURE,
	gameObjectType = 1024,
	objectName = "falumpaset be",
	socialGroup = "Falumpaset",
	pvpFaction = "",
	faction = "",
	level = 1,
	chanceHit = 0.200000,
	damageMin = 30,
	damageMax = 40,
	range = 0,
	baseXp = 30,
	baseHAM = 50,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "meat_",
	meatAmount = 0,
	hideType = "hide_",
	hideAmount = 0,
	boneType = "bone_",
	boneAmount = 0,
	milk = 0.000000,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = HERD,
	diet = CARNIVORE,

	templates = {},
	weapons = {},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(falumpaset_be, "falumpaset_be")
