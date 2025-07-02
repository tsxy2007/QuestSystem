// Fill out your copyright notice in the Description page of Project Settings.


#include "System/QuestSubsystem.h"
#include <Setting/QuestDevelopSettings.h>
#include <Data/QuestData.h>
#include <Quest/Quest.h>
#include <Objective/QuestObjective_Interact.h>
#include <Objective/QuestObjective_Kill.h>
#include <Objective/QuestObjective_Collect.h>
#include <Objective/QuestObjective_MoveTo.h>

UQuestSubsystem* UQuestSubsystem::Get(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);
	check(World);
	UQuestSubsystem* GI = UGameInstance::GetSubsystem<UQuestSubsystem>(World->GetGameInstance());
	check(GI);
	return GI;
}

void UQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	auto Settings = GetDefault<UQuestDevelopSettings>();

	for (int32 i = 0; i < Settings->QuestDataTables.Num(); i++)
	{
		TSoftObjectPtr<UDataTable> DataTablePtr = Settings->QuestDataTables[i];
		const UDataTable* DataTable = DataTablePtr.LoadSynchronous();
		static const FString ContextString(TEXT("UQuestSubsystem::QuestDataTable"));

		auto ForeachFun = [this](const FName& key, const FQuestData& InQuestItem) mutable -> void {
			UE_LOG(LogTemp, Warning, TEXT("QuestTable = %s"), *key.ToString());
			auto Quest = NewObject<UQuest>(this);
			for (int32 i = 0; i < InQuestItem.mObjectives.Num(); i++)
			{
				const FQuestObjective& Objective = InQuestItem.mObjectives[i];
				auto ObjectiveType = Objective.mObjectiveType;
				UQuestObjectiveBase* ObjectiveItem = nullptr;
				switch (ObjectiveType)
				{
				case EQuestObjectiveType::EQOT_Interact:
					ObjectiveItem = NewObject<UQuestObjective_Interact>(this);
					break;
				case EQuestObjectiveType::EQOT_Kill:
					ObjectiveItem = NewObject<UQuestObjective_Kill>(this);
					break;
				case EQuestObjectiveType::EQOT_Collect:
					ObjectiveItem = NewObject<UQuestObjective_Collect>(this);
					break;
				case EQuestObjectiveType::EQOT_MoveTo:
					ObjectiveItem = NewObject<UQuestObjective_MoveTo>(this);
					break;
				default:
					ObjectiveItem = NewObject<UQuestObjectiveBase>(this);
					break;
				}
				Quest->mQuestObjectives.Add(ObjectiveItem);
			}
		};
		DataTable->ForeachRow<FQuestData>(TEXT("UQuestSubsystem::QuestDataTable"), ForeachFun);
	}

	
}

bool UQuestSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}