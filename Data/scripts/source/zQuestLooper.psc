ScriptName zQuestLooper extends Quest

import Skybitica

; List of all named Skyrim quests defined in Creation Kit
FormList Property quests auto
; List for quests that are running so request doesn't get sent on all
Formlist Property runningQuests auto
; List for keeping track of which quests have had requests sent for them
Formlist Property pendingQuests auto

; Bool to indicate whether all http request results have been checked
; Start at true as their isn't any prior requests
bool upToDate = true

Event OnInit()
	; Script will run whenever player opens journal
	RegisterForMenu("Journal Menu")
EndEvent

Event OnMenuOpen(string menuName)
	GetRunningQuests()
	ConnectQuestsToHabitica() 
EndEvent

; Check results of quests and remove quests from runningQuests where appropriate
; This is the only place that quests should be removed from runningQuests
Event OnUpdate()
	Int i = 0
	While i < pendingQuests.GetSize()
		Quest pendingQuest = pendingQuests.GetAt(i) as Quest

		; Gets the http response code returned by the request, will be 0 if request not performed or finished
		Int response = GetRequestResult(pendingQuest.GetId())

		If httpRequestSucceeded(response)
			Debug.Notification("'" + pendingQuest.GetName() + "'" + " successfully updated on Habitica!")
			If !pendingQuest.IsRunning()
				; Don't want quest to be removed if it's still running, as we need to check if it's complete
				runningQuests.RemoveAddedForm(pendingQuest)
			EndIf
		ElseIf !AlreadyOnTodoList(response)		; Don't display message if problem is that it's already added
			Debug.Notification("'" + pendingQuest.GetName() + "'" + " failed to update on Habitica. Response code: " + response)
		Endif
		i += 1
	EndWhile

	; Removes all quests from pendingQuests
	pendingQuests.Revert()

	; Enables requests to be sent again
	upToDate = true
EndEvent

; Add running quests to the list of running quests so that they can be added to Habitica and checked
Function GetRunningQuests()
	Int i = 0
	While i < quests.GetSize()
		Quest questToBeChecked = quests.GetAt(i) as Quest
		; 2nd two checks as some quests still marked as running if completed, and some quests marked as running before they are in journal.
		If questToBeChecked.IsRunning() && !questToBeChecked.IsCompleted() && questToBeChecked.getStage() != 0
			; Duplicate forms already aren't added automatically
			runningQuests.AddForm(quests.GetAt(i))
		EndIf
		i += 1
	EndWhile
EndFunction

Function ConnectQuestsToHabitica() 
	; Only runs if previous results have been checked
	If upToDate
		Int i = 0
		While i < runningQuests.getSize()
			Quest questToBeChecked = runningQuests.GetAt(i) as Quest
			
			; Delete stopped quests that aren't completed from Habitica
			; Not reliable! Skyrim marks some quests as complete if failed, and some quests still marked as running if failed...
			If !questToBeChecked.IsCompleted() && (questToBeChecked.IsStopped() || questToBeChecked.IsStopping())
				DeleteQuestInHabitica(questToBeChecked.GetId())

			; Complete completed quests on Habitica Todo list
			ElseIf questToBeChecked.isCompleted()
				CompleteQuestInHabitica(questToBeChecked.GetName(), questToBeChecked.GetId())

			; Add running quests to Habitica Todo list
			ElseIf questToBeChecked.IsRunning()
				AddQuestToHabitica(questToBeChecked.GetName(), questToBeChecked.GetId())
			EndIf

			pendingQuests.AddForm(runningQuests.GetAt(i))
			i += 1
		EndWhile

		upToDate = false
		; Checks the results after 10 seconds, should be enough for http requests to complete
		RegisterForSingleUpdate(10)	
	EndIf
EndFunction

bool Function HttpRequestSucceeded(int responseCode)
	If responseCode == 200		;http response code for success
		return true
	Else
		return false
	Endif
EndFunction

; Returns true if already on Habitica todo list
bool Function AlreadyOnTodoList(int responseCode)
	If responseCode == 409		;response code returned if item already exists
		return true
	Else
		return false
	Endif
EndFunction