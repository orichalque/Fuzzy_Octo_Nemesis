/**
 * \file Dagger.cpp
 * \brief Concrete weapon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Dagger weapon equipement. Low stats
 *
 */
 
 /**
 * \class Dagger
 * \brief Define a concrete weapon for equiping
 */
 class Dagger : public Weapon {
    public:
       /**
        * \fn Dagger()
        * \brief Instancie une arme concrete avec des attributs pré-définis
        * \param void 
        * \return void 
        */    
        Dagger() {
            Item::name_ = "Dague";
		    Item::desc_ = "Une dague affutée.";
            Equipement::att = 12;
            Equipement::def = 3;
            Equipement::dext = 4;
        }

};
