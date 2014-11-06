#include"Leaf.hpp"
#include<cstdlib>
#include<ctime>

using namespace std;

/*|||||||||||||||||||||||||||||||Constructors|||||||||||||||||||||||||||*/
Leaf::Leaf() {
    x = y = width = height = 0;
    right = NULL;
    left = NULL;
    room = NULL;
}


Leaf::Leaf(int x_, int y_, int width_, int height_) {
    x = x_;
    y = y_;
    width = width_;
    height = height_;
    right = NULL;
    left = NULL;
    room = NULL;
}

Leaf::~Leaf() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    right = NULL;
    left = NULL;
    room = NULL;
}

/*||||||||||||||||||||||||||||||||Accessors|||||||||||||||||||||||||||||||||||*/
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

int Leaf::getX() {
    return x;
}

int Leaf::getY() {
    return y;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* ||||||||||||||||||||||CreateRoom||||||||||||||||||||||| */
/* ||||||||||||||Create a room inside a Leaf|||||||||||||| */
/* CETTE METHODE MODIFIE PAS L'INSTANCE C'EST DE LA MERDE JE COMPRENDS PAS POURQUOI */
void Leaf::createRoom(vector<Rectangle> &halls) {
    srand(time(NULL));
    if (left != NULL || right != NULL) {
        if ( left != NULL ) {
            left -> createRoom(halls);
        } 
        if ( right != NULL ) {
            right -> createRoom(halls); 
        }
        if (left != NULL && right != NULL) {
            createHall(*left -> getRoom(), *right -> getRoom(), halls);
        }
    } else if (left == NULL and right == NULL) {
        //Room creation inside the leaf
        int a = rand()%(width-2);
        int b = rand()%(height-2);
        if (a < 3)  { 
            a = 3;
        } 
        if (b < 3) {
            b = 3;
        }
        Point roomSize(a, b); //From 3*3 to Width-2*Height-2
        //We put the room in the leaf
        Point roomPos(rand()%(width-a)+1, rand()%(height-b)+1);
        //We create our room with the position and the size
        this -> room = new Rectangle(x+roomPos.getX(), y+roomPos.getY(), roomSize.getX(), roomSize.getY());
        cout << "Feuille: "; this -> getStat();
        cout << "Pièce intérieur: "; room -> displayInfo();
    }
}

/* |||||||||||||||||||||||||||||||||||||getRoom||||||||||||||||||||||||||||||||||| */
/* ||||||||||||||return the room inside the leaf, in a recursive way|||||||||||||| */
/* CETTE METHODE FONCTIONNE */
Rectangle* Leaf::getRoom(void) {
    if (room != NULL){
      return room;
    } else {
        Rectangle* lRoom = NULL;
        Rectangle* rRoom = NULL;
        if (left != NULL) { //Left exists, so we call getRoom on it
            lRoom = left -> getRoom();
        }
        if (right!= NULL) { //same here
            rRoom = right -> getRoom();
        }
        if (rRoom == NULL && lRoom == NULL) { //If there's no room inside, we return null
            return NULL;
        } else if (rRoom == NULL) {
            return lRoom;
        } else if (lRoom == NULL) {
            return rRoom;
        } else { //If there's 2 room inside, we return 1 of em randomly
            return (rand()%10>4) ? lRoom : rRoom; // looks cool, hope it'll work !
        }
    }
}

Rectangle* Leaf::getRoom2(void) {
    return room;
}
/* ||||||||||||||||||||||||CreateHall||||||||||||||||||||||| */
/* ||||||||||||||Create a Hall between 2 rooms|||||||||||||| */
/* JE SAIS PAS SI CETTE METHODE FONCTIONNE */
void Leaf::createHall(Rectangle l, Rectangle r, vector<Rectangle> &halls)  {
    srand(time(NULL));
    Point p1(rand()%(l.getX()-l.getX2())+1, rand()%(l.getY() - l.getY2()) - 2);
    Point p2(rand()%(r.getX()-r.getX2())+1, rand()%(r.getY() - r.getY2()) - 2);
    
    int w(p2.getX() - p1.getX());
    int h(p2.getY() - p1.getY());
    
    if (w < 0) {
        if (h < 0) {
            if (rand()%10 < 4) {
                halls.push_back(*new Rectangle(p2.getX(), p1.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p2.getX(), p2.getY(), 1, abs(h)));
            } else {
                halls.push_back(*new Rectangle(p2.getX(), p2.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p1.getX(), p2.getY(), 1, abs(h)));
            }
        } else if (h > 0)  {
            if (rand()%10 < 4) {
                halls.push_back(*new Rectangle(p2.getX(), p1.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p2.getX(), p1.getY(), 1, abs(h)));
            } else {
                halls.push_back(*new Rectangle(p2.getX(), p2.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p1.getX(), p1.getY(), 1, abs(h)));
            }
        } else {
            halls.push_back(*new Rectangle(p2.getX(), p2.getY(), abs(w), 1));
        }
    } else if (w > 0) {
        if (h < 0) {
            if (rand()%10 < 4) {
                halls.push_back(*new Rectangle(p1.getX(), p2.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p1.getX(), p2.getY(), 1, abs(h)));
            } else {
                halls.push_back(*new Rectangle(p1.getX(), p1.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p2.getX(), p2.getY(), 1, abs(h)));
            }
        } else if (h > 0)  {
            if (rand()%10 < 4) {
                halls.push_back(*new Rectangle(p1.getX(), p1.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p2.getX(), p1.getY(), 1, abs(h)));
            } else {
                halls.push_back(*new Rectangle(p1.getX(), p2.getY(), abs(w), 1));
                halls.push_back(*new Rectangle(p1.getX(), p1.getY(), 1, abs(h)));
            }
        } else {
            halls.push_back(*new Rectangle(p1.getX(), p1.getY(), abs(w), 1));
        }
    } else {
        if (h < 0)
        {
            halls.push_back(*new Rectangle(p2.getX(), p2.getY(), 1, abs(h)));
        }
        else if (h > 0)
        {
            halls.push_back(*new Rectangle(p1.getX(), p1.getY(), 1, abs(h)));
            
        }
    }
} 


/* |||||||||||||||||||||||||||||split||||||||||||||||||||||||||||| */
/* ||||||||||||||divide a leaf inside 2 little leafs|||||||||||||| */
/* CETTE METHODE FONCTIONNE */
bool Leaf::split(vector<Leaf> &leafs) { //Divide the room in 2 distincts room    
    if (left != NULL || right != NULL || (getWidth() <= MIN_LEAF_SIZE  && getHeight() <= MIN_LEAF_SIZE)) {
        return false; //The room have already been splitted   
    }
    srand(time(NULL));
    leafs.push_back(*this);
    bool splitH;    
    if (width > height) { /* [______] -> cut verticaly */
        splitH = false;    
    } else if (width < height) { /* [] -> cut horizontaly */
        splitH = true;
    } else {
        splitH = rand()%10>4;
    }
    int split = rand() %(MAX_LEAF_SIZE-MIN_LEAF_SIZE) + MIN_LEAF_SIZE +1; /* We define randomly the size of the cut*/
    
    if (splitH) {
        if ((height-split) < MIN_LEAF_SIZE) {
            while ((height-split) < MIN_LEAF_SIZE) {
                -- split;
            }
        }
        right = new Leaf(x, y, this -> width, split);
        left = new Leaf(x, y+split, this->width, this -> height-split); 
    } else {
        if ((height-split) < MIN_LEAF_SIZE) {
            while ((width-split) < MIN_LEAF_SIZE) {
                -- split;
            }
        }
        right = new Leaf(x, y, split, height);
        left = new Leaf(x+split, y, width-split, height);
    }
    
    if (right -> getWidth() > MAX_LEAF_SIZE || right -> getHeight() > MAX_LEAF_SIZE ){
         right -> split(leafs);
    }
    if (left -> getWidth() > MAX_LEAF_SIZE || left -> getHeight() > MAX_LEAF_SIZE){
         left -> split(leafs);  
    }
    return true;
}


