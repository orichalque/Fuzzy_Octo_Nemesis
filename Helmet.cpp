#include "Helmet.hpp"

using namespace std;

Helmet::Helmet()
{
	name_ = "helmet";
	desc_ = "prevent 5 damage";
	value_ = 5;
	consumable_ = false;
	settable_ = true;
}

Helmet::~Helmet()
{
}

