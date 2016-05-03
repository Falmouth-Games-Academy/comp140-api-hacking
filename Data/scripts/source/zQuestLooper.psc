ScriptName zQuestLooper extends Quest

import Skybitica

; List of all named Skyrim quests defined in Creation Kit
FormList Property quests auto
Formlist Property runningQuests auto
Formlist Property pendingQuests auto

bool upToDate = true

Event OnInit()
	; Script will run whenever player opens journal
	RegisterForMenu("Journal Menu")
EndEvent

Event OnMenuOpen(string menuName)
	GetRunningQuests()
	ConnectQuestsToHabitica() 
EndEvent

Event OnUpdate()
	Int i = 0
	While i < pendingQuests.GetSize()
		Quest pendingQuest = pendingQuests.GetAt(i) as Quest
		Int response = GetRequestResult(pendingQuest.GetId())
		If httpRequestSucceeded(response)
			Debug.Notification("'" + pendingQuest.GetName() + "'" + " successfully updated on Habitica!")
			runningQuests.RemoveAddedForm(pendingQuest)
		ElseIf !AlreadyOnTodoList(response)
			Debug.Notification("'" + pendingQuest.GetName() + "'" + " failed to update on Habitica. Response code: " + response)
		Endif
		i += 1
	EndWhile
	pendingQuests.Revert()
	upToDate = true
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
	If upToDate
		Int i = 0
		While i < runningQuests.getSize()
			Quest questToBeChecked = runningQuests.GetAt(i) as Quest
			If questToBeChecked.isCompleted()
				CompleteQuestInHabitica(questToBeChecked.GetName(), questToBeChecked.GetId())

			Elseif questToBeChecked.IsStopped()
				DeleteQuestInHabitica(questToBeChecked.GetId())

			Elseif questToBeChecked.IsRunning()
				AddQuestToHabitica(questToBeChecked.GetName(), questToBeChecked.GetId())
			Endif

			pendingQuests.AddForm(runningQuests.GetAt(i))
			i += 1
		EndWhile
		upToDate = false
		RegisterForSingleUpdate(10)	
	EndIf
EndFunction

bool Function HttpRequestSucceeded(int responseCode)
	If responseCode == 200
		return true
	Else
		return false
	Endif
EndFunction

bool Function AlreadyOnTodoList(int responseCode)
	If responseCode == 409
		return true
	Else
		return false
	Endif
EndFunction