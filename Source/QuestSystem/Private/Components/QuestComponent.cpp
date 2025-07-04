// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/QuestComponent.h"
#include <Setting/QuestDevelopSettings.h>
#include <Data/QuestData.h>

// Sets default values for this component's properties
UQuestComponent::UQuestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UQuestComponent::BeginPlay()
{
	Super::BeginPlay();

	mPlayerState = Cast<APlayerState>(GetOwner());
	check(mPlayerState);
	// ...
	auto Settings = GetDefault<UQuestDevelopSettings>();

	for (int32 i = 0; i < Settings->QuestDataTables.Num(); i++)
	{
		TSoftObjectPtr<UDataTable> DataTablePtr = Settings->QuestDataTables[i];
		const UDataTable* DataTable = DataTablePtr.LoadSynchronous();
		static const FString ContextString(TEXT("UQuestSubsystem::QuestDataTable"));

		auto ForeachFun = [this](const FName& key, const FQuestData& InQuestItem) mutable -> void
			{
				UE_LOG(LogTemp, Warning, TEXT("QuestTable = %s"), *key.ToString());
				auto Quest = NewObject<UQuest>();
				Quest->Init(InQuestItem);
				mQuestMap.Add(key, Quest);
			};
		DataTable->ForeachRow<FQuestData>(TEXT("UQuestSubsystem::QuestDataTable"), ForeachFun);
	}


}


// Called every frame
void UQuestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

