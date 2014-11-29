/**
 * \file ShortSword.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Short sword weapon equipement. low stats
 *
 */
 
class ShortSword : public Weapon {
    public:
        ShortSword() {
            Item::name_ = "Epee courte";
		    Item::desc_ = "Une épée courte à la lame bien affutée. ";
            Equipement::att = 18;
            Equipement::def = 6;
            Equipement::dext = 3;
        }
        
};
