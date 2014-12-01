/**
 * \file Invincible.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Final Boss for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */

/**
* \class Invincible
* \brief Define a concrete Final Boss
*/  
class Invincible : public Monster {
    public: 
    /**
    * \fn Invincible()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */       
	Invincible() {
		desc_ = "THE big boss";
		name_ = "L\'invincible";
		attack_ = 150;
		def_ = 70;
		life_ = 1000;
		dext_ = 35;
		Character::symbol_ = '&';
		Monster::lootList = {9, 14, 19, 24};
	}
	
	bool isBoss() {
		return true;
	}
	
	bool isFinalBoss() {
		return true;
	}
};
