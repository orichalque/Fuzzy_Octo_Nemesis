/**
 * \file LeatherArmor.hpp
 * \brief Concrete armor 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * LeatherArmor for equiping
 *
 */
class LeatherArmor : public Armor {
    public:
        LeatherArmor() {
            Item::name_ = "Armure en cuir";
		    Item::desc_ = "Une armure en cuir. Souple mais peu résistante. ";
            Equipement::att = 0;
            Equipement::def = 8;
            Equipement::dext = 2;
                            
        }
};

