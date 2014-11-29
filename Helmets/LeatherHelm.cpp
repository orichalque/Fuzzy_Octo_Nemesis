/**
 * \file LeatherHelm.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * leatherHelm equipement. Low stats
 *
 */
 
class LeatherHelm : public Helmet {
    public:
        LeatherHelm() {
            Item::name_ = "Casque en cuir";
		    Item::desc_ = "Un casque en cuir, léger mais peu résistant. ";
            Equipement::att = 0;
            Equipement::def = 4;
            Equipement::dext = 1;
                            
        }
};

