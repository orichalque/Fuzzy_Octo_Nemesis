/**
 * \file Bully.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
/**
* \class Bully
* \brief Define a concrete Monster
*/ 
 class Bully : public Monster {
    public: 
    /**
    * \fn Bully()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */
	Bully() {
		Character::desc_ = "Un orc en armure, il est enragé.";
        Character::name_ = "Brute";
        Character::attack_ = 60;
        Character::def_ = 45;
        Character::life_ = 200;
	    Character::dext_ = 29;
	    Character::symbol_ = 'B';
	    Monster::lootList = {9,24};
	}
};


