#include "Character.h"

Character::Character(GridTile* tile)
	: currentTile(tile), state(&Alive::GetInstance()) {}

void Character::ToggleState()
{
	state->Toggle(this);
}

void Character::SetState(CharacterState& newState)
{
	state = &newState;
}

void Character::MoveCharacter(GridTile* target)
{
	if (target->GetOccupied())
	{
		std::cout << "Target tile is already occupied.\n";
		return;
	}

	currentTile->SetOccupant(Occupant::None);

	switch (alliance)
	{
	case Alliance::Neutral:
		target->SetOccupant(Occupant::Neutral);
		break;
	case Alliance::Player:
		target->SetOccupant(Occupant::Player);
		break;
	case Alliance::Enemy:
		target->SetOccupant(Occupant::Enemy);
		break;
	default:
		target->SetOccupant(Occupant::Neutral);
	}
}

void Character::AttackCharacter(Character* target)
{
	std::cout << name + " attacked " + target->name + ".";
	target->TakeDamage(this, attackDamage, armorPiercing);
}

void Character::TakeDamage(Character* source, int amount, int armorPiercing)
{
	int totalDamage = amount - std::clamp(armor - armorPiercing, 0, armor);
	currentHealth -= totalDamage;
	
	std::cout << name + " took " + std::to_string(totalDamage) + " damage.";

	if (currentHealth <= 0)
	{
		Death(source);
	}
}

void Character::HealHealth(Character* source, int amount)
{
	currentHealth = std::clamp(currentHealth + amount, 0, maxHealth);
}

void Character::Death(Character* source)
{
	ToggleState();

	std::cout << name + " has died.";
}

void Character::LoadCharacterFromFile(std::string fileName)
{
}
