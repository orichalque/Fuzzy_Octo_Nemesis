/**
 * \file SteelArmor.hpp
 * \brief Concrete armor 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * SteelArmor for equiping
 *
 */

 /**
  * \class SteelArmor
  * \brief Concrete armor for equiping
  */
 class SteelArmor : public Armor {
    public:
        /**
         * \fn SteelArmor()
         * \brief instancie une armure avec des attributs définis
         * \param void
         * \return void
         */
        SteelArmor() {
            Item::name_ = "Armure en acier";
		    Item::desc_ = "Une belle armure en acier, très resistante. ";
            Equipement::att = 0;
            Equipement::def = 22;
            Equipement::dext = 0;
                            
        }
};

