/**
 * \file LeatherShield.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Leather shield equipement. Medium stats
 *
 */
 
/**
* \class LeatherShield
* \brief Define a concrete shield
*/
class LeatherShield : public Shield {
    public:
       /**
        * \fn LeatherShield()
        * \brief Instancie une armure concrete avec des attributs pré-définis
        * \param void
        * \return void
        */    
        LeatherShield() {
            Item::name_ = "Bouclier en cuir";
		    Item::desc_ = "Un bouclier en bois, recouvert de cuir. ";
            Equipement::att = 0;
            Equipement::def = 8;
            Equipement::dext = -1;
                            
        }
};

