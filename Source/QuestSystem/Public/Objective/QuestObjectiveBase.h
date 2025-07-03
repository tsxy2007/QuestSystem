// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestObjectiveBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveUpdated, UQuestObjectiveBase*, Objective);

UENUM(BlueprintType)
enum class EObjectiveStatus : uint8
{
    Inactive,   // 未激活
    Active,     // 进行中
    Completed,  // 完成
    Failed      // 失败
};
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestObjectiveBase : public UObject
{
	GENERATED_BODY()

public:
    UQuestObjectiveBase(const FObjectInitializer& ObjectInitializer);
public:
    // 激活目标
    UFUNCTION(BlueprintCallable)
    virtual void Activate();

    // 完成目标
    UFUNCTION(BlueprintCallable)
    virtual void Complete();

    // 失败处理
    UFUNCTION(BlueprintCallable)
    virtual void Fail();

    // 判定是否完成
    UFUNCTION(BlueprintCallable)
    virtual  bool IsComplete() const;

    // 目标描述（显示在UI中）
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    // 当前进度
    UPROPERTY(BlueprintReadOnly)
    int32 CurrentProgress = 0;

    // 目标所需进度
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TargetProgress = 1;

    // 目标状态
    UPROPERTY(BlueprintReadOnly)
    EObjectiveStatus Status = EObjectiveStatus::Inactive;

    // 目标更新时触发（用于UI更新）
    UPROPERTY(BlueprintAssignable)
    FOnObjectiveUpdated OnObjectiveUpdated;
};
