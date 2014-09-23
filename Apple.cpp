#include "Apple.hpp"

using namespace std;

Apple::Apple()
{
	name_ = "apple";
	desc_ = "give 10 lp";
	value_ = 10;
	consumable_ = true;
	settable_ = false;
}

Apple::~Apple()
{
}

int Apple::use() const
{
	return value_;
}

