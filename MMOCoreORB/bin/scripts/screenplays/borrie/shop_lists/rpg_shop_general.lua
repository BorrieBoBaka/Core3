rpg_shop_general = {
	categories = {"Pistols", "Medicine"},
	manifest = {
		["Pistols"] = {
			minItems = 1;
			items = {
				{template = "object/weapon/ranged/pistol/shared_pistol_dl44.iff", cost = 250, max = 10, chance = 100 },
				{template = "object/weapon/ranged/pistol/shared_pistol_fwg5.iff", cost = 250, max = 10, chance = 100 },
			}
		},
		["Armor"] = {
			minItems = 2;
			items = {
				{template = "object/tangible/wearables/armor/chitin/shared_armor_chitin_s01_helmet.iff", cost = 250, max = 10, chance = 100 },
				{template = "object/tangible/wearables/armor/composite/shared_armor_composite_chest_plate.iff", cost = 250, max = 10, chance = 100 },
			}
		},
	}	
}