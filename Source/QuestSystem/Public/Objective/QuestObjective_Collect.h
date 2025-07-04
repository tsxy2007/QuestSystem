// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective/QuestObjectiveBase.h"
#include "QuestObjective_Collect.generated.h"

/**
 * 收集
 */
UCLASS()
class QUESTSYSTEM_API UQuestObjective_Collect : public UQuestObjectiveBase
{
	GENERATED_BODY()
public:
	UQuestObjective_Collect(const FObjectInitializer& ObjectInitializer);

public:
    // 激活目标
    virtual void Activate() override;

    // 完成目标
    virtual void Complete()override;

    // 失败处理
    virtual void Fail()override;

    // 初始化
    virtual void OnInit() override;
};
