/**
 * \file LongSword.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Long sword weapon equipement. medium stats
 *
 */
 
 /**
 * \class LongSword
 * \brief Define a concrete weapon for equiping
 */
 class LongSword : public Weapon {
    public:
       /**
        * \fn LongSword()
        * \brief Instancie une arme concrete avec des attributs pré-définis
        * \param void 
        * \return void 
        */    
        LongSword() {
            Item::name_ = "Epee longue";
		    Item::desc_ = "Une épée longue tranchante comme un rasoir. ";
            Equipement::att = 24;
            Equipement::def = 6;
            Equipement::dext = 6;
        }
        
};
