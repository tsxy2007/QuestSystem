// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective/QuestObjectiveBase.h"

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