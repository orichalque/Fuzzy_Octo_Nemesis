/**
 * \file ArchMagus.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 
class ArchMagus : public Monster {
    public: 
	ArchMagus() {
		Character::desc_ = "Un archimage dégageant une aura sinistre";
        Character::name_ = "Archimage";
        Character::attack_ = 52;
        Character::def_ = 23;
        Character::life_ = 99;
		Character::dext_ = 27;	
		Character::symbol_ = 'A';
		Monster::lootList = {6 ,13 };
	}
};




