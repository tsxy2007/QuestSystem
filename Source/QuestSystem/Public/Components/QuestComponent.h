// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestComponent.generated.h"

struct FQuestData;
class UQuest;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnObjectiveCollected, FName,ItemTag,int32,ItemNum);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnObjectiveKill, FName,Tag,int32, Num);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveInteract, FName,Tag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveMoveTo, FName,Tag);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class QUESTSYSTEM_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void OnObjectiveCollectedFunc(FName InItemTag, int32 InNum);

	UFUNCTION()
	void OnObjectiveKillFunc(FName InItemTag, int32 InNum);

	UFUNCTION()
	void OnObjectiveInteractFunc(FName InTag);

	UFUNCTION()
	void OnObjectiveMoveToFunc(FName InTag);
public:
	UPROPERTY(BlueprintAssignable)
	FOnObjectiveCollected OnObjectiveCollected;

	UPROPERTY(BlueprintAssignable)
	FOnObjectiveKill OnObjectiveKill;

	UPROPERTY(BlueprintAssignable)
	FOnObjectiveInteract OnObjectiveInteract;

	UPROPERTY(BlueprintAssignable)
	FOnObjectiveMoveTo OnObjectiveMoveTo;
public:

	// 当前正在执行的任务列表
	UPROPERTY(BlueprintReadOnly)
	TArray<TObjectPtr<UQuest>> mActiveQuests;

	UPROPERTY()
	TMap<FName, TObjectPtr<UQuest>> mQuestMap;

	UPROPERTY()
	TObjectPtr<APlayerState> mPlayerState;

};
