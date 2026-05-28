#include "GridTile.h"

GridTile::GridTile() :
	tileChar(CHAR_EMPTY), occupant(Occupant::None) {}

void GridTile::SetOccupant(Occupant newOccupant)
{
	occupant = newOccupant;

	switch (newOccupant)
	{
	case Occupant::None:
		tileChar = CHAR_EMPTY;
		break;
	case Occupant::Player:
		tileChar = CHAR_PLAYER;
		break;
	case Occupant::Enemy:
		tileChar = CHAR_ENEMY;
		break;
	default:
		tileChar = CHAR_EMPTY;
		break;
	}
}

std::ostream& operator<<(std::ostream& os, const GridTile& gridTile)
{
	return os << gridTile.tileChar;
}
