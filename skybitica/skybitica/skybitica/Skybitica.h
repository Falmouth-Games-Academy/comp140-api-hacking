#pragma once
#include "skse/PapyrusNativeFunctions.h"
#include "HabiticaConnector.h"

namespace SkybiticaNamespace
{
	//! Adds a quest to Habitica
	/*!
	  An SKSE Plugin function that will be able to be called from Papyrus.
	  Adds the quest with the given name and ID to Habitica.
	*/
	void AddQuestToHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID);

	//! Completes a quest on Habitica
	/*!
	  An SKSE Plugin function that will be able to be called from Papyrus.
	  Completes the quest with the given ID on Habitica.
	*/
	void CompleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questID);

	//! Deletes a quest from Habitica
	/*!
	  An SKSE Plugin function that will be able to be called from Papyrus.
	  Deletes the quest with the given ID from Habitica.
	*/
	void DeleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questID);

	//! Returns the results of a quest associated with a specific ID
	/*!
	  Returns the response code received from the last HTTP request associated
	  with the given quest ID
	*/
	UInt32 GetRequestResult(StaticFunctionTag *base, BSFixedString questID);

	//! Not my function - from template for SKSE project
	bool RegisterFuncs(VMClassRegistry* registry);
}
