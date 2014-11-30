/**
 * \file MonsterFactory.hpp
 * \class MonsterFactory
 * \brief Monster Factory returning the monsters of F.O.N.
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Abstract mother-class of the 2 Monster Factories
 *
 */

#ifndef MONSTERFACTORY_HPP
#define MONSTERFACTORY_HPP

class MonsterFactory {
    protected:
		    
    public:
        MonsterFactory();
        ~MonsterFactory();
        virtual shared_ptr<Monster> create(int i) = 0;
     
};

#endif
