// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Plots/CultivablePlot.h"
#include "Components/StaticMeshComponent.h"
#include "AbstractTool.generated.h"

// Usable objects used by the player in game. This is an ABSTRACT class so you
// should not try to intanciate it. Class used to create child class for each
// different tool.
UCLASS(Abstract)
class AAbstractTool : public AActor
{
	GENERATED_BODY()

public:

	// Tool function that needs to be overrided in child class.
	UFUNCTION(BlueprintCallable)
  virtual void UseToolOn(ACultivablePlot* PlotTarget);

	// Enable or disable physics of the root component of this actor. Used to
	// prevent glitch when the player pickup the tool.
	UFUNCTION(BlueprintCallable)
	void EnablePhysics(const bool bEnable);

	virtual void BeginPlay() override;

protected:

	// Root component and static mesh (used in child class).
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent * Mesh;

	AAbstractTool();
};
