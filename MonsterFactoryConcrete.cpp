#include "MonsterFactoryConcrete.hpp"
using namespace std;
MonsterFactoryConcrete::MonsterFactoryConcrete() {
}

MonsterFactoryConcrete::~MonsterFactoryConcrete() { 
}

shared_ptr<Monster> MonsterFactoryConcrete::getM() {
    return monster;
}

shared_ptr<Monster> MonsterFactoryConcrete::create(int i) {
    switch(i) {
        case 1:
            return make_shared<Gobelin>();
            break;
            
        case 2:
            return make_shared<Bat>();
            break;
            
        case 3:
            return make_shared<Orc>();
            break;
            
        case 4:
            return make_shared<Troll>();
            break;
            
        case 5:
            return make_shared<Kobold>();
            break;
            
        case 6:
            return make_shared<Sorcerer>();
            break;
            
        case 7:
            return make_shared<Squeleton>();
            break;
            
        case 8:
            return make_shared<HellHound>();
            break;
            
        case 9:
            return make_shared<Fantask>();
            break;
            
        case 10:
            return make_shared<Vampire>();
            break;
            
        case 11:
            return make_shared<Ghoul>();
            break;
            
        case 12:
            return make_shared<Golem>();
            break;
            
        case 13:
            return make_shared<Zombie>();
            break;
            
        case 14:
            return make_shared<Harpy>();
            break;
            
        case 15:
            return make_shared<ArchMagus>();
            break;
            
        case 16:
            return make_shared<Dragon>();
            break;
        
        case 17:
            return make_shared<Elemental>();
            break;
            
        case 18:
            return make_shared<Bully>();
            break;
            
        case 19:
            return make_shared<Eternal>();
            break;
            
        case 20:
            return make_shared<Invincible>();
            break;
  
         monster;
    };
}
