#include"Inventory.hpp"
using namespace std;

/**
 * \fn Inventory::Inventory()
 * \brief Constructeur d'inventaire
 * 
 * \param void
 * \return void
 * \deprecated Pas implémenté
 */ 
Inventory::Inventory() {
	itemNb = 0;
	for (int i = 0; i < NMAX; i ++ ) {
		items[i] = NULL;
		amount[i] = 0;
	}
} 

/**
 * \fn Inventory::~Inventory()
 * \brief Destructeur d'Inventaire
 * 
 * \param void
 * \return void
 * \deprecated Pas implémenté
 */ 
Inventory::~Inventory() {
}

/**
 * \fn Item* Inventory::getItem(int id)
 * \brief renvoit l'objet de l'inventaire avec l'ID en paramètre
 * 
 * \param int id
 * \return Item*
 * \deprecated Pas implémenté
 */ 
Item* Inventory::getItem(int id) {
	return items[id];
}

/**
 * \fn int Inventory::getItemAmount(int id)
 * \brief renvoit la quantité de l'Item avec l'id en paramètre
 * 
 * \param int id
 * \return int
 * \deprecated Pas implémenté
 */ 
int Inventory::getItemAmount(int id) {
	return amount[id];
}

/**
 * \fn void Inventory::addItem(Item *item_) 
 * \brief ajoute un objet à l'inventaire
 * 
 * \param Item* 
 * \return void
 * \deprecated Pas implémenté
 */ 
void Inventory::addItem(Item *item_) {
	if (items[item_ -> id()] == NULL) { //checking if item already in the array
		items[item_ -> id()] == item_; //If not, adding it
	}
	amount[item_ -> id()] += 1; //Incrementing its amount in the 2nd array
	itemNb += 1; 
}

/**
 * \fn void Inventory::dropItem(Item *item_)
 * \brief retire un objet de l'inventaire
 * 
 * \param Item* 
 * \return void
 * \deprecated Pas implémenté
 */ 
void Inventory::dropItem(Item *item_) {
	if ((items[item_ -> id()] != NULL)&&(amount[item_ -> id()] > 0)) { //checking if item is in the array, and if its amount is positive
		amount[item_ -> id()] -= 1;
		if (amount[item_ -> id()] == 0) { //if they're no items remaining, removing it.
			items[item_ -> id()] = NULL;
		}
	}
}

/**
 * \fn bool Inventory::useItem(Item *item_)
 * \brief utilise un objet de l'inventaire
 *
 * \param Item* 
 * \return bool
 * \deprecated Pas implémenté
 */ 
bool Inventory::useItem(Item *item_) {
	if (item_ -> consumable()) { //true -> item is consummable
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


