#ifndef MONSTERFACTORY_HPP
#define MONSTERFACTORY_HPP

#include<memory>
#include"Monster.cpp"
#include"Monsters.hpp"


class MonsterFactory {
    protected:
        std::shared_ptr<Monster> monster;
    
    public:
        MonsterFactory();
        ~MonsterFactory();
        virtual shared_ptr<Monster> create(int i) = 0;
     
};

#endif
