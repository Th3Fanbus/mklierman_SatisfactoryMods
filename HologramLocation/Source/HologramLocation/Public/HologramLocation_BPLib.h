// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FGFactoryConnectionComponent.h"
#include "Hologram/FGConveyorLiftHologram.h"
#include "HologramLocation_BPLib.generated.h"


/**
 *
 */
UCLASS()
class HOLOGRAMLOCATION_API UHologramLocation_BPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "HologramLocation")
		static FString RegexReplace(FString inputString, FString regexCode, FString replacementText);

	UFUNCTION(BlueprintCallable, Category = "HologramLocation")
		static FString AddCommasToInt(int inputInt);


	UFUNCTION(BlueprintCallable, Category = "HologramLocation")
		static FVector GetConnectionComponentLocation(UFGFactoryConnectionComponent* connection);


	UFUNCTION(BlueprintCallable, Category = "HologramLocation")
		static FVector GetConnectionComponentRotation(UFGFactoryConnectionComponent* connection);


	UFUNCTION(BlueprintCallable, Category = "HologramLocation")
		static FTransform GetLiftHologramTransform(AFGConveyorLiftHologram* clHologram);

	UFUNCTION(BlueprintCallable, Category = "HologramLocation")
		static FString FormatIntAsNumberString(int32 number, bool usePeriod);

	UFUNCTION(BlueprintCallable, Category = "HologramLocation")
		static FString FormatFloatAsNumberString(float number, bool usePeriod);
};
