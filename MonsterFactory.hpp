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
