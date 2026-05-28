#pragma once

#include "Character.h"

// Each concrete state class is a singleton

class Alive : public CharacterState
{
private:
	Alive() {}
	Alive(const Alive* other) = delete;
	Alive& operator=(const Alive* other) = delete;

public:
	void Toggle(Character* character);
	static CharacterState& GetInstance();
};

class Dead : public CharacterState
{
private:
	Dead() {}
	Dead(const Dead* other) = delete;
	Dead& operator=(const Dead* other) = delete;

public:
	void Toggle(Character* character);
	static CharacterState& GetInstance();
};

