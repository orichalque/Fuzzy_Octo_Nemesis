/**
 * \file Wall.hpp
 * \brief Concrete armor 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Wall for equiping. Best Armor of the game
 *
 */
 
 /**
  * \class Wall
  * \brief Concrete armor for equiping
  */
 class Wall : public Armor {
    public:
        /**
         * \fn Wall()
         * \brief instancie une armure avec des attributs définis
         * \param void
         * \return void
         */
        Wall() {
            Item::name_ = "La Muraille";
		    Item::desc_ = "L\'armure ultime, réputée infranchissable. ";
            Equipement::att = 5;
            Equipement::def = 40;
            Equipement::dext = 5;
                            
        }
};

