/**
 * \file Helmet.hpp
 * \brief Helmet equipement class
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the Helmet methods, inherited from Equipement class
 *
 */

#ifndef HELMET_HPP
#define HELMET_HPP

class Helmet : public Equipement
{
	public:
	    Helmet();
	    ~Helmet();
		virtual bool isHelmet();
		virtual bool isEquipement();
		
};

#endif

