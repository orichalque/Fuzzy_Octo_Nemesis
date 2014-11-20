#ifndef LEAF_HPP
#define LEAF_HPP

#include<iostream>
#include<stdint.h>
#include<vector>

class Leaf {
    private:
        int static const MIN_LEAF_SIZE = 6; //Min size of the leaf
        int static const MAX_LEAF_SIZE = 15;
        int x; // Room Position
        int y; 
        int height; // Dimensions of the leaf
        int width;
        Leaf *right; // Sons of the node
        Leaf *left;
        Rectangle *room; //The room, inside the leaf
        bool linked;
        bool empty;

    
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
        

