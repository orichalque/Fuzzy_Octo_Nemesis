#include "Monster.hpp"

Monster::Monster() { 
	srand (time(NULL));
	lootPb = rand()%40 + 40; //~40% to 80% loot
}

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

bool Monster::isBoss() {
	return false;
}

