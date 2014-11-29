#include "BossFactory.hpp"
using namespace std;
BossFactory::BossFactory() {
}

BossFactory::~BossFactory() { 
}

shared_ptr<Monster> BossFactory::create(int i) {
    switch(i) {
        case 1:
            return make_shared<Troll>();
            break;
            
        case 2:
            return make_shared<HellHound>();
            break;
            
        case 3:
            return make_shared<Golem>();
            break;
            
        case 4:
            return make_shared<Dragon>();
            break;
            
        case 5:
            return make_shared<Invincible>();
            break;
            
        
    };
}
