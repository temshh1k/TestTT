// Fill out your copyright notice in the Description page of Project Settings.


#include "C1.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AC1::AC1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*capsule size*/
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 100.0f);

	/*выключаем зависимости поворота камеры*/
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	/*создаем и настраиваем спрингарм*/
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	/*создаем и настраиваем камеру*/
	FollowCamera = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	/*создаем и настраиваем Movement Component*/
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f,540.0f,0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	GetCharacterMovement()->SetWalkableFloorAngle(60);


	/* Smert ini */
	bDead = false;
}



// Called when the game starts or when spawned
void AC1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AC1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*Вперед и назад*/

	PlayerInputComponent->BindAxis("MoveForward", this, &AC1::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AC1::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AC1::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AC1::AddControllerPitchInput);
}


void AC1::MoveForward(float Axis)
{
	if ((Controller != NULL) && (Axis != 0.0f) && (bDead != true)){
		
		/*Получаем угол направления камеры*/
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);


		


	}
}

void AC1::MoveRight(float Axis)
{
	if ((Controller != NULL) && (Axis != 0.0f) && (bDead != true)) {

		
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);


	}
}


