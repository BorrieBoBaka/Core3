rpg_shopkeeper_convo_handler = Object:new {
}
function rpg_shopkeeper_convo_handler:getNextConversationScreen(conversationTemplate, conversingPlayer, selectedOption)
    -- Assign the player to variable creature for use inside this function.
    local creature = LuaCreatureObject(conversingPlayer)
    -- Get the last conversation to determine whetehr or not we're  on the first screen
    local convosession = creature:getConversationSession()
    lastConversation = nil
    local conversation = LuaConversationTemplate(conversationTemplate)

    

    -- If there is a conversation open, do stuff with it
    if ( conversation ~= nil ) then
    -- check to see if we have a next screen
        if ( convosession ~= nil ) then
            local session = LuaConversationSession(convosession)
            if ( session ~= nil ) then
                lastConversationScreen = session:getLastConversationScreen()
            end
        end
        -- Last conversation was nil, so get the first screen
        if ( lastConversationScreen == nil ) then
            nextConversationScreen = conversation:getScreen("greeting")
        else
            -- Start playing the rest of the conversation based on user input
            local luaLastConversationScreen = LuaConversationScreen(lastConversationScreen)
            -- Set variable to track what option the player picked and get the option picked
            local optionLink = luaLastConversationScreen:getOptionLink(selectedOption)
            nextConversationScreen = conversation:getScreen(optionLink)
        end
    end
-- end of the conversation logic.
	if ( lastConversationScreen ~= nil ) then
		local luaLastConversationScreen = LuaConversationScreen(lastConversationScreen)
	end

    if(nextConversationScreen ~= nil) then
        local luaLastConversationScreen = LuaConversationScreen(lastConversationScreen)
        local optionData = luaLastConversationScreen:getOptionData(selectedOption)
        if(strlen(optionData) > 4) then
            if(strsub(optionData, 1, 4) == "$vnd") then
                CreatureObject(conversingPlayer):sendSystemMessage(optionData)
            end
        end
    end

    return nextConversationScreen
end

function rpg_shopkeeper_convo_handler:runScreenHandlers(conversationTemplate, conversingPlayer, conversingNPC, selectedOption, conversationScreen)
    -- Plays the screens of the conversation.
    local player = LuaSceneObject(conversingPlayer)
    local screen = LuaConversationScreen(conversationScreen)
    local screenID = screen:getScreenID()
    local pConvScreen = screen:cloneScreen()
    local clonedConversation = LuaConversationScreen(pConvScreen)


	--CreatureObject(conversingPlayer):sendSystemMessage("Screen: " .. screenID)
	
    --Customized Data
    local vendorThemeID = "general" --getQuestStatus(CreatureObject(conversingNPC):getObjectID() .. ":vendorTheme")
    local vendorTheme = rpgVendorThemeDirectory[vendorThemeID]
    local vendorListID = "shop_general" --getQuestStatus(CreatureObject(conversingNPC):getObjectID() .. ":vendorList")
    local vendorList = rpgVendorShopListDirectory[vendorListID]

    --Setting the initial greeting based on theme.
    if(screenID == "greeting") then
        clonedConversation:setCustomDialogText(vendorTheme.dialog.greeting)
    elseif(screenID == "abort") then
        clonedConversation:setCustomDialogText(vendorTheme.dialog.abort)
    elseif(screenID == "browse") then
        clonedConversation:setCustomDialogText(vendorTheme.dialog.browse)
    elseif(screenID == "items") then
        clonedConversation:setCustomDialogText(vendorTheme.dialog.items)
    elseif(screenID == "shop") then
        clonedConversation:setCustomDialogText(vendorTheme.dialog.startShopping)
    end

    --Displaying the items.
	
    if(screenID == "browse") then
        --We want to get all the categories available
        clonedConversation:removeAllOptions()
        for i = 1, #vendorList.categories, 1 do
            clonedConversation:addOptionWithData("$vnd:category:" .. i, vendorList.categories[i], "items")
        end
        clonedConversation:addOption("Nevermind.", "abort")
    elseif(screenID == "items") then
        clonedConversation:setCustomDialogText(vendorTheme.dialog.items)
        clonedConversation:removeAllOptions()
        for i = 1, #vendorList.manifest["Pistols"].items, 1 do
            local templateName = vendorList.manifest["Pistols"].items[i].template
            local objectName = getItemTemplateName(templateName)
            local price = vendorList.manifest["Pistols"].items[i].cost;
            clonedConversation:addOptionWithData("$vnd:item:" .. ":" .. price .. ":" .. templateName, objectName, "items")
        end
        clonedConversation:addOption("I'd rather look at something else.", "browse")		
    end


    return pConvScreen
end
