#include"Leaf.hpp"
#include<cstdlib>

using namespace std;
Leaf::Leaf() {
    x = y = width = height = 0;
    right = NULL;
    left = NULL;
}


Leaf::Leaf(int x_, int y_, int width_, int height_) {
    x = x_;
    y = y_;
    width = width_;
    height = height_;
    right = NULL;
    left = NULL;
}

Leaf::~Leaf() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    right = NULL;
    left = NULL;
}

void Leaf::getStat() {
    cout << "Feuille en " << x << ":" << y << " De taille " << width << " x " << height << endl;
}

Leaf* Leaf::getRight() {
    return right;
}

Leaf* Leaf::getLeft() {
    return left;
}

int Leaf::getHeight() {
    return height;
}

int Leaf::getWidth() {
    return width;
}

bool Leaf::split(vector<Leaf> &leafs) { //Divide the room in 2 distincts room    
    if (left != NULL || right != NULL || (getWidth() <= MIN_LEAF_SIZE  && getHeight() <= MIN_LEAF_SIZE)) {
        return false; //The room have already been splitted   
    }
    
    this -> getStat();
    leafs.push_back(*this);
    bool splitH;
    
    if (width >= height) { /* [______] -> cut verticaly */
        splitH = false;    
    } else if (width < height) { /* [] -> cut horizontaly */
        splitH = true;
    } 
    
    int split = rand() %(MAX_LEAF_SIZE-MIN_LEAF_SIZE) + MIN_LEAF_SIZE; /* We define randomly the size of the cut*/
    
    if (splitH) {
        cout << "Split Horizontal à "<< split << " " << endl;
        right = new Leaf(x, y, this -> width, split);
        left = new Leaf(x, y+split, this->width, this -> height-split);
        
        
        
    } else {
        cout << "Split Vertical à "<< split << " " << endl;
        right = new Leaf(x, y, split, height);
        left = new Leaf(x+split, y, width-split, height);
    }
    if (right -> getWidth() > MIN_LEAF_SIZE || right -> getHeight() > MIN_LEAF_SIZE){
         right -> split(leafs);
    }
    if (left -> getWidth() > MIN_LEAF_SIZE || left -> getHeight() > MIN_LEAF_SIZE){
         left -> split(leafs);  
    }
    return true;
}


