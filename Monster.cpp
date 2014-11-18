#include "Monster.hpp"

Monster::Monster() { }

Monster::~Monster() { }
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Getters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*
Item Monster::lootList(void) {
	return lootList;
}

*/
int Monster::getNbLoot(void) {
	return nbLoot;
}

int Monster::getLootPb(void) {
	return lootPb;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~Methods~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*
Item Monster::loot(void) {
	int v = rand() % 100 + 1; // number from 1 to 100
	if ( v <= lootPb) { //loot
		v = rand() % nbLoot; // Obtain a number from 0 to nbLoot
		return lootList[v];              
	} else { //no loot
		return NULL;
	}
}
*/
