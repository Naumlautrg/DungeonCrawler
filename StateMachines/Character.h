#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#include "GridTile.h"
#include "CharacterState.h"
#include "ConcreteCharacterStates.h"

class Character
{
private:
	CharacterState* state;

	enum class Alliance { Neutral, Player, Enemy };

	std::string name = "";
	std::string className = "";
	int level = 0;
	int maxHealth = 0;
	int currentHealth = 0;
	int armor = 0;
	int attackDamage = 0;
	int armorPiercing = 0;
	Alliance alliance = Alliance::Neutral;
	GridTile* currentTile = nullptr;

public:
	Character(GridTile* tile);

	inline CharacterState* GetState() const { return state; }
	inline std::string GetName() const { return name; }
	inline std::string GetClassName() const { return className; }
	inline int GetLevel() const { return level; }
	inline int GetMaxHealth() const { return maxHealth; }
	inline int GetCurrentHealth() const { return currentHealth; }
	inline int GetArmor() const { return armor;  }
	inline int GetAttackDamage() const { return attackDamage; }
	inline int GetArmorPiercing() const { return armorPiercing; }
	inline Alliance GetAlliance() const { return alliance; }
	inline void SetName(const std::string& name) { this->name = name; }
	inline void SetClassName(const std::string className) { this->className = className; }
	inline void SetLevel(int level) { this->level = level; }
	inline void SetMaxHealth(int health) { this->maxHealth = health; }
	inline void SetArmor(int armor) { this->armor = armor; }
	inline void SetAttackDamage(int attackDamage) { this->attackDamage = attackDamage; }
	inline void SetArmorPiercing(int armorPiercing) { this->armorPiercing = armorPiercing; }
	inline void SetAlliance(Alliance alliance) { this->alliance = alliance; }

	void ToggleState();
	void SetState(CharacterState& newState);

	void MoveCharacter(GridTile* tile);
	void AttackCharacter(Character* character);
	void TakeDamage(Character* source, int amount, int armorPiercing);
	void HealHealth(Character* source, int amount);
	void Death(Character* source);
	static Character LoadCharacterFromFile(const std::string& fileName);
};