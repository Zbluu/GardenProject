// Copyright Alexandre Depail. All Rights Reserved.

#include "Tools/AbstractTool.h"

AAbstractTool::AAbstractTool()
: AActor()
, Mesh(CreateDefaultSubobject<UStaticMeshComponent>("Mesh"))
{
  // Create a static mesh here. It'll be used in BP child class to set the
  // static mesh of the tool.

  // Set the static mesh to root component.
  this->SetRootComponent(this->Mesh);
}

void AAbstractTool::UseToolOn(ACultivablePlot* PlotTarget){}

void AAbstractTool::EnablePhysics(const bool bEnable)
{
  // Enable/disable the physics of the root mesh.
  this->Mesh->SetSimulatePhysics(bEnable);
}

void AAbstractTool::BeginPlay()
{
  Super::BeginPlay();

  // Set the physics settings to not collide with player or camera.
  this->Mesh->SetCollisionProfileName("Tool", true);

  // Enable Physics by default.
  this->EnablePhysics(true);
}
