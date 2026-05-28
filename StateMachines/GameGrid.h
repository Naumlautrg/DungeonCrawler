#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "GridTile.h"

class GameGrid
{
private:
	std::vector<std::vector<std::unique_ptr<GridTile>>> grid;

public:
	GameGrid(int rows, int columns);

	inline std::vector<std::vector<std::unique_ptr<GridTile>>>& GetGrid() { return grid; }
	inline GridTile* GetGridTile(int x, int y) const { return grid[x][y].get(); }
	void GenerateGrid(int rows, int columns);
	void Print();
};

