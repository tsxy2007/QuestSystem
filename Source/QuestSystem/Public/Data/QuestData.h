// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include <GameplayTagContainer.h>
#include "QuestData.generated.h"

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	QT_None,
	QT_Main,
	QT_Daily,
};

// ������
USTRUCT(BlueprintType)
struct FQuestReward
{
	GENERATED_BODY()
};

// ����Ŀ��
USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag mObjectiveTag;
};

USTRUCT(BlueprintType)
struct FQuestData : public FTableRowBase
{
	GENERATED_BODY()

	// ����ID
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName QID;

	// ��������ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> QFollowID;

	// ��������
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText QDesc;

	// ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestType QType;

	// ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestReward> QRewards;

	// ����Ŀ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestObjective> QObjectives;
};