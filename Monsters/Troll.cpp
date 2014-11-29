/**
 * \file Troll.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Boss for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 
class Troll : public Monster {
    public: 
	Troll() {
		Character::desc_ = "Un immense troll à l\'imposante massue.";
		Character::name_ = "Troll";
		Character::attack_ = 22;
		Character::def_ = 15;
		Character::life_ = 75;
		Character::dext_ = 9;
		Character::symbol_ = 'T';
		Monster::lootList = {3,11,16,21};
	}
	
	bool isBoss() {
		return true;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
