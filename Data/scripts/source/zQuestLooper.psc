ScriptName zQuestLooper extends Quest

FormList Property quests auto
import Skybitica

Event OnInit()
	Int i
	While i < quests.GetSize()
		Quest questToBeChecked = quests.GetAt(i) as Quest
		string questID = questToBeChecked.GetId()
		string questname = questToBeChecked.GetName()


		If questToBeChecked.isCompleted()
			Debug.Notification("'" + questname + "'" + "complete!")
			Debug.Notification(CompleteQuestInHabitica(questName, questID))
		Elseif questToBeChecked.IsRunning()
			Debug.Notification(AddQuestToHabitica(questName, questID))
			Debug.Notification("'" + questname + "'" + "added to Habitica Todo List!")
			AddQuestToHabitica(questName, questID)
		EndIf

		i += 1
	EndWhile
EndEvent