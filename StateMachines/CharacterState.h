#pragma once
class Character;

class CharacterState
{
public:
	virtual void Toggle(Character* character) = 0;
	virtual ~CharacterState() {}
};

