// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective/QuestObjective_Kill.h"


UQuestObjective_Kill::UQuestObjective_Kill(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void UQuestObjective_Kill::Activate()
{
	Super::Activate();
}

void UQuestObjective_Kill::Complete()
{
	Super::Complete();
}

void UQuestObjective_Kill::Fail()
{
	Super::Complete();
}
