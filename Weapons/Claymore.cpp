/**
 * \file Claymore.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Claymore weapon equipement. High stats
 *
 */
 
 class Claymore : public Weapon {
    public:
        Claymore() {
            Item::name_ = "Claymore";
		    Item::desc_ = "Une monstrueuse épée large. Se tient à deux mains. ";
            Equipement::att = 36;
            Equipement::def = 8;
            Equipement::dext = 2;
        }

        
};
