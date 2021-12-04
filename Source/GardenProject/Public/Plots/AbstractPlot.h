// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "AbstractPlot.generated.h"

// Parent class of all possible plot types. This is an ABSTRACT class so you
// should not try to intanciate it. Class used to create child class for each
// different plot types.
UCLASS(Abstract)
class AAbstractPlot : public AActor
{
	GENERATED_BODY()

protected:
  AAbstractPlot();
};
