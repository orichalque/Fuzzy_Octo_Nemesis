/**
 * \file IronShield.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Iron shield equipement. Medium stats
 *
 */
 class IronShield : public Shield {
    public:
        IronShield() {
            Item::name_ = "Bouclier en fer";
		    Item::desc_ = "Un classique bouclier en fer. Encombrant. ";
            Equipement::att = 0;
            Equipement::def = 11;
            Equipement::dext = -2;
                            
        }
};

