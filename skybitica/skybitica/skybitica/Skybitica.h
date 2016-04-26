#pragma once
#include "skse/PapyrusNativeFunctions.h"
#include "HabiticaConnector.h"

namespace SkybiticaNamespace
{
	UInt32 AddQuestToHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID);

	UInt32 CompleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID);

	bool RegisterFuncs(VMClassRegistry* registry);
}
