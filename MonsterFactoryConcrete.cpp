
#include "MonsterFactoryConcrete.hpp"
using namespace std;
MonsterFactoryConcrete::MonsterFactoryConcrete() {
}

MonsterFactoryConcrete::~MonsterFactoryConcrete() { 
}

shared_ptr<Monster> MonsterFactoryConcrete::create(int i) {
    switch(i) {
    	/* Level 1 */
        case 1:
            return make_shared<Gobelin>();
            break;
            
        case 2:
            return make_shared<Bat>();
            break;
            
        case 3:
            return make_shared<Orc>();
            break;
        /*********************/    
        
        /* Level 2 */    
        case 4:
            return make_shared<Kobold>();
            break;
            
        case 5:
            return make_shared<Sorcerer>();
            break;
            
        case 6:
            return make_shared<Squeleton>();
            break;
         /*********************/ 
          
        /* Level 3 */    
        case 7:
            return make_shared<Fantask>();
            break;
            
        case 8:
            return make_shared<Vampire>();
            break;
            
        case 9:
            return make_shared<Ghoul>();
            break;
         /*********************/ 
             
		/* Level 4 */
        case 10:
            return make_shared<Zombie>();
            break;
            
        case 11:
            return make_shared<Harpy>();
            break;
            
        case 12:
            return make_shared<ArchMagus>();
            break;
		/*********************/ 
		 
		/* Level 5 */
        case 13:
            return make_shared<Elemental>();
            break;
            
        case 14:
            return make_shared<Bully>();
            break;
            
        case 15:
            return make_shared<Eternal>();
            break;
		/*********************/ 
    };
}

