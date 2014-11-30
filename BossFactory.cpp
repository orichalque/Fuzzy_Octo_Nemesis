#include "BossFactory.hpp"
using namespace std;

/**
 * \fn BossFactory::BossFactory()
 * \brief instancie la Fabrique de boss
 *
 * \param void
 * \return void
 *
 */
BossFactory::BossFactory() {
}

/**
 * \fn BossFactory::~BossFactory()
 * \brief détruit la Fabrique de boss
 *
 * \param void
 * \return void
 * 
 * Smart pointers utilisés, il n'y a rien à désallouer
 */
BossFactory::~BossFactory() { 
}

/**
 * \fn shared_ptr<Monster> BossFactory::create(int i)
 * \brief crée un boss et le renvoie
 *
 * \param int 
 * \return shared_ptr<Monster>
 * 
 * Crée et retourne le monstre qui correspond au niveau passé en entré.
 */
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
