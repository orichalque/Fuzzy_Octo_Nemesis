/**
 * \file Leaf.hpp
 * \class Leaf
 * \brief Class definition for manipulating the rooms of the dungeon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 */
#ifndef __LEAF_HPP__
#define __LEAF_HPP__

class Leaf {
    private:
        int static const MIN_LEAF_SIZE = 8; /*!< Min size of the leaf */
        int static const MAX_LEAF_SIZE = 17; /*!< Max size of the leaf */
        int x; /*!<Room Position */
        int y; /*!<Room position */
        int height; /*!< height of the leaf */
        int width; /*!< width of the leaf */
        Leaf *right; /*!< right son of the node */
        Leaf *left; /*!< left son of the node */
        Rectangle *room; /*!< The room, inside the leaf */
        bool linked; /*!< True is the room has no hall */
        bool empty; /*!< True if the room has no monster */

    
    public:
        Leaf();
        Leaf(int x_, int y_, int width_, int height_);
        ~Leaf();
        
        Leaf* getRight();
        Leaf* getLeft();
        Rectangle* getRoom();
        int getRoomSurface();
        int getRoomCenterX();
        int getRoomCenterY();
        bool isJoined();
        bool isEmpty();
		void setFull();
        
        bool split(vector<Leaf*> *leafs, int seed);
        bool createRoom(int seed);
        void getInfo();
        void getInfoRec();
        void join();
};


int randomize(int min, int max, int seed);

#endif
        

