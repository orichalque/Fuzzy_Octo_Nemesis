#include "Equipement.hpp"

/**
 * \fn bool Equipement::~Equipement()
 * \brief Destructeur d'equipement
 *
 * \param void
 * \return void
 *
 * utilisation de SmartPointers, le destructeur est vide
 */ 
Equipement::~Equipement() {

}

/**
 * \fn bool Equipement::isEquipement()
 * \brief Renvoit vrai si c'est un equipement
 *
 * \param void
 * \return bool
 *
 * @Override
 */ 
bool Equipement::isEquipement() {
	return true;
}	    

/**
 * \fn int Equipement::getAtt()
 * \brief Renvoit l'attaque de l'equipement
 *
 * \param void
 * \return int
 *
 * @Override
 */ 
int Equipement::getAtt() {
	return att;
}

/**
 * \fn int Equipement::getDef()
 * \brief Renvoit la défense de l'equipement
 *
 * \param void
 * \return int
 *
 * @Override
 */ 
int Equipement::getDef() {
	return def;
}

/**
 * \fn int Equipement::getDext()
 * \brief Renvoit la dextérité de l'equipement
 *
 * \param void
 * \return int
 *
 * @Override
 */ 		
int Equipement::getDext() {
	return dext;
}

/**
 * \fn bool Equipement::isHelmet()
 * \brief Renvoit faux si c'est un casque.
 *
 * \param void
 * \return bool
 *
 * @Ecrasé dans les classes filles
 */ 
bool Equipement::isHelmet() {
    return false;
}

/**
 * \fn bool Equipement::isShield()
 * \brief Renvoit faux si c'est un bouclier.
 *
 * \param void
 * \return bool
 *
 * @Ecrasé dans les classes filles
 */
bool Equipement::isShield(){
    return false;
}

/**
 * \fn bool Equipement::isArmor()
 * \brief Renvoit faux si c'est une armure
 *
 * \param void
 * \return bool
 *
 * @Ecrasé dans les classes filles
 */
bool Equipement::isArmor(){
    return false;
}

/**
 * \fn bool Equipement::isWeapon()
 * \brief Renvoit faux si c'est une arme
 *
 * \param void
 * \return bool
 *
 * @Ecrasé dans les classes filles
 */
bool Equipement::isWeapon(){
    return false;
}
