-- untitled script component

require("conversation.core")
local dcLib = require("conversation.dialogue_component")

-- BOP_GENERATED_INCLUDES_BEGIN

-- BOP_GENERATED_INCLUDES_END

local untitled = dcLib.ScriptDialogueComponent:New()

function untitled:InitConversationScript() end

function untitled:OnActivate()
	self:ActivateConversationScript() -- Required since defining OnActivate in the metaclass doesn't seem to work.

	Debug.Log(
		"[untitled] ScriptComponent activated on entity: '"
			.. GameEntityContextRequestBus.Broadcast.GetEntityName(self.entityId)
			.. "'"
	)
end

function untitled:OnDeactivate()
	self:DeactivateConversationScript() -- Required since defining OnActivate in the metaclass doesn't seem to work.

	Debug.Log(
		"[untitled] ScriptComponent deactivated on entity: '"
			.. GameEntityContextRequestBus.Broadcast.GetEntityName(self.entityId)
			.. "'"
	)
end

-- BOP_GENERATED_FUNCTIONS_BEGIN

-- BOP_GENERATED_FUNCTIONS_END

return untitled
