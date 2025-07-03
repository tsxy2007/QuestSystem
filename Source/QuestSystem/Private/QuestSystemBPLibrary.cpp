// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestSystemBPLibrary.h"
#include "QuestSystem.h"
#include <Objective/QuestObjective_Interact.h>
#include <Objective/QuestObjective_Kill.h>
#include <Objective/QuestObjective_Collect.h>
#include <Objective/QuestObjective_MoveTo.h>

UQuestSystemBPLibrary::UQuestSystemBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

UQuestObjectiveBase* UQuestSystemBPLibrary::CreateQuestObjective(UObject* WorldContextObject, EQuestObjectiveType QuestObjectiveType, TSoftClassPtr<UQuestObjectiveBase> ClassPtr)
{
	UQuestObjectiveBase* ObjectiveItem = nullptr;
	if (ClassPtr.IsValid())
	{
		UClass* TemplateClass = ClassPtr.LoadSynchronous();
		ObjectiveItem = NewObject<UQuestObjectiveBase>(WorldContextObject, TemplateClass);
	}
	else
	{
		switch (QuestObjectiveType)
		{
		case EQuestObjectiveType::EQOT_Interact:
			ObjectiveItem = NewObject<UQuestObjective_Interact>(WorldContextObject);
			break;
		case EQuestObjectiveType::EQOT_Kill:
			ObjectiveItem = NewObject<UQuestObjective_Kill>(WorldContextObject);
			break;
		case EQuestObjectiveType::EQOT_Collect:
			ObjectiveItem = NewObject<UQuestObjective_Collect>(WorldContextObject);
			break;
		case EQuestObjectiveType::EQOT_MoveTo:
			ObjectiveItem = NewObject<UQuestObjective_MoveTo>(WorldContextObject);
			break;
		default:
			ObjectiveItem = NewObject<UQuestObjectiveBase>(WorldContextObject);
			break;
		}
	}

	return ObjectiveItem;
}

