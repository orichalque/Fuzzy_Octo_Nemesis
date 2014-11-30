/**
 * \file Equipement.hpp
 * \brief Equipement abstract class definition 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the Equipement class, mother-class of all the equipement in the game
 *
 */

#ifndef EQUIPEMENT_HPP
#define EQUIPEMENT_HPP

class Equipement : public Item {
	protected :
		int att; /*!<Attaque de l'arme */
	    int def; /*!<Defense de l'arme */
		int dext; /*!<Dextérité de l'arme */
	
	public:
	    ~Equipement();
		virtual bool isEquipement();
		virtual int getAtt();
		virtual	int getDef();
		virtual	int getDext();
		virtual bool isHelmet();
		virtual bool isShield();
		virtual bool isArmor();
		virtual bool isWeapon();
		
		
};

#endif
