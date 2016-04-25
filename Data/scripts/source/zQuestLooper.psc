ScriptName zQuestLooper extends Quest

FormList Property quests auto
import Skybitica

Event OnInit()
	Int i
	While i < quests.GetSize()
		Quest questToBeChecked = quests.GetAt(i) as Quest
		if questToBeChecked.IsRunning() && !questToBeChecked.IsCompleted()
			string questID = questToBeChecked.GetId()
			string questname = questToBeChecked.GetName()
			Debug.Notification(AddQuest(questName))
			Debug.Notification("'" + questname + "'" + "added to Habitica Todo List!")
		EndIf
		i += 1
	EndWhile
EndEvent