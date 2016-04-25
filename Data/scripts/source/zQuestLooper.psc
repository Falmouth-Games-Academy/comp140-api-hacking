ScriptName zQuestLooper extends Quest

FormList Property quests auto
import Skybitica

Event OnInit()
	Int i
	While i < quests.GetSize()
		Quest questToBeChecked = quests.GetAt(i) as Quest
		If questToBeChecked.IsRunning() && !questToBeChecked.IsCompleted()
			string questID = questToBeChecked.GetId()
			string questname = questToBeChecked.GetName()
			Debug.Notification(AddQuestToHabitica(questName, questID))
			Debug.Notification("'" + questname + "'" + "added to Habitica Todo List!")
			CompleteQuestInHabitica(questToBeChecked.getID())
		EndIf
		i += 1
	EndWhile
EndEvent