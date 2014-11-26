/**
 * \file IronArmor.hpp
 * \brief Concrete armor 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * IronArmor for equiping
 *
 */
 
 class IronArmor : public Armor {
    public:
        IronArmor() {
            Item::name_ = "Armure en fer";
		    Item::desc_ = "Un armure en fer légèrement rouillée. ";
            Equipement::att = 0;
            Equipement::def = 15;
            Equipement::dext = 1;
                            
        }
};

