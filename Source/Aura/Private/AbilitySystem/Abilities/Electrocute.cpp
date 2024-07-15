// Copyright KonaBear


#include "AbilitySystem/Abilities/Electrocute.h"

FString UElectrocute::GetDescription(int32 Level)
{
	
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>ELECTROCUTE</>\n\n"
			// Details
			"<Small>Level: </><Level>%d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			// Description
			"<Default>Emits a beam of lightning, connecting with the target repeatedly causing </>"
			"<Damage>%d</><Default> lightning damage with a chance to stun</>\n\n"),
			//Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>ELECTROCUTE</>\n\n"
			// Details
			"<Small>Level: </><Level>%d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			// Description
			"<Default>Emits a beam of lightning propagating to %d additional targets nearby, causing </>"
			"<Damage>%d</><Default> lightning damage with a chance to stun</>\n\n"),
			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShockTargets-1),
			ScaledDamage);
	}
	
}

FString UElectrocute::GetNextLevelDescription(int32 Level)
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
	// Description
	"<Default>Emits a beam of lightning propagating to %d additional targets nearby, causing </>"
	"<Damage>%d</><Default> lightning damage with a chance to stun</>\n\n"),
	//Values
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, MaxNumShockTargets-1),
	ScaledDamage);
}
