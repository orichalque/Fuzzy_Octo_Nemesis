/**
 * \file Excalibur.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Excalibur weapon equipement. high stats
 *
 */
 class Excalibur : public Weapon {
    public:
        Excalibur() {
            Item::name_ = "Excalibur";
		    Item::desc_ = "Elle dégage une aura sacrée";
            Equipement::att = 41;
            Equipement::def = 9;
            Equipement::dext = 9;
        }
        

};
