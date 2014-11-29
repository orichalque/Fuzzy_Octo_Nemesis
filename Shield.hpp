/**
 * \file Shield.hpp
 * \brief Shield equipement class. 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the abstract class Shield, inherited by all the concrete shield equipement
 *
 */

#ifndef Shield_HPP
#define Shield_HPP

class Shield : public Equipement {
	public:
	    ~Shield();
		virtual bool isShield();
		virtual bool isEquipement();
		
};

#endif

