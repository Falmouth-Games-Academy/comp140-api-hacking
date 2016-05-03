#pragma once
#include "skse/PapyrusNativeFunctions.h"
#include "HabiticaConnector.h"

namespace SkybiticaNamespace
{
	void AddQuestToHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID);

	void CompleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID);

	void DeleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questID);

	UInt32 GetRequestResult(StaticFunctionTag *base, BSFixedString questID);

	bool RegisterFuncs(VMClassRegistry* registry);
}
