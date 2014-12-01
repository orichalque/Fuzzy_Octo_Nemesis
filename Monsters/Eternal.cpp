/**
 * \file Eternal.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
/**
* \class Eternal
* \brief Define a concrete Monster
*/ 
 class Eternal : public Monster {
    public: 
    /**
    * \fn Eternal()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */    
	Eternal() {
	    Character::	desc_ = "Un magicien qui déchaine les éléments";
	    Character::	name_ = "Eternel";
	    Character::symbol_ = 'E';
	    Character::	attack_ = 101;
	    Character::	def_ = 34;
	    Character::	life_ = 115;
	    Character::	dext_ = 32;
	    Monster::lootList = {19,24};
	}
};
