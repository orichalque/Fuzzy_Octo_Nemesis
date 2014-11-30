/**
 * \file Egid.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Egid equipement. Very High stats
 *
 */

/**
* \class Egid
* \brief Define a concrete shield
*/
 class Egid : public Shield {
    public:
       /**
        * \fn Egid()
        * \brief Instancie une armure concrete avec des attributs pré-définis
        * \param void
        * \return void
        */    
        Egid() {
            Item::name_ = "Egide";
		    Item::desc_ = "L'égide, l'assurance d'une protection fiable. ";
            Equipement::att = 0;
            Equipement::def = 24;
            Equipement::dext = -6;                         
        }
};

