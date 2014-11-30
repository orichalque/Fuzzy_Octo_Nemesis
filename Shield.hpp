/**
 * \file Shield.hpp
 * \class Shield
 * \brief Shield equipement class. 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the abstract class Shield, inherited by all the concrete shield equipement
 *
 */

#ifndef __SHIELD_HPP__
#define __SHIELD_HPP_

class Shield : public Equipement {
	public:
	    Shield();
	    ~Shield();
		virtual bool isShield();
		
};

#endif

