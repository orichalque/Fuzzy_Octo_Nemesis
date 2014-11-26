/**
 * \file SteelShield.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Steel shield equipement. High stats
 *
 */

class SteelShield : public Shield {
    public:
        SteelShield() {
            Item::name_ = "Bouclier en acier";
		    Item::desc_ = "Un solide bouclier d'acier. Très lourd. ";
            Equipement::att = 0;
            Equipement::def = 14;
            Equipement::dext = -4;                         
        }
};

