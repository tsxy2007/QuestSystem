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

// 任务奖励
USTRUCT(BlueprintType)
struct FQuestReward
{
	GENERATED_BODY()
};

// 任务目标
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

	// 任务ID
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName QID;

	// 后续任务ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> QFollowID;

	// 任务描述
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText QDesc;

	// 任务类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestType QType;

	// 任务奖励
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestReward> QRewards;

	// 任务目标
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestObjective> QObjectives;
};