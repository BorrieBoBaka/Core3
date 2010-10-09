corellian_butterfly_defender = Creature:new {
	templateType = NPCCREATURE,
	gameObjectType = 1024,
	objectName = "corellian butterfly defender",
	socialGroup = "Cor. Butterfly",
	pvpFaction = "",
	faction = "",
	level = 18,
	chanceHit = 0.320000,
	damageMin = 210,
	damageMax = 220,
	range = 25,
	baseXp = 1257,
	baseHAM = 2200,
	armor = 0,
	resists = {0,15,-1,-1,-1,-1,-1,-1,-1},
	meatType = "meat_insect",
	meatAmount = 16,
	hideType = "hide_scale",
	hideAmount = 16,
	boneType = "bone_",
	boneAmount = 0,
	milk = 0.000000,
	tamingChance = 0.250000,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE,
	creatureBitmask = PACK + HERD,
	diet = CARNIVORE,

	templates = {},
	weapons = {},
	attacks = {
		{"intimidationattack","intimidationChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(corellian_butterfly_defender, "corellian_butterfly_defender")
