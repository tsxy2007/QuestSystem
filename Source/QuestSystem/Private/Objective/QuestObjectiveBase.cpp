// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective/QuestObjectiveBase.h"

UQuestObjectiveBase::UQuestObjectiveBase(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{

}

void UQuestObjectiveBase::Init(const FQuestObjective& InObjective)
{
    Data = InObjective;
    OnInit();
}

void UQuestObjectiveBase::OnInit()
{
}

void UQuestObjectiveBase::Activate()
{
    Status = EObjectiveStatus::Active;
    OnObjectiveUpdated.Broadcast(this);
}

void UQuestObjectiveBase::Complete()
{
    Status = EObjectiveStatus::Completed;
    OnObjectiveUpdated.Broadcast(this);
}

void UQuestObjectiveBase::Fail()
{
    Status = EObjectiveStatus::Failed;
    OnObjectiveUpdated.Broadcast(this);
}

bool UQuestObjectiveBase::IsComplete() const
{
    return Status == EObjectiveStatus::Completed;
}