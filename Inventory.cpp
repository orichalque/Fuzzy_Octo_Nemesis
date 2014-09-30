#include"Inventory.hpp"

Inventory::Inventory() {
	itemNb = 0;
	for (int i = 0; i < NMAX; i ++ ) {
		item[i] = NULL;
		amount[i] = 0;
	}
}

Inventory::~Inventory() {
}

Item* Inventory::getItem(int id) {
	return items[id];
}

int Inventory::getItemAmount(int id) {
	return amount[id];
}

void Inventory::addItem(Item *item_) {
	if (items[item_ -> id()] == NULL) { //checking if item already in the array
		items[item_ -> id()] == _item; //If not, adding it
	}
	amount[items_ -> id()] += 1; //Incrementing its amount in the 2nd array
	itemNb += 1; 
}

void Inventory::dropItem(Item *item_) {
	if ((items[item_ -> id()] =! NULL)&&(amount[item_ -> id] >0)) { //checking if item is in the array, and if it's amount is positive
		amount[item_ -> id()] -= 1;
		if (amount[item_ -> id()] == 0) { //if they're no items remaining, removing it.
			items[item_ -> id()] = NULL;
		}
	}
}

bool Inventory::useItem(Item *item_) {
	if (item_.isConsummable()) { //true -> item is consummable
		if (amount[item_ -> id()] > 0 ) { // true -> the player have the item
			amount[item_ -> id()] -= 1; // item amount decreased after utilisation
			return true;
		 } else {
		 	return false; // the player don't have the item
		 }
	} else {
		return false; // the item isn't consummable
	}
}


