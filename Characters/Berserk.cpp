/**
 * \file Berserk.hpp
 * \brief Concrete character
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Berserk character class. High Attack and low defense
 *
 */
class Berserk : public Character {
    public: 
        Berserk() {
            Character::desc_ = "Un violent combattant assoiffé de bataille. Bonne attaque et bonne santé. ";
            Character::name_ = "Berserk";
            Character::attack_ = 17;
            Character::def_ = 6;
            Character::life_ = 125;
            Character::maxLife_ = 125;
	        Character::dext_ = 5;
	        
	        Character::weapon = make_shared<ShortSword>();
        }
};
