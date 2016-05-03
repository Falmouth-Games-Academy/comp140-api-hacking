ScriptName zQuestLooper extends Quest

import Skybitica

; List of all named Skyrim quests defined in Creation Kit
FormList Property quests auto
Formlist Property runningQuests auto


Event OnInit()
	; Script will run whenever player opens journal
	RegisterForMenu("Journal Menu")
EndEvent

Event OnMenuOpen(string menuName)
	GetRunningQuests()
	ConnectQuestsToHabitica()
EndEvent

Function GetRunningQuests()
	Int i = 0
	While i < quests.GetSize()
		Quest questToBeChecked = quests.GetAt(i) as Quest
		If questToBeChecked.IsRunning() && !questToBeChecked.IsCompleted()
			; Duplicate forms aren't added automatically
			runningQuests.AddForm(quests.GetAt(i))
		Endif
		i += 1
	EndWhile
EndFunction

Function ConnectQuestsToHabitica()
	Int i = 0
	While i < runningQuests.getSize()
		Quest questToBeChecked = runningQuests.GetAt(i) as Quest
		string questID = questToBeChecked.GetId()
		string questname = questToBeChecked.GetName()

		If questToBeChecked.isCompleted()
			Debug.Notification("'" + questname + "'" + "complete!")
			Debug.Notification(CompleteQuestInHabitica(questName, questID))
			runningQuests.RemoveAddedForm(questToBeChecked)
		Elseif questToBeChecked.IsRunning()
			Debug.Notification(AddQuestToHabitica(questName, questID))
			Debug.Notification("'" + questname + "'" + "added to Habitica Todo List!")
			AddQuestToHabitica(questName, questID)
		Elseif questToBeChecked.IsStopped()
			; delete from habitica
		Endif
		i += 1

	EndWhile
EndFunction