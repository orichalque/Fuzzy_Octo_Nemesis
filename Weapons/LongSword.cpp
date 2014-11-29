/**
 * \file LongSword.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Long sword weapon equipement. medium stats
 *
 */
 class LongSword : public Weapon {
    public:
        LongSword() {
            Item::name_ = "Epee longue";
		    Item::desc_ = "Une épée longue tranchante comme un rasoir. ";
            Equipement::att = 24;
            Equipement::def = 6;
            Equipement::dext = 6;
        }
        
};
