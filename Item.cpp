#include "Item.hpp"

using namespace std;

Item::Item() {

}

string Item::name() const
{
	return name_;
}

string Item::description() const
{
	return desc_;
}

int Item::value() const
{
	return value_;
}

bool Item::consumable() const
{
	return consumable_;
}

bool Item::settable() const
{
	return settable_;
}

int Item::id() const
{
	return id_;
}
