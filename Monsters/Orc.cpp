/**
 * \file Orc.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */

/**
* \class Orc
* \brief Define a concrete Monster
*/   
 class Orc : public Monster {
    public: 
    /**
    * \fn Orc()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */       
	Orc() {
		Character::desc_ = "Un orc à l'allure aggressive";
		Character::name_ = "Orc";
		Character::symbol_ = 'O';
		Character::attack_ = 25;
		Character::def_ = 11;
		Character::life_ = 45;
		Character::dext_ = 6;
		Monster::lootList = {2, 20};
	}
};
