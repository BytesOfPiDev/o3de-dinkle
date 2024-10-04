-- bot script component

require("conversation.core")
local dcLib = require("conversation.dialogue_component")

-- BOP_GENERATED_INCLUDES_BEGIN

-- BOP_GENERATED_INCLUDES_END

local bot = dcLib.ScriptDialogueComponent:New()

function bot:InitConversationScript() end

function bot:OnActivate()
	self:ActivateConversationScript() -- Required since defining OnActivate in the metaclass doesn't seem to work.

	Debug.Log(
		"[bot] ScriptComponent activated on entity: '"
			.. GameEntityContextRequestBus.Broadcast.GetEntityName(self.entityId)
			.. "'"
	)
end

function bot:OnDeactivate()
	self:DeactivateConversationScript() -- Required since defining OnActivate in the metaclass doesn't seem to work.

	Debug.Log(
		"[bot] ScriptComponent deactivated on entity: '"
			.. GameEntityContextRequestBus.Broadcast.GetEntityName(self.entityId)
			.. "'"
	)
end

-- BOP_GENERATED_FUNCTIONS_BEGIN

-- BOP_GENERATED_FUNCTIONS_END

return bot
