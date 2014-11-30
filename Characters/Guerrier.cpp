/**
 * \file Guerrier.hpp
 * \brief Concrete character
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Guerrier character class. Middle attack and Middle defense
 *
 */
 
/**
 * \class Guerrier
 * \brief Character concrete class 
 */
class Guerrier : public Character {
    public:
       /**
        * \fn Guerrier()
        * \brief Instancie un personnage avec des attributs définis
        * \param void 
        * \return void
        */
        Guerrier() {
            Character::desc_ = "Un guerrier habitué du combat. Bonne attaque et défense. ";
            Character::name_ = "Guerrier";
            Character::attack_ = 12;
            Character::def_ = 10;
            Character::life_ = 75;
            Character::maxLife_ = 75;
	        Character::dext_ = 5;
	        
	        Character::weapon = make_shared<Dagger>();
	        Character::armor = make_shared<LeatherArmor>();
        }
};

