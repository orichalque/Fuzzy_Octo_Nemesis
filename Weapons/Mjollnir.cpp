/**
 * \file Mjollnir.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Mjollnir weapon equipement. High stats
 *
 */
 class Mjollnir : public Weapon {
    public:
        Mjollnir() {
            Item::name_ = "Mjollnir";
		    Item::desc_ = "Ce marteau est dévastateur, mais terriblement lourd. ";
            Equipement::att = 51;
            Equipement::def = 15;
            Equipement::dext = 9;
        }

};
