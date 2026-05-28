#pragma once

#include <vector>

#include "GameGrid.h"
#include "Character.h"

class GameManager
{
private:
	const int GRIDSIZE_X = 10;
	const int GRIDSIZE_Y = 10;

	GameGrid gameGrid;
	std::vector<std::unique_ptr<Character>> activeCharacters;
	Character* playerCharacter;

public:
	GameManager();

	void Start();
	void CreateCharacter(const Character& character);
};

