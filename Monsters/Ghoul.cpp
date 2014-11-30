/**
 * \file Ghoul.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
/**
* \class Ghoul
* \brief Define a concrete Monster
*/ 
 class Ghoul : public Monster {
    public: 
    /**
    * \fn Ghoul()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */    
	Ghoul() {
		Character::desc_ = "Une goule en décomposition, dégueulasse";
		Character::name_ = "Goule";
		Character::symbol_ = 'G';
		Character::attack_ = 27;
		Character::def_ = 34;
		Character::life_ = 100;
		Character::dext_ = 22;
		Monster::lootList = {22};
	}
};
