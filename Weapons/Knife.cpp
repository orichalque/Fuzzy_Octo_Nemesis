/**
 * \file Dagger.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Knife weapon equipement. low stats
 *
 */
 class Knife : public Weapon {
    public:
        Knife() {
            Item::name_ = "Couteau";
		    Item::desc_ = "Un petit couteau de cuisine. Mal barré";
            Equipement::att = 5;
            Equipement::def = 0;
            Equipement::dext = 1;
        }
        

};
