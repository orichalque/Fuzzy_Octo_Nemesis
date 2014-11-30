/**
 * \file SteelHelm.cpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * SteelHelm equipement. Medium stats
 *
 */
 
 /**
* \class SteelHelm
* \brief define a concrete helmet
*/
class SteelHelm : public Helmet {
    public:
       /**
        * \fn SteelHelm()
        * \brief Instancie un casque concret avec des attributs définis
        * \param void
        * \return void
        */    
        SteelHelm() {
            Item::name_ = "Casque en acier";
		    Item::desc_ = "Un casque en acier hérissé de pointes métalliques. ";
            Equipement::att = 2;
            Equipement::def = 12;
            Equipement::dext = 1;
                            
        }
};

