#ifndef LEAF_HPP
#define LEAF_HPP

#include<iostream>
#include<stdint.h>
#include<vector>

class Leaf {
    private:
        int static const MIN_LEAF_SIZE = 5; //Min size of the leaf
        int static const MAX_LEAF_SIZE = 12;
        int x; // Room Position
        int y; 
        int height; // Dimensions of the leaf
        int width;
        Leaf *right; // Sons of the node
        Leaf *left;
        Rectangle *room; //The room, inside the leaf

    
    public:
        Leaf();
        Leaf(int x_, int y_, int width_, int height_);
        ~Leaf();
        void createRoom(vector<Rectangle> &halls);
        Rectangle* getRoom();
        void createHall(Rectangle l, Rectangle r, std::vector<Rectangle> &halls);
        void getStat();
        Leaf* getRight();
        Leaf* getLeft();
        int getWidth();
        int getHeight();
        int getX();
        int getY();
        bool split(std::vector<Leaf> &leafs);
		void getRoomsAndHalls();
};


#endif
        
