rpg_shopkeeper= ConvoTemplate:new {
  initialScreen = "greeting",
  templateType = "Lua",
  luaClassHandler = "rpg_shopkeeper_convo_handler",
  screens = {}
}

greeting = ConvoScreen:new {
  id = "greeting",
  customDialogText = "Hello there! I have many fine wares to sell. Would you like to look at my inventory?",
  stopConversation = "false",
  options = {
      {"Let me see what you've got.", "shop"},
      {"Not right now.", "abort"},
  }
}
rpg_shopkeeper:addScreen(greeting)

shop = ConvoScreen:new {
  id = "shop",
  customDialogText = "All prices are final. Have a look.",
  stopConversation = "true",
  options = {
  }
}
rpg_shopkeeper:addScreen(shop)

abort = ConvoScreen:new {
  id = "abort",
  customDialogText = "Come back anytime!",
  stopConversation = "true",
  options = {
  }
}
rpg_shopkeeper:addScreen(abort)

addConversationTemplate("rpg_shopkeeper", rpg_shopkeeper);
