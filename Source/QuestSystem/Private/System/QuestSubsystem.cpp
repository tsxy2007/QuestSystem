// Fill out your copyright notice in the Description page of Project Settings.


#include "System/QuestSubsystem.h"
#include <Setting/QuestDevelopSettings.h>
#include <Data/QuestData.h>

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

		auto ForeachFun = [](const FName& key, const FQuestData& InQuestItem) mutable -> void {
			UE_LOG(LogTemp, Warning, TEXT("QuestTable = %s"), key);
			for (int32 i = 0; i < InQuestItem.mObjectives.Num(); i++)
			{
				InQuestItem.mType;
			}
		};
		DataTable->ForeachRow<FQuestData>(TEXT("UQuestSubsystem::QuestDataTable"), ForeachFun);
	}

	
}

bool UQuestSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}