// Fill out your copyright notice in the Description page of Project Settings.


#include "OwnerPropertyRecorder.h"

#include "Kismet/KismetStringLibrary.h"


// Sets default values for this component's properties
UOwnerPropertyRecorder::UOwnerPropertyRecorder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	OutputPath = FPaths::ProjectSavedDir();
}

void UOwnerPropertyRecorder::GetModifiedProperties()
{
	AActor* OwnerActor = GetOwner();
	if (!FPaths::DirectoryExists(OutputPath))
	{
		UE_LOG(LogTemp, Error, TEXT("Error Output Path!"));
		return;
	}
	FString OutputData;
	OutputData.Append("+BooleanProperties:\r\n");
	for (TFieldIterator<FBoolProperty> TargetProperty(OwnerActor->GetClass()); TargetProperty; ++TargetProperty)
	{
		//下边的判断可以过滤掉bReplicateUsingRegisteredSubObjectList
		if (TargetProperty->GetPropertyFlags() & CPF_DisableEditOnInstance || !TargetProperty->GetPropertyFlags() &
			CPF_Edit)
		{
			continue;
		}
		const bool InstanceValue = *(TargetProperty->ContainerPtrToValuePtr<bool>(OwnerActor));
		const bool DefaultValue = *(TargetProperty->ContainerPtrToValuePtr<bool>(
			OwnerActor->GetClass()->GetDefaultObject()));
		if (InstanceValue != DefaultValue)
		{
			UE_LOG(LogTemp, Display, TEXT("Property %s Value Changed,Current Value:%s"), *TargetProperty->GetName(),
			       *UKismetStringLibrary::Conv_BoolToString(InstanceValue));
			OutputData.Append(TargetProperty->GetName()+":"+UKismetStringLibrary::Conv_BoolToString(InstanceValue)+"\r\n");
		}
	}
	if (FileName.IsEmpty())
	{
		FileName=OwnerActor->GetName()+".txt";
	}
	if (!FileName.EndsWith(".txt"))
	{
		FileName+=".txt";
	}
	FFileHelper::SaveStringToFile(OutputData,*(OutputPath+FileName));
	UE_LOG(LogTemp, Display, TEXT("Generate Output File Success"));
}
