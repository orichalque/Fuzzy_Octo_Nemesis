/**
 * \file Kunee.hpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Kunee equipement. Very high stats
 *
 */

class Kunee : public Helmet {
    public:
        Kunee() {
            Item::name_ = "Kunée";
		    Item::desc_ = "Le casque légendaire Kunée. Il dégage une atmosphère confortante. ";
            Equipement::att = 4;
            Equipement::def = 25;
            Equipement::dext = 7;
                            
        }
};

