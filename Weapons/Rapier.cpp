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
 class Rapier : public Weapon {
    public:
        Rapier() {
            Item::name_ = "Rapière";
		    Item::desc_ = "Une fine lame horriblement affutée";
            Equipement::att = 33;
            Equipement::def = 7;
            Equipement::dext = 11;
        }
        
};
