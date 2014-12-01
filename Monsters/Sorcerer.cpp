/**
 * \file Sorcerer.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */

/**
* \class Sorcerer
* \brief Define a concrete Monster
*/  
 class Sorcerer : public Monster {
    public: 
    /**
    * \fn Sorcerer()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */       
	Sorcerer() {
		Character::desc_ = "Un Sorcier armé d\'un sceptre ensorcelé !";
		Character::name_ = "Sorcier";
		Character::symbol_ = 'S';
		Character::attack_ = 49;
		Character::def_ = 5;
		Character::life_ = 35;
		Character::dext_ = 16;
		Monster::lootList = {3 , 11};
	}
};
