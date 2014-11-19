#include<ctime>
#include<iostream>
#include<cstdlib>
#include"Rectangle.cpp"
#include"Leaf.hpp"


Leaf::Leaf() {
    x = 0;
    y = 0;
    height = 0;
    width = 0;
    right = NULL;
    left = NULL;
    room = NULL;
    linked = false;
    empty = true;
}

Leaf::Leaf(int x_, int y_, int width_, int height_) {
    x = x_;
    y = y_;
    height = height_;
    width = width_;
    right = NULL;
    left = NULL;
    room = NULL;
    linked = false;
}

Leaf::~Leaf() {
    delete right;
    delete left;
    delete room;
}

Leaf* Leaf::getRight() {
    return right;
}

Leaf* Leaf::getLeft() {
    return left;
}

Rectangle* Leaf::getRoom() {
    return room;
}


/* Split : feuille trop large ? on coupe verticalement.
    feuille trop longue ? On coupe horizontalement 
    ses deux fils prennent chaque partie coupée */
    
bool Leaf::split(vector<Leaf*> *leafs, int seed) {
    if ((right != NULL) and (left != NULL)) {
        return false; //feuille déjà coupée en deux
    }
    bool splitV;
    if (height <= MAX_LEAF_SIZE and width <= MAX_LEAF_SIZE) {
        leafs -> push_back(this);
        return true; //the size is good.
    }
    if (height > MAX_LEAF_SIZE and width > MAX_LEAF_SIZE) {
        splitV = (rand()%10 > 4); 
    } else {
        (height > MAX_LEAF_SIZE) ? splitV = false : splitV = true;  
    }
    int w2, h2;
    if (splitV) {
       h2 = height;
       w2 = randomize(MIN_LEAF_SIZE, (width - MIN_LEAF_SIZE), seed);
       right = new Leaf(x, y, w2, h2);
       left = new Leaf(x + w2, y, width - w2, h2);
    } else {
       w2 = width;  
       h2 = randomize(MIN_LEAF_SIZE, (height - MIN_LEAF_SIZE), seed);
       right = new Leaf(x, y, width, h2);
       left = new Leaf(x, y + h2, width, height - h2);
    }
    right -> split(leafs, seed +1);
    left -> split(leafs, seed +2);
    return true;
}

void Leaf::join() {
    linked = true;
}

bool Leaf::isJoined() {
    return linked;
}

int Leaf::getRoomSurface() {
    return (room -> getWidth() * room -> getHeight());
}

int Leaf::getRoomCenterX() {
    if (room != NULL) {
        return room -> getXCenter();
    } else {
        return 0;
    }
}

int Leaf::getRoomCenterY() {
    if (room != NULL) {
        return room -> getYCenter();
    } else {
        return 0;
    }
}

bool Leaf::createRoom(int seed) {
    if (right != NULL and left != NULL) {
        cout << "Cette feuille n'est pas terminale" << endl;
        return false;    
    }
    
    int x2 = randomize(1, (width-4), seed); // 2 to width -4
    int y2 = randomize(1, (height-4), seed);
    
    
    int w = randomize(4, width-x2, seed); // 4 to width -2
    int h = randomize(4, height-y2, seed);
    //The room can go from 4*4 to Width-2*height-2
 
        
    room = new Rectangle(x+x2, y+y2, w, h);
}   

void Leaf::getInfoRec() {
    if (right == NULL and left == NULL) {
        this -> getInfo();
    }
    
    if (right != NULL) {
        right -> getInfoRec();
    }
    if (left != NULL) {
        left -> getInfoRec();
    }
}

void Leaf::getInfo() {
    cout << " x,y: " << x << "," << y << " width*height: " << width << "*" << height <<endl;
    if (room != NULL) {
        cout << "Room :" << " x,y: " << room -> getX() << "," << room -> getY() << " width*height: " << room -> getWidth() << "*" << room -> getHeight() <<endl;
    }
}

int randomize(int min, int max, int seed) {
    srand(time(NULL) + seed); //rand initialisation
    int n = max - min + 1;
    if (n <= 0) return min;
    int i = rand() % n;
    if(i < 0) {
       i = -i;
    }
    return min + i;
}

