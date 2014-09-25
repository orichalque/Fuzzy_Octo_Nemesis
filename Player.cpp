Player::Player() {
	inventory = new Inventory();
	equipement = Item[4];
}

/* Equipement table : */
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
