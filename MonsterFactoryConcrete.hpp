#ifndef __MONSTERFACTORYCONCRETE_HPP__
#define __MONSTERFACTORYCONCRETE_HPP__

#include "MonsterFactory.cpp"
class MonsterFactoryConcrete : public MonsterFactory {
    private:
    
    public:
        MonsterFactoryConcrete();
        ~MonsterFactoryConcrete();
        shared_ptr<Monster> create(int i);
        shared_ptr<Monster> getM();
};

#endif
