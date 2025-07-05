// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Data/QuestData.h"
#include "Quest.generated.h"

class UQuestObjectiveBase;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuest : public UObject
{
	GENERATED_BODY()
	
	UQuest(const FObjectInitializer& ObjectInitializer);
public:
	UFUNCTION(BlueprintCallable)
	void Init(const FQuestData& InQuestData);

	// 启动任务
	UFUNCTION(BlueprintCallable)
	void StartQuest();

	// 完成任务
	UFUNCTION(BlueprintCallable)
	void Complete();

	// 检查任务是否完成
	UFUNCTION(BlueprintCallable)
	bool IsComplete() const;


    // 更新目标进度
    UFUNCTION(BlueprintCallable)
    void UpdateObjectiveProgress(FName ObjectiveID, int32 Delta);

    // 复制支持
    virtual bool IsSupportedForNetworking() const override { return true; }
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:
	UPROPERTY()
	TArray<TObjectPtr<UQuestObjectiveBase>> mQuestObjectives;

	UPROPERTY(Transient)
	FQuestData mQuestData;
};
