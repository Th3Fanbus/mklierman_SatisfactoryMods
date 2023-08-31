

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FGColoredInstanceMeshProxy.h"
#include "LB_BPFL.generated.h"

/**
 *
 */
UCLASS()
class LOADBALANCERS_API ULB_BPFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category = "Utilities")
		static void SortStringArray(UPARAM(ref)TArray<FString>& Array_To_Sort, TArray<FString>& Sorted_Array);

		UFUNCTION(BlueprintCallable)
		static void SetMeshInstanced(UFGColoredInstanceMeshProxy* mesh, bool setToInstanced)
		{
			if (mesh)
			{
				mesh->SetInstanced(setToInstanced);
			}
		};
};
