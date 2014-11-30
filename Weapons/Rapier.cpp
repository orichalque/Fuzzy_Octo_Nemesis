/**
 * \file Rapier.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Rapier weapon equipement. medium stats
 *
 */
 
 /**
 * \class Rapier
 * \brief Define a concrete weapon for equiping
 */
 class Rapier : public Weapon {
    public:
       /**
        * \fn Rapier()
        * \brief Instancie une arme concrete avec des attributs pré-définis
        * \param void 
        * \return void 
        */    
        Rapier() {
            Item::name_ = "Rapière";
		    Item::desc_ = "Une fine lame horriblement affutée";
            Equipement::att = 33;
            Equipement::def = 7;
            Equipement::dext = 11;
        }
        
};
