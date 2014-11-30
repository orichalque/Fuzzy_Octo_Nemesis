/**
 * \file EquipementFactory.hpp
 * \class EquipementFactory
 * \brief client class for FuzzyOctoNemesis
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Equipement factory returning the equipement when necessary.
 * Part of the Factory Method pattern
 */

#ifndef __EQUIPEMENTFACTORY_HPP__
#define __EQUIPEMENTFACTORY_HPP__

class EquipementFactory : public Factory {
	private:
	
	public:
		EquipementFactory();
		~EquipementFactory();
		shared_ptr<Equipement> create(int i);
};

#endif
