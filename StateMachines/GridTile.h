#pragma once

#include <iostream>

enum class Occupant { None, Neutral, Player, Enemy };

class GridTile
{
private:
	const char CHAR_EMPTY = 'O';
	const char CHAR_NEUTRAL = 'N';
	const char CHAR_PLAYER = 'P';
	const char CHAR_ENEMY = 'E';

	char tileChar = ' ';
	Occupant occupant = Occupant::None;

public:
	GridTile();
	void SetOccupant(Occupant newOccupant);
	inline bool GetOccupied() const { return occupant != Occupant::None; }

	friend std::ostream& operator<<(std::ostream& os, const GridTile& gridTile);
};

