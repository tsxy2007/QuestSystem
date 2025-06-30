// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include <GameplayTagContainer.h>
#include "QuestData.generated.h"

// 任务类型
UENUM(BlueprintType)
enum class EQuestType : uint8
{
	QT_Main   UMETA(DisplayName = "主线"),
	QT_Daily  UMETA(DisplayName = "日常"),
};

// 任务等级
UENUM(BlueprintType)
enum class EQuestPriority : uint8
{
	EQP_Low = 0			UMETA(DisplayName = "低"),
	EQP_Normal = 1		UMETA(DisplayName = "正常"),
	EQP_High = 2		UMETA(DisplayName = "高"),
	EQP_Urgent = 3		UMETA(DisplayName = "紧急"),
};

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	EQS_Accept = 0			UMETA(DisplayName = "接受"),
	EQS_Going = 1			UMETA(DisplayName = "进行中"),
	EQS_Completed = 2		UMETA(DisplayName = "完成"),
	EQS_Canceled = 3		UMETA(DisplayName = "取消"),
};

// 任务奖励
USTRUCT(BlueprintType)
struct FQuestReward
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName mQRId;
};

// 任务目标
USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName FQOId;
};

// 接收任务方式
USTRUCT(BlueprintType)
struct FQuestCondition
{
	GENERATED_BODY()
};

// 任务
USTRUCT(BlueprintType)
struct FQuestData : public FTableRowBase
{
	GENERATED_BODY()

	// 任务ID
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName mID;

	// 任务描述
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText mDesc;

	// 任务类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestType mType;

	// 后续任务ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> mNextID;

	// 任务优先级
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestPriority mPriority;

	// 触发条件
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FQuestCondition> mConditiones;

	// 任务奖励
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestReward> mRewards;

	// 任务目标
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestObjective> mObjectives;
};