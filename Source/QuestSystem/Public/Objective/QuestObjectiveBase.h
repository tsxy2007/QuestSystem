// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestObjectiveBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveUpdated, UQuestObjectiveBase*, Objective);

UENUM(BlueprintType)
enum class EObjectiveStatus : uint8
{
    Inactive,   // δ����
    Active,     // ������
    Completed,  // ���
    Failed      // ʧ��
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
    // ����Ŀ��
    UFUNCTION(BlueprintCallable)
    virtual void Activate();

    // ���Ŀ��
    UFUNCTION(BlueprintCallable)
    virtual void Complete();

    // ʧ�ܴ���
    UFUNCTION(BlueprintCallable)
    virtual void Fail();

    // �ж��Ƿ����
    UFUNCTION(BlueprintCallable)
    virtual  bool IsComplete() const;

    // Ŀ����������ʾ��UI�У�
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    // ��ǰ����
    UPROPERTY(BlueprintReadOnly)
    int32 CurrentProgress = 0;

    // Ŀ���������
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TargetProgress = 1;

    // Ŀ��״̬
    UPROPERTY(BlueprintReadOnly)
    EObjectiveStatus Status = EObjectiveStatus::Inactive;

    // Ŀ�����ʱ����������UI���£�
    UPROPERTY(BlueprintAssignable)
    FOnObjectiveUpdated OnObjectiveUpdated;
};
