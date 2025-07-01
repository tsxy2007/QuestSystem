// Fill out your copyright notice in the Description page of Project Settings.


#include "Setting/QuestDevelopSettings.h"

UQuestDevelopSettings::UQuestDevelopSettings()
	:Super()
{
}

// UObject interface
void UQuestDevelopSettings::PostInitProperties()
{
	Super::PostInitProperties();

#if WITH_EDITOR
	if (IsTemplate())
	{
		ImportConsoleVariableValues();
	}
#endif
}

#if WITH_EDITOR
void UQuestDevelopSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		ExportValuesToConsoleVariables(PropertyChangedEvent.Property);
	}
}

#endif