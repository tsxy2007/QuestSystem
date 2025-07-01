// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "QuestDevelopSettings.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Quest Develop"))
class QUESTSYSTEM_API UQuestDevelopSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UQuestDevelopSettings();
public:
	virtual void PostInitProperties() override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
public:
	UPROPERTY(Config, EditAnywhere, Category = "Config")
	TArray<TSoftObjectPtr<UDataTable>> QuestDataTables;


	UPROPERTY(Config, EditAnywhere, Category = "Config")
	TArray<TSoftObjectPtr<UDataTable>> SequenceDataTables;
};
