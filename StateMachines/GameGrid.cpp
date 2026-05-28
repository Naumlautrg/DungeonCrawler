#include "GameGrid.h"

GameGrid::GameGrid(int rows, int columns)
{
	GenerateGrid(rows, columns);
}

void GameGrid::GenerateGrid(int rows, int columns)
{
	grid.resize(rows);

	for (auto& row : grid)
	{
		row.reserve(columns);
		for (size_t i = 0; i < columns; ++i)
			row.push_back(std::make_unique<GridTile>());
	}
}

void GameGrid::Print()
{
	for (const auto& row : grid)
	{
		std::cout << "| ";

		for (const auto& tile : row)
		{
			std::cout << *tile << " | ";
		}

		std::cout << "\n";
	}
}
