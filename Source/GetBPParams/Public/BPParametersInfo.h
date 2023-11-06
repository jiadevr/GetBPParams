// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "BPParametersInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct GETBPPARAMS_API FBPParametersInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BPParams")
	bool bShowWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BPParams")
	FVector WidgetOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BPParams")
	FText WidgetText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BPParams")
	FLinearColor TextColor;
	/*	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BPParams")FTexture2D WidgetTexture*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BPParams")
	double MoveAmplitude;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BPParams")
	int32 Index;
};
