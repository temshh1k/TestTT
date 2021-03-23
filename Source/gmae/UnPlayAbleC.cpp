// Fill out your copyright notice in the Description page of Project Settings.


#include "UnPlayAbleC.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AUnPlayAbleC::AUnPlayAbleC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*capsule size*/
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 100.0f);



}

// Called when the game starts or when spawned
void AUnPlayAbleC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnPlayAbleC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnPlayAbleC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

