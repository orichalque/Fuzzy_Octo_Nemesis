/**
 * \file Orc.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 class Orc : public Monster {
    public: 
	Orc() {
		Character::desc_ = "Un orc à l'allure aggressive";
		Character::name_ = "Orc";
		Character::symbol_ = 'O';
		Character::attack_ = 18;
		Character::def_ = 11;
		Character::life_ = 45;
		Character::dext_ = 6;
		Monster::lootList = {2, 20};
	}
};
