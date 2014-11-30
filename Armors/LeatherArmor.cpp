/**
 * \file LeatherArmor.hpp
 * \brief Concrete armor 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * LeatherArmor for equiping
 *
 */
 
 /**
  * \class LeatherArmor
  * \brief Concrete armor for equiping
  */
class LeatherArmor : public Armor {
    public:
        /**
         * \fn LeatherArmor()
         * \brief instancie une armure avec des attributs définis
         * \param void
         * \return void
         */
        LeatherArmor() {
            Item::name_ = "Armure en cuir";
		    Item::desc_ = "Une armure en cuir. Souple mais peu résistante. ";
            Equipement::att = 0;
            Equipement::def = 8;
            Equipement::dext = 2;
                            
        }
};

