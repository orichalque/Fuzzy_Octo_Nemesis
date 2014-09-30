#include "Player.hpp"

Player::Player() {
	inventory = new Inventory();
	equipement = Item[4];
	for ( int i = 0; i < 4; i++ ){
		equipement[i] = NULL;
	}
}

/* Equipement table : What do u think modafakin Corentin ? */
/* pointer table ofc */
/*   [0]     [1]      [2]      [3] */
/* Weapon - Shield - Helmet - Armor */

Inventory Player::inventory(void) {
	return inventory;
}

void Player::addItem(Item item) {
	inventory.addItem(item);
}

void Player::useItem(Item item) {
	inventory.useItem(item);
}

void Player::dropItem(Item item) {
	inventory.dropItem(item);
}

//Pattern State ? Loulz
//Testing time, and equiping it in the right slot of the equipement table 
void Player::equipItem(Item item) {
	if (item.isEquipement()) {
		if (item.isWeapon) {
			equipement[0] = item;
		} else if (item.isShield()) {
			equipement[1] = item;		
		} else if (item.isHelm()) {
			equipement[2] = item;
		} else if (item.isArmor()){
			equipement[3] = item;
		} else {
			cout << "ERROR_ITEM" << endl;
		}
	} else {
		cout << "This item isn't equipable" << endl;
	}
}

//Remove an equiped armor or weapon
void Player::unequipItem(int i) {
	assert(i>= 0 && i < 5);
	equipement[i] = NULL;
}

//return player's attack plus weapon's att
int Player::attacking() {
	int i = 0;
	if (equipement[0] != NULL) { //testing if sword equiped
		i = equipement[0] -> attacking(); //Return weapon's attack.
	}
	return (this->attacking() + i); 
}

//return player's def plus armor bonuses
int Player::defending() {
	int i = 0;
	if (equipement[1] != NULL) { //shield equiped?
		i += equipement[1] -> defending();
	}
	if (equipement[2] != NULL ){ //helmet equiped?
		i += equipement[2] -> defending();
	}
	if (equipement[3] != NULL) { //armor equiped ?
		i += equipement[3] -> defending();
	}
	return (this -> defend() +i);
}

