// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include <GameplayTagContainer.h>
#include "QuestData.generated.h"

class UDialog;
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

// 任务状态
UENUM(BlueprintType)
enum class EQuestState : uint8
{
	//EQS_WaitTrigger = 0		UMETA(DisplayName = "等待触发"),
	EQS_Accept 			UMETA(DisplayName = "接受"),
	EQS_Going			UMETA(DisplayName = "进行中"),
	EQS_Completed		UMETA(DisplayName = "完成"),
	EQS_Canceled		UMETA(DisplayName = "取消"),
};

// 任务奖励类型
UENUM(BlueprintType)
enum class EQuestRewardType : uint8
{
	ERT_Empirical = 0		UMETA(DisplayName = "经验"),
	ERT_Item = 1			UMETA(DisplayName = "物品"),
};

// 任务触发方式枚举
UENUM(BlueprintType)
enum class EQuestTriggerModeType : uint8
{
	EQTT_Sequence = 0		UMETA(DisplayName = "视频"),
	EQTT_Dialog	  = 1		UMETA(DisplayName = "对话"),
};

// 任务目标
UENUM(BlueprintType)
enum class EQuestObjectiveType : uint8
{
	EQOT_Interact = 0		UMETA(DisplayName = "交互类目标"),
	EQOT_Kill = 1			UMETA(DisplayName = "击杀目标"),
	EQOT_Collect = 2		UMETA(DisplayName = "收集目标"),
	EQOT_MoveTo  = 3		UMETA(DisplayName = "移动至目标"),
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

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	EQuestObjectiveType mObjectiveType;
};

// 触发条件
USTRUCT(BlueprintType)
struct FQuestCondition
{
	GENERATED_BODY()
};

// 触发方式
USTRUCT(BlueprintType)
struct FQuestTriggerMode
{
	GENERATED_BODY()

	// 触发方式ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName mTriggerModeID;

	// 触发类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestTriggerModeType mTriggerModeType;

	// 对话结局ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName mEndTag;
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

	// 任务触发方式
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FQuestTriggerMode mTriggerMode;

	// 任务目标
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestObjective> mObjectives;

	// 任务奖励
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestReward> mRewards;
};

// 触发方式
USTRUCT(BlueprintType)
struct FQuestSequence : public FTableRowBase
{
	GENERATED_BODY()
	// 任务ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName mID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class ULevelSequence> mSequence;
};

// 对话框 触发方式
USTRUCT(BlueprintType)
struct FQuestDialog : public FTableRowBase
{
	GENERATED_BODY()
	// 任务ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName mID;

	// 对话系统资源
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UDialog> mDialog;
};
