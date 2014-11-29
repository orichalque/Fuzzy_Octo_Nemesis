/**
 * \file Barrel.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Barrel equipement. Low stats
 *
 */
 
class Barrel : public Shield {
    public:
        Barrel() {
            Item::name_ = "Couvercle";
		    Item::desc_ = "Un couvercle de tonneau avec une poignée. Fragile.";
            Equipement::att = 0;
            Equipement::def = 4;
            Equipement::dext = 0;
                            
        }
};

