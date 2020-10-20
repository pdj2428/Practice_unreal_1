// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	
	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
	void UpdateAnimationProperties();

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Movemnet)
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Movemnet)
	bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Movemnet)
	class APawn* Pawn;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Movemnet)
	class AMain* Main;
};
