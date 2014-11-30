/**
 * \file Factory.hpp
 * \class Factory
 * \brief factory mother-class for FuzzyOctoNemesis
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Virtual pure class defining the basics of the factories
 * Used in the Pattern Factory Method
 *
 */
 
#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

class Factory {
	private:
	
	public:
		Factory();
		~Factory();
		virtual shared_ptr<Equipement> create(int i) = 0;
	
};

#endif
