// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	static UQuestSubsystem* Get(const UObject* Object);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

public:
	UPROPERTY()
	TMap<FName, TObjectPtr<UQuest>> mQuestMap;
};
