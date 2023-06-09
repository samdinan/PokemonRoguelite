// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/Actor.h"
#include "PokemonRoguelite/Gameplay/PokemonInstance.h"
#include "BattlePokemon.generated.h"

UCLASS()
class POKEMONROGUELITE_API ABattlePokemon : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UPokemonInstance* Instance;
	
	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	UPaperSpriteComponent* PaperSprite;
	
	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* SceneRoot;
	
public:	
	ABattlePokemon();

	void Initialize(UPokemonInstance* PokemonInstance);

	FName GetName();

	UFUNCTION(BlueprintCallable)
	UHealth* GetHealth();

	TArray<UAttackData*>* GetAttacks();

	int GetLevel();
	FStatBlock* GetStats();

protected:
	virtual void BeginPlay() override;

};
