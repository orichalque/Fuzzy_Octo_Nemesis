/**
 * \file Elemental.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
/**
* \class Elemental
* \brief Define a concrete Monster
*/ 
 class Elemental : public Monster {
    public: 
    /**
    * \fn Elemental()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */    
	Elemental() {
		Character::desc_ = "Un nuage dégageant des flammes et des éclairs ";
        Character::name_ = "Elemental";
        Character::symbol_ = 'E';
        Character::attack_ = 71;
        Character::def_ = 28;
        Character::life_ = 135;
        Character::dext_ = 28;
        Monster::lootList = {9 ,14};
	}
};
