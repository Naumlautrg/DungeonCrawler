// Blind Hunt

#include <iostream>
#include <iomanip>

#include "GameManager.h"

int main()
{
	std::string characterFileName = "";
	// Have user initialize options + specify character file name via menu

	GameManager manager;
	manager.CreateCharacter(Character::LoadCharacterFromFile(characterFileName)); // Player character
	manager.Start();

	return 0;
}