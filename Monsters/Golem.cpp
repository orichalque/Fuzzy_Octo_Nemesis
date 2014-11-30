/**
 * \file Golem.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Boss for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 
/**
* \class Golem
* \brief Define a concrete boss
*/ 
 class Golem : public Monster {
    public: 
    /**
    * \fn Golem()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */    
	Golem() {
		Character::desc_ = "Un Golem de pierre d'au moins cinq mètres de haut !";
		Character::name_ = "Golem";
		Character::attack_ = 37;
		Character::def_ = 40;
		Character::life_ = 150;
		Character::dext_ = 19;
		Character::symbol_ = 'G';
		Monster::lootList = {8, 13, 18, 23};
	}
	
	bool isBoss() {
		return true;
	}
};
