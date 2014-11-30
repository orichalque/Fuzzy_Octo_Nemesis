#include "Monster.hpp"

/**
 * \fn Monster::Monster()
 * \brief Instancie le monstre
 *
 * \param void
 * \return void
 *
 * Instancie le monstre, crée son pourcentage de change de laisser l'objet de manière aléatoire
 */ 
Monster::Monster() { 
	lootPb = rand()%40 + 40; //~40% to 80% loot
}

/**
 * \fn Monster::~Monster()
 * \brief détruit le monstre
 *
 * \param void
 * \return void
 *
 */ 
Monster::~Monster() { }
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Getters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * \fn Monster::getLootList(void)
 * \brief renvoit la liste de butin du monstre
 *
 * \param void
 * \return vector<int>
 *
 */ 
vector<int> Monster::getLootList(void) {
	return lootList;
}

/**
 * \fn int Monster::getNbLoot(void)
 * \brief renvoit le nombre de butins du monstre
 *
 * \param void
 * \return int
 *
 */ 
int Monster::getNbLoot(void) {
	return nbLoot;
}

/**
 * \fn int Monster::getLootPb(void)
 * \brief renvoit la probabilité de loot du monstre
 *
 * \param void
 * \return int
 *
 */ 
int Monster::getLootPb(void) {
	return lootPb;
}

/**
 * \fn boo Monster::isBoss()
 * \brief Teste si le monstre est un boss ou non
 *
 * \param void
 * \return bool
 *
 */ 
bool Monster::isBoss() {
	return false;
}

/**
 * \fn boo Monster::isFinalBoss()
 * \brief Teste si le monstre est le boss final ou non
 *
 * \param void
 * \return bool
 *
 */ 
bool Monster::isFinalBoss() {
	return false;
}

