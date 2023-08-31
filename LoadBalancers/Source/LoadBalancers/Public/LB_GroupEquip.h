#pragma once
#include "Equipment/FGEquipment.h"
#include "CoreMinimal.h"
#include "LoadBalancersModule.h"
#include "LBBuild_ModularLoadBalancer.h"
#include "FGColoredInstanceMeshProxy.h"
#include "LB_GroupEquip.generated.h"

UENUM(BlueprintType)
enum class EToolMode : uint8
{
	Merge = 0 UMETA(DisplayName = "Merge"),
	Split = 1 UMETA(DisplayName = "Split"),
};

UCLASS()
class LOADBALANCERS_API ALB_GroupEquip : public AFGEquipment
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	EToolMode currentToolMode;

	UPROPERTY(BlueprintReadWrite)
	ALBBuild_ModularLoadBalancer* firstGroupLeader;

	UPROPERTY(BlueprintReadWrite)
	ALBBuild_ModularLoadBalancer* secondGroupLeader;

	UPROPERTY(BlueprintReadWrite)
		TArray< ALBBuild_ModularLoadBalancer*> splitBalancers;

	UFUNCTION(BlueprintCallable, Category = "Equipment")
	void MergeGroups();

	UFUNCTION(BlueprintCallable, Category = "Equipment")
		void SplitGroups();
};

