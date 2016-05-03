#include "Skybitica.h"

namespace SkybiticaNamespace {

	HabiticaConnector habiticaConnector;

	UInt32 AddQuestToHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID)
	{
		return habiticaConnector.addTask(convertToWideString(questName.data), convertToWideString(questID.data));
	}

	UInt32 CompleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID)
	{
		return  habiticaConnector.completeTask(convertToWideString(questName.data), convertToWideString(questID.data));
	}

	bool HabiticaRequestDone(StaticFunctionTag *base)
	{
		return habiticaConnector.requestTaskDone();
	}

	bool RegisterFuncs(VMClassRegistry* registry) {
		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, UInt32, BSFixedString, BSFixedString>("AddQuestToHabitica", "Skybitica", SkybiticaNamespace::AddQuestToHabitica, registry));
		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, UInt32, BSFixedString, BSFixedString>("CompleteQuestInHabitica", "Skybitica", SkybiticaNamespace::CompleteQuestInHabitica, registry));
		registry->RegisterFunction(
			new NativeFunction0 <StaticFunctionTag, bool>("HabiticaRequestDone", "Skybitica", SkybiticaNamespace::HabiticaRequestDone, registry));

		return true;
	}
} 
