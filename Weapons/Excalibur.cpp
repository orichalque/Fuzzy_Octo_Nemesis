/**
 * \file Excalibur.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Excalibur weapon equipement. high stats
 *
 */
 
 /**
 * \class Excalibur
 * \brief Define a concrete weapon for equiping
 */
 class Excalibur : public Weapon {
    public:
       /**
        * \fn Excalibur()
        * \brief Instancie une arme concrete avec des attributs pré-définis
        * \param void 
        * \return void 
        */    
        Excalibur() {
            Item::name_ = "Excalibur";
		    Item::desc_ = "Elle dégage une aura sacrée";
            Equipement::att = 41;
            Equipement::def = 9;
            Equipement::dext = 9;
        }
        

};
