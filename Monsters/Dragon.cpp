/**
 * \file Dragon.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Boss for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */

/**
* \class Dragon
* \brief Define a concrete Boss
*/ 
 class Dragon : public Monster {
    public: 
    /**
    * \fn Dragon()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */    
	Dragon() {
		Character::desc_ = "Un lézard vert de 15 mètres crachant du feu";
        Character::name_ = "Dragon";
        Character::attack_ = 95;
        Character::def_ = 40;
        Character::life_ = 230;
        Character::dext_ = 29;
        Character::symbol_ = 'D';
        Monster::lootList = {9, 14, 19, 24};
	}
	
	bool isBoss() {
		return true;
	}
};
