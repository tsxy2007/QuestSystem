// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective/QuestObjectiveBase.h"
#include "QuestObjective_MoveTo.generated.h"

/**
 * �ƶ���Ŀ��
 */
UCLASS()
class QUESTSYSTEM_API UQuestObjective_MoveTo : public UQuestObjectiveBase
{
	GENERATED_BODY()

    UQuestObjective_MoveTo(const FObjectInitializer& ObjectInitializer);

public:
    // ����Ŀ��
    virtual void Activate() override;

    // ���Ŀ��
    virtual void Complete()override;

    // ʧ�ܴ���
    virtual void Fail()override;

    // ��ʼ��
    virtual void OnInit() override;
};
