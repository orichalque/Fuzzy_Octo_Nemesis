/**
 * \file SteelArmor.hpp
 * \brief Concrete armor 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * SteelArmor for equiping
 *
 */
 class SteelArmor : public Armor {
    public:
        SteelArmor() {
            Item::name_ = "Armure en acier";
		    Item::desc_ = "Une belle armure en acier, très resistante. ";
            Equipement::att = 0;
            Equipement::def = 22;
            Equipement::dext = 0;
                            
        }
};

