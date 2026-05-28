#include "GameManager.h"

GameManager::GameManager()
	: gameGrid(GameGrid(GRIDSIZE_X, GRIDSIZE_Y)) { }

void GameManager::Start()
{
	gameGrid.Print();
}
