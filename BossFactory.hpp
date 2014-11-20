#ifndef __BOSSFACTORY_HPP__
#define __BOSSFACTORY_HPP__

class BossFactory : public MonsterFactory {
    private:
    
    public:
        BossFactory();
        ~BossFactory();
        shared_ptr<Monster> create(int i);
};

#endif
