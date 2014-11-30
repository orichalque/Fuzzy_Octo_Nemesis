/**
 * \file MonsterFactoryConcrete.hpp
 * \class MonsterFactoryConcrete
 * \brief Monster Factory returning the monsters of F.O.N.
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Return the monsters of the dungeon, by entering their ID 
 *
 */
 
#ifndef __MONSTERFACTORYCONCRETE_HPP__
#define __MONSTERFACTORYCONCRETE_HPP__

class MonsterFactoryConcrete : public MonsterFactory {
    private:
    
    public:
        MonsterFactoryConcrete();
        ~MonsterFactoryConcrete();
        shared_ptr<Monster> create(int i);
};

#endif
