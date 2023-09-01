#include "LB_GroupEquip.h"

void ALB_GroupEquip::MergeGroups()
{
	if (firstGroupLeader && secondGroupLeader)
	{
		if (firstGroupLeader->IsLeader())
		{
			TArray< ALBBuild_ModularLoadBalancer*> balancersToMove = secondGroupLeader->GetGroupModules();
			if (balancersToMove.Num() > 0)
			{
				if (HasAuthority())
				{
					secondGroupLeader->GroupLeader = firstGroupLeader;

					for (ALBBuild_ModularLoadBalancer* ModularLoadBalancer : balancersToMove)
					{
						if (ModularLoadBalancer)
						{
							ModularLoadBalancer->GroupLeader = firstGroupLeader;
							ModularLoadBalancer->mNormalLoaderData = firstGroupLeader->mNormalLoaderData;
							ModularLoadBalancer->ForceNetUpdate();
						}
					}

					firstGroupLeader->UpdateCache();
					firstGroupLeader->ForceNetUpdate();
				}
			}
		}
	}
}

void ALB_GroupEquip::SplitGroups()
{
	if (splitBalancers.Num() > 0)
	{
		for (auto balancer : splitBalancers)
		{

		}
	}
}
