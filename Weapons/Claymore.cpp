/**
 * \file Claymore.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Claymore weapon equipement. High stats
 *
 */
 
/** 
 * \class Claymore
 * \brief Define a concrete weapon for equiping
 */
 class Claymore : public Weapon {
    public:
       /**
        * \fn Claymore()
        * \brief Instancie une arme concrete avec des attributs pré-définis
        * \param void 
        * \return void 
        */
        Claymore() {
            Item::name_ = "Claymore";
		    Item::desc_ = "Une monstrueuse épée large. Se tient à deux mains. ";
            Equipement::att = 36;
            Equipement::def = 8;
            Equipement::dext = 2;
        }

        
};
