#include "Item.hpp"

using namespace std;

Item::Item() {

}

string Item::getName()
{
	return name_;
}

string Item::getDescription()
{
	return desc_;
}

int Item::getValue()
{
	return value_;
}

bool Item::isConsumable()
{
	return consumable_;
}

bool Item::isSettable()
{
	return settable_;
}

int Item::getId()
{
	return id_;
}

bool isEquipement() {
    return false;
}
