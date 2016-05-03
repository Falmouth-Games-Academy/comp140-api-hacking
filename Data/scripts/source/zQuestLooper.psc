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
			; Duplicate forms already aren't added automatically
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
			Int response = CompleteQuestInHabitica(questName, questID)
			If httpRequestSucceeded(response)
				Debug.Notification("'" + questname + "'" + " complete!")
				runningQuests.RemoveAddedForm(questToBeChecked)
			Else
			Debug.Notification("'" + questname + "'" + " failed to complete on Habitica. Response code: " + response)
			Endif

		Elseif questToBeChecked.IsRunning()
			Int response = AddQuestToHabitica(questName, questID)
			If httpRequestSucceeded(response)
				Debug.Notification("'" + questname + "'" + "added to Habitica Todo List!")
			Else
				Debug.Notification("'" + questname + "'" + " failed to be added to Habitica. Response code: " + response)
			Endif
			
		Elseif questToBeChecked.IsStopped()
			Int response = DeleteQuestInHabitica(questID)
			If httpRequestSucceeded(response)
				Debug.Notification("'" + questname + "'" + " removed from Habitica Todo List.")
				runningQuests.RemoveAddedForm(questToBeChecked)
			Else
				Debug.Notification("'" + questname + "'" + " failed to be removed from Habitica. Response code: " + response)
			Endif

		Endif
		i += 1

	EndWhile
EndFunction

bool Function httpRequestSucceeded(int responseCode)
	If responseCode == 200
		return true
	Else
		return false
	Endif
EndFunction