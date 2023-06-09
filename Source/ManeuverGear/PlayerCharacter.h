// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"


UCLASS(config = Game)
class APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	//////////////////////////////////////////////////////////////////////////////////////////
	// Components

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

	/** Left Rope Box */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Rope, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> LeftRopeBox;

	/** Right Rope Box */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Rope, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> RightRopeBox;

	/** Left Rope Spawn Point */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Rope, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> LeftRopePoint;

	/** Right Spawn Point */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Rope, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> RightRopePoint;

	/** Rope Cable Components */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Rope, meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<class UCableComponent>> RopeCables;


	//////////////////////////////////////////////////////////////////////////////////////////
	// Inputs

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> LookAction;

	/** Camera Zoom Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ZoomAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float MinZoomLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float MaxZoomLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> WalkAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float RunSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float WalkSpeed = 300.f;

public:
	APlayerCharacter();

private:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for zooming input */
	void Zoom(const FInputActionValue& Value);

	/** Called for walking input */
	void Walk();
	void StopWalking();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE TObjectPtr<class USpringArmComponent> GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE TObjectPtr<class UCameraComponent> GetFollowCamera() const { return FollowCamera; }
};

