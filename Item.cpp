#include "Item.hpp"

using namespace std;

/**
 * \fn string Item::getName()
 * \brief getter de l'attribut nom
 *
 * \param void
 * \return string
 *
 */ 
string Item::getName()
{
	return name_;
}

/**
 * \fn string Item::getDescription()
 * \brief getter de l'attribut description
 *
 * \param void
 * \return string
 *
 */ 
string Item::getDescription()
{
	return desc_;
}

/**
 * \fn int Item::getValue()
 * \brief getter de l'attribut value
 * \deprecated Value oubliée. Inutile.
 * \param void
 * \return int
 *
 */ 
int Item::getValue()
{
	return value_;
}

/**
 * \fn bool Item::isConsumable()
 * \brief vrai si l'objet est consommable
 * \deprecated Deprecié
 * \param void
 * \return bool
 *
 */ 
bool Item::isConsumable()
{
	return consumable_;
}

/**
 * \fn bool Item::isSettable()
 * \brief vrai si l'objet est utilisable
 * \deprecated Deprecié
 * \param void
 * \return bool
 *
 */ 
bool Item::isSettable()
{
	return settable_;
}

/**
 * \fn bool Item::isEquipement()
 * \brief renvoie toujours faux. Ecrasé dans les classes filles d'equipement
 * \param void
 * \return bool
 *
 */ 
bool Item::isEquipement() {
    return false;
}

