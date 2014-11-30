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

/**
* \class Barrel
* \brief Define a concrete shield
*/
class Barrel : public Shield {
    public:
       /**
        * \fn Barrel()
        * \brief Instancie une armure concrete avec des attributs pré-définis
        * \param void
        * \return void
        */
        Barrel() {
            Item::name_ = "Couvercle";
		    Item::desc_ = "Un couvercle de tonneau avec une poignée. Fragile.";
            Equipement::att = 0;
            Equipement::def = 4;
            Equipement::dext = 0;
                            
        }
};

