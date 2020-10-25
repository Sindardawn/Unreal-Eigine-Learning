// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
// Sets default values
int32 ATarget::score = 0;

ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//����BoxComponent
	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("TestCollision"));
	CollisionMesh->SetBoxExtent(FVector(200.f, 200.f, 10.f));
	CollisionMesh->bDynamicObstacle = true;
	CollisionMesh->SetupAttachment(GetRootComponent());
	//ע��: ���Ҫ��CollisionMesh->OnComponentHit�Ļص��¼���������������CollisionMesh->BodyInstance.SetCollisionProfileName
	CollisionMesh->BodyInstance.SetCollisionProfileName("MyCollisionProfile");
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	//Ҫ����Hit�¼������Զ�����Ҫ��ѡ���ԣ�Simulation Generates Hit Events
	FScriptDelegate DelegateHit;
	DelegateHit.BindUFunction(this, "OnTestHit");
	CollisionMesh->OnComponentHit.Add(DelegateHit);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::OnTestHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	ATarget::score++;
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("Your Score:")+FString::FromInt(ATarget::score),true);
}
