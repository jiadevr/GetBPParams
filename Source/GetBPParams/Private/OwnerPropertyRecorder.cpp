// Fill out your copyright notice in the Description page of Project Settings.


#include "OwnerPropertyRecorder.h"

#include "Kismet/KismetStringLibrary.h"


// Sets default values for this component's properties
UOwnerPropertyRecorder::UOwnerPropertyRecorder()
{
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
		if (!CheckPropertyIsExportable(TargetProperty->GetPropertyFlags())||TargetProperty->GetMetaData("Category") == "Hidden Exposed")
		{
			continue;
		}
		const bool InstanceValue = *(TargetProperty->ContainerPtrToValuePtr<bool>(OwnerActor));
		const bool DefaultValue = *(TargetProperty->ContainerPtrToValuePtr<bool>(
			OwnerActor->GetClass()->GetDefaultObject()));
		if (InstanceValue != DefaultValue)
		{
			UE_LOG(LogTemp, Display, TEXT("Property %s Value Was Changed,Current Value:%s"), *TargetProperty->GetName(),
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

bool UOwnerPropertyRecorder::CheckPropertyIsExportable(const uint64& TargetFlags)
{
	if (TargetFlags & CPF_DisableEditOnInstance || TargetFlags & CPF_Transient || TargetFlags & CPF_EditorOnly ||
		!TargetFlags & CPF_Edit)
	{
		return false;
	}
	return true;
}
