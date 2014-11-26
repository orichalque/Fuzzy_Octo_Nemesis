/**
 * \file BossFactory.hpp
 * \brief Factory returning bosses
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * one of the factory classes from the Factory Pattern
 *
 */

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
