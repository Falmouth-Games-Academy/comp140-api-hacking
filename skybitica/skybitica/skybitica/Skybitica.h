#include "skse/PapyrusNativeFunctions.h"

namespace SkybiticaNamespace
{
	float AddQuestToHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID);

	void CompleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questName);

	bool RegisterFuncs(VMClassRegistry* registry);
}
