// Copyright KonaBear


#include "AbilitySystem/Abilities/AuraFireBlast.h"

FString UAuraFireBlast::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	
		return FString::Printf(TEXT(
			// Title
			"<Title>FIRE BLAST</>\n\n"
			// Details
			"<Small>Level: </><Level>%d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			// Descriptions
			"<Default>Launches %d fire balls in all directions, each coming back and exploding upon return, causing </>"
			"<Damage>%d</><Default> radial fire damage with a chance to burn</>\n\n"),
			//Values
			Level,
			ManaCost,
			Cooldown,
			NumFireBalls,
			ScaledDamage);
	
}

FString UAuraFireBlast::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	
	return FString::Printf(TEXT(
		// Title
		"<Title>NEXT LEVEL:</>\n\n"
		// Details
		"<Small>Level: </><Level>%d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
		// Descriptions
		"<Default>Launches %d fire balls in all directions, each coming back and exploding upon return, causing </>"
		"<Damage>%d</><Default> radial fire damage with a chance to burn</>\n\n"),
		//Values
		Level,
		ManaCost,
		Cooldown,
		NumFireBalls,
		ScaledDamage);
}

TArray<AAuraFireBall*> UAuraFireBlast::SpawnFireBalls()
{
	return TArray<AAuraFireBall*>();
}
