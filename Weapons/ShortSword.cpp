/**
 * \file ShortSword.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Short sword weapon equipement. low stats
 *
 */
 
 /**
 * \class ShortSword
 * \brief Define a concrete weapon for equiping
 */
class ShortSword : public Weapon {
    public:
       /**
        * \fn ShortSword()
        * \brief Instancie une arme concrete avec des attributs pré-définis
        * \param void 
        * \return void 
        */    
        ShortSword() {
            Item::name_ = "Epee courte";
		    Item::desc_ = "Une épée courte à la lame bien affutée. ";
            Equipement::att = 18;
            Equipement::def = 6;
            Equipement::dext = 3;
        }
        
};
