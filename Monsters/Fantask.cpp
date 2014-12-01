/**
 * \file Fantask.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
/**
* \class Fantask
* \brief Define a concrete Monster
*/ 
 class Fantask : public Monster {
    public: 
    /**
    * \fn Fantask()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */    
	Fantask() {
		Character::desc_ = "Un fantassin squelette, caché derrière un immense bouclier";
		Character::name_ = "Fantassin Squelette";
		Character::symbol_ = 'F';
		Character::attack_ = 50;
		Character::def_ = 35;
		Character::life_ = 78;
		Character::dext_ = 25;
		Monster::lootList = {5 , 12};
	}
};
