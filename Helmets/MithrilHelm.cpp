/**
 * \file MithrilHelm.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * MithrilHelm equipement. High Stats
 *
 */
 
class MithrilHelm : public Helmet {
    public:
        MithrilHelm() {
            Item::name_ = "Casque en mithril";
		    Item::desc_ = "Un casque en mithril, léger et pourtant très resistant. ";
            Equipement::att = 2;
            Equipement::def = 17;
            Equipement::dext = 5;
                            
        }
};

