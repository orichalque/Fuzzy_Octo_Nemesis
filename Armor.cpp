/**
 * \file Armor.cpp
 * \brief Armor class for FuzzyOctoNemesis
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the abstract class Armor 
 *
 */

#include "Armor.hpp"

using namespace std;

/**
 * \fn Armor::Armor()
 * \brief instancie une armure
 *
 * \param void
 * \return void
 *
 */
Armor::Armor() 
{

}

/**
 * \fn Armor::~Armor()
 * \brief détruit une armure
 *
 * \param void
 * \return void
 *
 */
Armor::~Armor() {

}

/**
 * \fn Armor::isArmor()
 * \brief renvoit vrai si c'est une armure
 *
 * \param void
 * \return bool
 *
 * @Override
 */
bool Armor::isArmor()
{
	return true;
}


