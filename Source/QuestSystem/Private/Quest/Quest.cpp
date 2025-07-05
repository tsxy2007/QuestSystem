// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest/Quest.h"
#include "Objective/QuestObjectiveBase.h"
#include <QuestSystemBPLibrary.h>

UQuest::UQuest(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UQuest::Init(const FQuestData& InQuestData)
{
	mQuestData = InQuestData;

	for (int32 i = 0; i < mQuestData.mObjectives.Num(); i++)
	{
		const FQuestObjective& Objective = mQuestData.mObjectives[i];
		UQuestObjectiveBase* ObjectiveItem = UQuestSystemBPLibrary::CreateQuestObjective(this, Objective.mObjectiveType);
		ObjectiveItem->Init(Objective);
		mQuestObjectives.Add(ObjectiveItem);
	}
}

void UQuest::StartQuest()
{
	for (UQuestObjectiveBase* Objective : mQuestObjectives)
	{
		if (Objective && Objective->Status == EObjectiveStatus::Inactive)
		{
			Objective->Activate();
		}
	}
}

void UQuest::Complete()
{

}

bool UQuest::IsComplete() const
{
	for (UQuestObjectiveBase* Objective : mQuestObjectives)
	{
		if (Objective && Objective->Status != EObjectiveStatus::Completed)
		{
			return false;
		}
	}
	return true;
}

void UQuest::UpdateObjectiveProgress(FName ObjectiveID, int32 Delta)
{
}

void UQuest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
