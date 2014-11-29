/**
 * \file Squeleton.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 class Squeleton : public Monster {
    public: 
	Squeleton() {
		Character::desc_ = "Un Squelette avec une épée et un bouclier";
		Character::name_ = "Squelette";
		Character::symbol_ = 'S';
		Character::attack_ = 18;
		Character::def_ = 17;
		Character::life_ = 65;
		Character::dext_ = 13;
		Monster::lootList = {4, 21};
	}
};
