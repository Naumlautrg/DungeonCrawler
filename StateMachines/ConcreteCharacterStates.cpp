#include "ConcreteCharacterStates.h"

void Alive::Toggle(Character* character)
{
	character->SetState(Dead::GetInstance());
}

CharacterState& Alive::GetInstance()
{
	static Alive singleton;
	return singleton;
}

void Dead::Toggle(Character* character)
{
	character->SetState(Alive::GetInstance());
}

CharacterState& Dead::GetInstance()
{
	static Dead singleton;
	return singleton;
}