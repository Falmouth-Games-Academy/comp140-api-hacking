#include "Skybitica.h"

namespace SkybiticaNamespace {

	HabiticaConnector habiticaConnector;

	void AddQuestToHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID)
	{
		habiticaConnector.addTask(convertToWideString(questName.data), convertToWideString(questID.data));
	}

	void CompleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questID)
	{
		habiticaConnector.completeTask(convertToWideString(questID.data));
	}

	void DeleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questID)
	{
		habiticaConnector.deleteTask(convertToWideString(questID.data));
	}

	UInt32 GetRequestResult(StaticFunctionTag *base, BSFixedString questID)
	{
		return habiticaConnector.getResult(convertToWideString(questID.data));
	}

	bool RegisterFuncs(VMClassRegistry* registry) {
		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, void, BSFixedString, BSFixedString>("AddQuestToHabitica", "Skybitica", SkybiticaNamespace::AddQuestToHabitica, registry));
		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, void, BSFixedString>("CompleteQuestInHabitica", "Skybitica", SkybiticaNamespace::CompleteQuestInHabitica, registry));
		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, void, BSFixedString>("DeleteQuestInHabitica", "Skybitica", SkybiticaNamespace::DeleteQuestInHabitica, registry));
		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, UInt32, BSFixedString>("GetRequestResult", "Skybitica", SkybiticaNamespace::GetRequestResult, registry));

		return true;
	}
} 
