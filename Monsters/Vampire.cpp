/**
 * \file Vampire.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 
/**
* \class Vampire
* \brief Define a concrete Monster
*/   
 class Vampire : public Monster {
    public: 
    /**
    * \fn Vampire()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */       
	Vampire() {
		Character::desc_ = "Un vampire assoiffé de sang";
		Character::name_ = "Vampire";
		Character::symbol_ = 'V';
		Character::attack_ = 36;
		Character::def_ = 25;
		Character::life_ = 86;
		Character::dext_ = 24;
		Monster::lootList = {5,17};
	}
};
