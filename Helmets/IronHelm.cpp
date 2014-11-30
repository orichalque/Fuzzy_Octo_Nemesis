/**
 * \file ironHelm.hpp
 * \brief Concrete equipement
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * ironHelm equipement. Low stats
 *
 */
 
/**
* \class IronHelm
* \brief define a concrete helmet
*/
class IronHelm : public Helmet {
    public:
       /**
        * \fn IronHelm()
        * \brief Instancie un casque concret avec des attributs définis
        * \param void
        * \return void
        */
        IronHelm() {
            Item::name_ = "Casque en fer";
		    Item::desc_ = "Un casque en fer, avec des renforts latéraux en cuir. ";
            Equipement::att = 0;
            Equipement::def = 9;
            Equipement::dext = 0;
                            
        }
};

