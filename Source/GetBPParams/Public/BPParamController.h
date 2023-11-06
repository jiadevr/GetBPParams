// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BPParamController.generated.h"


struct FBPParametersInfo;
class UDataTable;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GETBPPARAMS_API UBPParamController : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBPParamController();

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="DataRecorder")
	UDataTable* ParamRecorderDT;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="DataRecorder|Row")
	FName TargetRowName="Preset1";
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="TargetParamsName")
	FName DoublePropertyName = "MoveAmplitude";

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="TargetParamsName")
	FName BoolPropertyName = "bShowWidget";

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="TargetParamsName")
	FName IntegerPropertyName = "Index";

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="TargetParamsName")
	FName TextPropertyName = "WidgetText";
	
	/*UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="TargetParamsName")
	FName TexturePropertyName = "WidgetTexture";
	读不了？*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="TargetParamsName")
	FName VectorPropertyName = "WidgetOffset";
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="TargetParamsName")
	FName ColorPropertyName = "TextColor";
	

	UFUNCTION(CallInEditor)
	void DEBUG_GetBPValue();

	UFUNCTION(CallInEditor,Category="DataRecorder")
	void WriteDataToDataTable();

	UFUNCTION(CallInEditor,Category="DataRecorder")
	void ReadDataFromDataTable();

	


#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif


	//Get BPValue
	bool GetBPDoubleValueByName(const UObject* Target, const FName& PropertyName, double& OutValue);
	bool GetBPVectorValueByName(const UObject* Target, const FName& PropertyName, FVector& OutValue);
	
	//BP-GetValue模板函数
	template <typename T>
	bool GetBPValueOfType(const UObject* Target, const FName& PropertyName, T& OutValue);
	
	//BP-SetValue模板函数
	template <typename T>
	bool SetBPValueOfType(UObject* Target, const FName& PropertyName, const T& InValue);

	//DT-GetValue模板函数
	template <typename T>
	bool GetDTValueOfType(const FBPParametersInfo* Target, const FName& PropertyName, T& OutValue);
	
	//DT-SetValue模板函数
	template <typename T>
	bool SetDTValueOfType(FBPParametersInfo* Target, const FName& PropertyName, const T& InValue);
	
	bool SetDoubleValueByName(UObject* Target, const FName& PropertyName, const double& InValue);
};


