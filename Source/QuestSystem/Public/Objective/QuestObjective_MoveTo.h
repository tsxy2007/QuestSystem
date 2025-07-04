// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective/QuestObjectiveBase.h"
#include "QuestObjective_MoveTo.generated.h"

/**
 * 移动至目标
 */
UCLASS()
class QUESTSYSTEM_API UQuestObjective_MoveTo : public UQuestObjectiveBase
{
	GENERATED_BODY()

    UQuestObjective_MoveTo(const FObjectInitializer& ObjectInitializer);

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
