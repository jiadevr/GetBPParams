// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OwnerPropertyRecorder.generated.h"


UCLASS(ClassGroup=(EditorUtilities), meta=(BlueprintSpawnableComponent))
class GETBPPARAMS_API UOwnerPropertyRecorder : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOwnerPropertyRecorder();

protected:

	UFUNCTION(CallInEditor,Category="GetProperties")
	void GetModifiedProperties();

	UPROPERTY(EditInstanceOnly,Category="GetProperties")
	FString OutputPath;

	UPROPERTY(EditInstanceOnly,Category="GetProperties")
	FString FileName;
};
