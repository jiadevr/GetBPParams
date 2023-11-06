// Fill out your copyright notice in the Description page of Project Settings.


#include "BPParamController.h"

#include "BPParametersInfo.h"
#include "Engine/DataTable.h"
#include "Kismet/KismetStringLibrary.h"
#include "UObject/PropertyAccessUtil.h"

// Sets default values for this component's properties
UBPParamController::UBPParamController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UBPParamController::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UBPParamController::DEBUG_GetBPValue()
{
	if (!DoublePropertyName.IsNone())
	{
		double BPValue = 0;
		//GetBPDoubleValueByName(GetOwner(), DoublePropertyName, BPValue);
		if (GetBPValueOfType(GetOwner(), DoublePropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %f"), *(DoublePropertyName.ToString()), BPValue);
			/*BPValue=1000.0;
			if (SetBPValueOfType(GetOwner(),DoublePropertyName,BPValue))
			{
				UE_LOG(LogTemp, Display, TEXT("%s Value Changed To: %f"), *(DoublePropertyName.ToString()), BPValue);
			}*/
		}
	}
	if (!BoolPropertyName.IsNone())
	{
		bool BPValue = false;
		if (GetBPValueOfType(GetOwner(), BoolPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(BoolPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_BoolToString(BPValue)));
		}
	}
	if (!IntegerPropertyName.IsNone())
	{
		int32 BPValue = -1;
		if (GetBPValueOfType(GetOwner(), IntegerPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %d"), *(IntegerPropertyName.ToString()), BPValue);
		}
	}
	if (!TextPropertyName.IsNone())
	{
		FText BPValue;
		if (GetBPValueOfType(GetOwner(), TextPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(TextPropertyName.ToString()), *(BPValue.ToString()));
		}
	}

	if (!VectorPropertyName.IsNone())
	{
		FVector BPValue;
		//GetBPVectorValueByName(GetOwner(),VectorPropertyName,BPValue);
		if (GetBPValueOfType(GetOwner(), VectorPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(VectorPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_VectorToString(BPValue)));
		}
	}
	if (!ColorPropertyName.IsNone())
	{
		FLinearColor BPValue;
		if (GetBPValueOfType(GetOwner(), ColorPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(ColorPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_ColorToString(BPValue)));
		}
	}

	/*if (!TexturePropertyName.IsNone())
	{
		UTexture2D BPValue;
		if (GetBPValueOfType(GetOwner(), TexturePropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(TexturePropertyName.ToString()),
				   *(BPValue.GetPathName()));
		}
	}
	BPParamController.cpp(139): [C2248] 'UTexture2D::operator =': cannot access private member declared in class 'UTexture2D'
	*/
}

void UBPParamController::WriteDataToDataTable()
{
	if (!ParamRecorderDT)
	{
		return;
	}
	FBPParametersInfo* ParametersInfo = new FBPParametersInfo();

	if (!DoublePropertyName.IsNone())
	{
		double BPValue = 0;
		//GetBPDoubleValueByName(GetOwner(), DoublePropertyName, BPValue);
		if (GetBPValueOfType(GetOwner(), DoublePropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %f"), *(DoublePropertyName.ToString()), BPValue);
			if (SetDTValueOfType(ParametersInfo, DoublePropertyName, BPValue))
			{
				UE_LOG(LogTemp, Display, TEXT("Data Table Write Success"));
			}
		}
	}
	if (!BoolPropertyName.IsNone())
	{
		bool BPValue = false;
		if (GetBPValueOfType(GetOwner(), BoolPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(BoolPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_BoolToString(BPValue)));
			if (SetDTValueOfType(ParametersInfo, BoolPropertyName, BPValue))
			{
				UE_LOG(LogTemp, Display, TEXT("Data Table Write Success"));
			}
		}
	}
	if (!IntegerPropertyName.IsNone())
	{
		int32 BPValue = -1;
		if (GetBPValueOfType(GetOwner(), IntegerPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %d"), *(IntegerPropertyName.ToString()), BPValue);
			if (SetDTValueOfType(ParametersInfo, IntegerPropertyName, BPValue))
			{
				UE_LOG(LogTemp, Display, TEXT("Data Table Write Success"));
			}
		}
	}
	if (!TextPropertyName.IsNone())
	{
		FText BPValue;
		if (GetBPValueOfType(GetOwner(), TextPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(TextPropertyName.ToString()), *(BPValue.ToString()));
			if (SetDTValueOfType(ParametersInfo, TextPropertyName, BPValue))
			{
				UE_LOG(LogTemp, Display, TEXT("Data Table Write Success"));
			}
		}
	}
	if (!VectorPropertyName.IsNone())
	{
		FVector BPValue;
		if (GetBPValueOfType(GetOwner(), VectorPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(VectorPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_VectorToString(BPValue)));
			if (SetDTValueOfType(ParametersInfo, VectorPropertyName, BPValue))
			{
				UE_LOG(LogTemp, Display, TEXT("Data Table Write Success"));
			}
		}
	}
	if (!ColorPropertyName.IsNone())
	{
		FLinearColor BPValue;
		if (GetBPValueOfType(GetOwner(), ColorPropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(ColorPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_ColorToString(BPValue)));
			if (SetDTValueOfType(ParametersInfo, ColorPropertyName, BPValue))
			{
				UE_LOG(LogTemp, Display, TEXT("Data Table Write Success"));
			}
		}
	}
	ParamRecorderDT->AddRow(TargetRowName, *ParametersInfo);
	/*if (!TexturePropertyName.IsNone())
	{
		UTexture2D BPValue;
		if (GetBPValueOfType(GetOwner(), TexturePropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(TexturePropertyName.ToString()),
				   *(BPValue.GetPathName()));
		}
	}
	BPParamController.cpp(139): [C2248] 'UTexture2D::operator =': cannot access private member declared in class 'UTexture2D'
	*/
	delete ParametersInfo;
}

void UBPParamController::ReadDataFromDataTable()
{
	if (!ParamRecorderDT)
	{
		return;
	}
	FBPParametersInfo* ParametersInfo= ParamRecorderDT->FindRow<FBPParametersInfo>(TargetRowName,"");
	if (!ParametersInfo)
	{
		UE_LOG(LogTemp,Error,TEXT("Invalid Row Name,Find %s Failed"),*(TargetRowName.ToString()));
		return;
	}
	
	if (!DoublePropertyName.IsNone())
	{
		double DTValue = 0;
		if (GetDTValueOfType(ParametersInfo, DoublePropertyName, DTValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %f"), *(DoublePropertyName.ToString()), DTValue);
			if (SetBPValueOfType(GetOwner(), DoublePropertyName, DTValue))
			{
				UE_LOG(LogTemp, Display, TEXT("BP Param Write Success"));
			}
		}
	}
	if (!BoolPropertyName.IsNone())
	{
		bool DTValue = false;
		if (GetDTValueOfType(ParametersInfo, BoolPropertyName, DTValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(BoolPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_BoolToString(DTValue)));
			if (SetBPValueOfType(GetOwner(), BoolPropertyName, DTValue))
			{
				UE_LOG(LogTemp, Display, TEXT("BP Param Write Success"));
			}
		}
	}
	if (!IntegerPropertyName.IsNone())
	{
		int32 DTValue = -1;
		if (GetDTValueOfType(ParametersInfo, IntegerPropertyName, DTValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %d"), *(IntegerPropertyName.ToString()), DTValue);
			if (SetBPValueOfType(GetOwner(), IntegerPropertyName, DTValue))
			{
				UE_LOG(LogTemp, Display, TEXT("BP Param Write Success"));
			}
		}
	}
	if (!TextPropertyName.IsNone())
	{
		FText DTValue;
		if (GetDTValueOfType(ParametersInfo, TextPropertyName, DTValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(TextPropertyName.ToString()), *(DTValue.ToString()));
			if (SetBPValueOfType(GetOwner(), TextPropertyName, DTValue))
			{
				UE_LOG(LogTemp, Display, TEXT("BP Param Write Success"));
			}
		}
	}
	if (!VectorPropertyName.IsNone())
	{
		FVector DTValue;
		if (GetDTValueOfType(ParametersInfo, VectorPropertyName, DTValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(VectorPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_VectorToString(DTValue)));
			if (SetBPValueOfType(GetOwner(), VectorPropertyName, DTValue))
			{
				UE_LOG(LogTemp, Display, TEXT("BP Param Write Success"));
			}
		}
	}
	if (!ColorPropertyName.IsNone())
	{
		FLinearColor DTValue;
		if (GetDTValueOfType(ParametersInfo, ColorPropertyName, DTValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(ColorPropertyName.ToString()),
			       *(UKismetStringLibrary::Conv_ColorToString(DTValue)));
			if (SetBPValueOfType(GetOwner(), ColorPropertyName, DTValue))
			{
				UE_LOG(LogTemp, Display, TEXT("BP Param Write Success"));
			}
		}
	}
	/*if (!TexturePropertyName.IsNone())
	{
		UTexture2D BPValue;
		if (GetBPValueOfType(GetOwner(), TexturePropertyName, BPValue))
		{
			UE_LOG(LogTemp, Display, TEXT("%s Value Is: %s"), *(TexturePropertyName.ToString()),
				   *(BPValue.GetPathName()));
		}
	}
	BPParamController.cpp(139): [C2248] 'UTexture2D::operator =': cannot access private member declared in class 'UTexture2D'
	*/
}

#if WITH_EDITOR
void UBPParamController::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	UE_LOG(LogTemp, Display, TEXT("Refesh Data Here"));
}
#endif

bool UBPParamController::GetBPDoubleValueByName(const UObject* Target, const FName& PropertyName, double& OutValue)
{
	//Target->GetClass()不能是Target->StaticClass()，否则获取不出来,注释中的方法也可以
	FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->GetClass());
	//FProperty* NamedProperty=FindFProperty<FProperty>(Target->GetClass(),PropertyName);
	if (nullptr == NamedProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
		return false;
	}
	FDoubleProperty* NamedDoubleProperty = CastField<FDoubleProperty>(NamedProperty);
	if (nullptr == NamedDoubleProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Property Named: %s, But not Match Type"), *(PropertyName.ToString()));
		return false;
	}
	OutValue = NamedDoubleProperty->GetPropertyValue_InContainer(Target);
	UE_LOG(LogTemp, Display, TEXT("Find Property Sucess,Name:%s,Value:%f"), *(PropertyName.ToString()), OutValue)
	return true;
}

bool UBPParamController::GetBPVectorValueByName(const UObject* Target, const FName& PropertyName, FVector& OutValue)
{
	FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->GetClass());
	if (nullptr == NamedProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
		return false;
	}
	FStructProperty* NamedVectorProperty = CastField<FStructProperty>(NamedProperty);
	if (nullptr == NamedVectorProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Property Named: %s, But not Match Type"), *(PropertyName.ToString()));
		return false;
	}
	OutValue = *NamedVectorProperty->ContainerPtrToValuePtr<FVector>(Target);
	UE_LOG(LogTemp, Display, TEXT("Find Property Sucess,Name:%s,Value:%s"), *(PropertyName.ToString()),
	       *(UKismetStringLibrary::Conv_VectorToString(OutValue)))
	return true;
}


template <typename T>
bool UBPParamController::GetBPValueOfType(const UObject* Target, const FName& PropertyName, T& OutValue)
{
	FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->GetClass());
	//FProperty* NamedProperty=FindFProperty<FProperty>(Target->GetClass(),PropertyName);
	if (nullptr == NamedProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
		return false;
	}
	const T* TempValue = NamedProperty->ContainerPtrToValuePtr<T>(Target);
	if (!TempValue)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Property Named: %s, But not Match Type"), *(PropertyName.ToString()));
		return false;
	}
	OutValue = *TempValue;
	return true;
}

template <typename T>
bool UBPParamController::SetBPValueOfType(UObject* Target, const FName& PropertyName, const T& InValue)
{
	FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->GetClass());
	if (nullptr == NamedProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
		return false;
	}
	T* TargetParamAddress = NamedProperty->ContainerPtrToValuePtr<T>(Target);
	if (!TargetParamAddress)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Property Named: %s, But not Match Type"), *(PropertyName.ToString()));
		return false;
	}
	*TargetParamAddress = InValue;
	return true;
}

template <typename T>
bool UBPParamController::GetDTValueOfType(const FBPParametersInfo* Target, const FName& PropertyName, T& OutValue)
{
	FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->StaticStruct());
	//FProperty* NamedProperty=FindFProperty<FProperty>(Target->GetClass(),PropertyName);
	if (nullptr == NamedProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
		return false;
	}
	const T* TempValue = NamedProperty->ContainerPtrToValuePtr<T>(Target);
	if (!TempValue)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Property Named: %s, But not Match Type"), *(PropertyName.ToString()));
		return false;
	}
	OutValue = *TempValue;
	return true;
}

template <typename T>
bool UBPParamController::SetDTValueOfType(FBPParametersInfo* Target, const FName& PropertyName, const T& InValue)
{
	FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->StaticStruct());
	if (nullptr == NamedProperty)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
		return false;
	}
	T* TargetParamAddress = NamedProperty->ContainerPtrToValuePtr<T>(Target);
	if (!TargetParamAddress)
	{
		UE_LOG(LogTemp, Error, TEXT("Find Property Named: %s, But not Match Type"), *(PropertyName.ToString()));
		return false;
	}
	*TargetParamAddress = InValue;
	return true;
}
