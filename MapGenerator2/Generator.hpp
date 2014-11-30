/**
 * \file Generator.hpp
 * \class Generator
 * \brief Class definition for manipulating the matrix
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 */

#ifndef __GENERATOR_HPP__
#define __GENERATOR_HPP__
 
class Generator {
    private:
        int static const SIZE = 32; /*!< Size of the square map */
        std::vector<Leaf*> leafs; /*!< vector with all the terminal leafs */
        std::vector<Rectangle*> halls; /*!< vector with all the halls of the map */
        Leaf* root;  /*!< root of the BSP tree */
        std::vector< std::vector<char> > mat; /*!< Matrix width the map in it */
                 
    public:
        Generator();
        ~Generator();
        int getSize();
        void split();
        void createRoom();
        void createHalls();
        void buildMap();
        bool findLeaf(Rectangle* l);
        void init();
        char placeCharacter(shared_ptr<Character> c);
        shared_ptr<Monster> placeBoss(int level, shared_ptr<BossFactory> bf);
        vector< shared_ptr<Monster> > placeMonsters(int level, shared_ptr<MonsterFactoryConcrete> mfc, shared_ptr<BossFactory> bf);
        vector< vector<char> >  getMap();
        char updateCharPosition(shared_ptr<Character> character);
    
};

#endif

