// Copyright Falling Snow Interactive 2023


#include "BattlePokemon.h"

ABattlePokemon::ABattlePokemon()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SceneRoot->SetupAttachment(RootComponent);

	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	PaperSprite -> SetupAttachment(SceneRoot);
}

void ABattlePokemon::BeginPlay()
{
	Super::BeginPlay();
}

void ABattlePokemon::Initialize(UPokemonInstance* PokemonInstance)
{
	Instance = PokemonInstance;
	
	PaperSprite->SetSprite(Instance->Data->FrontSprite);
}

UHealth* ABattlePokemon::GetHealth()
{
	return Instance->GetHealth();
}

FName ABattlePokemon::GetName()
{
	return Instance->Name;
}

TArray<UAttackData*>* ABattlePokemon::GetAttacks()
{
	return &Instance->Attacks;
}

int ABattlePokemon::GetLevel()
{
	return Instance->Level;
}

FStatBlock* ABattlePokemon::GetStats()
{
	return Instance->GetStats();
}

