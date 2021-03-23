// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C1.generated.h"




UCLASS()
class GMAE_API AC1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC1();

	/*cam arm*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera);
	class USpringArmComponent* CameraBoom;

	/*cam*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera);
	class UCameraComponent* FollowCamera;
	
	/*Right left, forward movement methods*/
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	

	/* Smert */
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	bool bDead; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
