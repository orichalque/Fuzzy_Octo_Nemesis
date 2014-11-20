#include "Monster.hpp"

Monster::Monster() { }

Monster::~Monster() { }
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Getters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

vector<int> Monster::getLootList(void) {
	return lootList;
}

int Monster::getNbLoot(void) {
	return nbLoot;
}

int Monster::getLootPb(void) {
	return lootPb;
}

