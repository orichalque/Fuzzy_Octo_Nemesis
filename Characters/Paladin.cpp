/**
 * \file Paladin.hpp
 * \brief Concrete character
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Paladin character class. High defense
 *
 */
 
class Paladin : public Character {
    public:
        Paladin() {
            Character::desc_ = "Un soldat en armure. Bonne défense. ";
            Character::name_ = "Paladin";
            Character::attack_ = 10;
            Character::def_ = 14;
            Character::life_ = 75;
            Character::maxLife_ = 75;
	        Character::dext_ = 5;
	        
	        Character::weapon = make_shared<Knife>();
	        Character::shield = make_shared<Barrel>();
	        Character::armor = make_shared<LeatherArmor>();
	        
        }
};
