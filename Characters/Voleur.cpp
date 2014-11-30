/**
 * \file Voleur.hpp
 * \brief Concrete character
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Voleur character class. High dexterity, low stats
 *
 */

/**
 * \class Voleur
 * \brief Character concrete class 
 */
class Voleur : public Character {
    public:
        /**
        * \fn Voleur()
        * \brief Instancie un personnage avec des attributs définis
        * \param void 
        * \return void
        */    
        Voleur() {
            Character::desc_ = "Un brigand au pas souple et rapide. Bonne dextérité. ";
            Character::name_ = "Voleur";
            Character::attack_ = 9;
            Character::def_ = 7;
            Character::life_ = 70;
            Character::maxLife_ = 70;
	        Character::dext_ = 10;
	        
	        Character::weapon = make_shared<Dagger>();
	        Character::helmet = make_shared<LeatherHelm>();
	        
	        
        }
};
