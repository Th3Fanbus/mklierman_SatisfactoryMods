

#pragma once

#include "CoreMinimal.h"
#include "FGConstructDisqualifier.h"
#include "Hologram/FGFactoryHologram.h"
#include "LBBuild_ModularLoadBalancer.h"
#include "LBOutlineSubsystem.h"
#include "FGPlayerController.h"
#include "LBModularLoadBalancer_Hologram.generated.h"

/**
 *
 */
//DECLARE_LOG_CATEGORY_EXTERN(LoadBalancersHG_Log, Display, All);
UCLASS()
class LOADBALANCERS_API ALBModularLoadBalancer_Hologram : public AFGFactoryHologram
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	virtual AActor* Construct(TArray< AActor* >& out_children, FNetConstructionID netConstructionID) override;
	virtual void Destroyed() override;
	virtual bool TrySnapToActor(const FHitResult& hitResult) override;

	virtual bool IsValidHitResult(const FHitResult& hitResult) const override;

	void UnHighlightAll();

	void HighlightAll(TArray<ALBBuild_ModularLoadBalancer*> actorsToOutline);

	// Let use configure the load balancer.
	virtual void ConfigureActor(AFGBuildable* inBuildable) const override;
	
	UPROPERTY(BlueprintReadWrite, Replicated)
	ALBBuild_ModularLoadBalancer* LastSnapped;
	
	UPROPERTY(BlueprintReadWrite, Replicated)
	ALBBuild_ModularLoadBalancer* ActiveGroupLeader;

	UPROPERTY(EditDefaultsOnly, Category="Holo")
	UMaterialInterface* mHoloMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Holo")
	FLinearColor mHoloColor = FLinearColor(.5f, .5f, .5f, 1.f);

	UPROPERTY(EditDefaultsOnly, Category="Holo")
	FLinearColor mHoloFailedColor = FLinearColor(1.f, .0f, .0f, 1.f);

	UPROPERTY(Transient)
	ALBOutlineSubsystem* mOutlineSubsystem;
};


UCLASS()
class LOADBALANCERS_API UFGCDHasOverflow : public UFGConstructDisqualifier
{
	GENERATED_BODY()

	UFGCDHasOverflow()
	{
		mDisqfualifyingText = FText::FromString(TEXT("Only one Overflow module can be attached"));
	}
};
