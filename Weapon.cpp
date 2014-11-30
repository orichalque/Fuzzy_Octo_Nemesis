#include "Weapon.hpp"

using namespace std;

/**
 * \fn Weapon::Weapon()
 * \brief instancie une arme
 *
 * \param void
 * \return void
 *
 */
Weapon::Weapon() { 

}

/**
 * \fn Weapon::~Weapon()
 * \brief détruit une arme
 *
 * \param void
 * \return void
 *
 */
Weapon::~Weapon() {

}

/**
 * \fn bool Weapon::isWeapon()
 * \brief renvoit vrai si c'est une arme
 *
 * \param void
 * \return bool
 *
 * @Override
 */
bool Weapon::isWeapon()
{
	return true;
}



