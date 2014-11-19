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
