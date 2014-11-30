/**
 * \file MithrilArmor.hpp
 * \brief Concrete armor 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * MithrilArmor for equiping
 *
 */
 
 /**
  * \class MithrilArmor
  * \brief Concrete armor for equiping
  */
class MithrilArmor : public Armor {
    public:
        /**
         * \fn MithrilArmor()
         * \brief instancie une armure avec des attributs définis
         * \param void
         * \return void
         */
        MithrilArmor() {
            Item::name_ = "Armure en mithril";
		    Item::desc_ = "Une somptueuse armure en mithril, légère comme du cuir et dure comme de la pierre. ";
            Equipement::att = 2;
            Equipement::def = 27;
            Equipement::dext = 4;
                            
        }
};

