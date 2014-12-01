/**
 * \file Gobelin.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 /**
* \class Gobelin
* \brief Define a concrete Monster
*/ 
class Gobelin : public Monster {
    public: 
    /**
    * \fn Gobelin()
    * \brief Instancie un monstre concret avec ses attributs définis
    * \param void 
    * \return void
    */    
	    Gobelin() {
		    Character::desc_ = "Un gobelin verreux";
		    Character::name_ = "Gobelin";
		    Character::symbol_ = 'G';
		    Character::attack_ = 19;
		    Character::def_ = 5;
		    Character::life_ = 35;
		    Character::dext_ = 8;
		    lootList = {1, 10};
	    }
};

