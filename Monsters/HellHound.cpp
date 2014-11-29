/**
 * \file HellHound.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Boss for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 class HellHound : public Monster {
    public: 
	HellHound() {
		Character::desc_ = "Un monstrueux chien avec des yeux enflammés";
		Character::name_ = "Chien de l\'enfer";
		Character::attack_ = 29;
		Character::def_ = 19;
		Character::life_ = 100;
		Character::dext_ = 16;
		Character::symbol_ = 'H';
		Monster::lootList = {7 , 12, 17, 22};
	}
	
	
	bool isBoss() {
		return true;
	}
};
