mottbull = Creature:new {
	templateType = NPCCREATURE,
	gameObjectType = 1024,
	objectName = "mottbull",
	socialGroup = "Mott",
	pvpFaction = "",
	faction = "",
	level = 11,
	chanceHit = 0.290000,
	damageMin = 130,
	damageMax = 140,
	range = 0,
	baseXp = 430,
	baseHAM = 900,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "meat_herbivore",
	meatAmount = 100,
	hideType = "hide_leathery",
	hideAmount = 65,
	boneType = "bone_mammal",
	boneAmount = 40,
	milk = 0.000000,
	tamingChance = 0.250000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK,
	diet = CARNIVORE,

	templates = {},
	weapons = {},
	attacks = {
		{"intimidationattack","intimidationChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(mottbull, "mottbull")
