#include "Sword.hpp"

using namespace std;

Sword::Sword()
{
	name_ = "sword";
	desc_ = "weapon with 10 attack";
	value_ = 10;
	consumable_ = false;
	settable_ = true;
}

Sword::~Sword()
{
}

int Sword::attack() const
{
	return value_;
}

