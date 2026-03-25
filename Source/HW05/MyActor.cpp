// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	

	//Fvector로 currentpos라는 이름의 위치데이터 받고 setactorlocation()에 받은 값을 넣어즘


	FVector CurrentPos = FVector(0.0f, 50.0f, 0.0f);
	SetActorLocation(CurrentPos);

	for (int32 i = 0; i < 10; ++i) {


		//이동 범위를 랜덤하게 fvector에 적용후 적용한 fvector값을 addactorlocaloffset에 전달
	

		FVector RandomOffset = FVector(FMath::RandRange(-200.f, 200.f), FMath::RandRange(-200.f, 200.f), 0.f);

		AddActorLocalOffset(RandomOffset);


		//현재 위치정보를 수신
		FVector FinalPos = GetActorLocation();

		//AddOnScreenDebugMessage(① 번호, ② 시간, ③ 색상, ④[출력할 문장]FString::Printf(TEXT("Step %d: %s"), 데이터1, 데이터2 ...);)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("FinalLocation %d: %s"), i+1, *FinalPos.ToString()));

		FRotator RandomRotation = FRotator(FMath::RandRange(-200.f, 200.f), FMath::RandRange(-200.f, 200.f), 0.f);

		AddActorLocalRotation(RandomRotation);

		FRotator FinalRot = GetActorRotation();

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue,
			FString::Printf(TEXT("Final Rotation %d: %s"),i+1, *FinalRot.ToString()));

	}

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

