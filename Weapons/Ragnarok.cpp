/**
 * \file Ragnarok.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Ragnarok weapon equipement. Very high stats
 *
 */
 
 /**
 * \class Ragnarok
 * \brief Define a concrete weapon for equiping
 */
class Ragnarok : public Weapon {
    public:
       /**
        * \fn Ragnarok()
        * \brief Instancie une arme concrete avec des attributs pré-définis
        * \param void 
        * \return void 
        */    
        Ragnarok() {
            Item::name_ = "Ragnarok";
		    Item::desc_ = "La lame maîtresse à la puissance incommensurable. ";
            Equipement::att = 74;
            Equipement::def = 18;
            Equipement::dext = 15;
        }
        
        

};
