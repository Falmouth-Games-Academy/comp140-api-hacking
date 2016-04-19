ScriptName SkyrimTestScript extends Quest

FormList Property quests auto

Event OnInit()
	Quest questToBeChecked = quests.GetAt(5) as Quest
	string questID = questToBeChecked.GetId()
	string questname = questToBeChecked.GetName()
	Debug.Notification(questID)
	Debug.Notification(questname)
EndEvent