#include<ctime>
#include<iostream>
#include<cstdlib>
#include"Leaf.hpp"

/**
 * \fn Leaf::Leaf()
 * \brief Instancie une feuille, de taille nulle et sans fils
 * \param void
 * \return void
 */ 
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

/**
 * \fn Leaf::Leaf(int x_, int y_, int width_, int height_)
 * \brief Instancie une feuille avec les attributs en paramètres
 * \param int x_, int y_, int width_, int height_
 * \return void
 */ 
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

/**
 * \fn Leaf::~Leaf()
 * \brief Détruit la feuille et ses fils récursivement
 * \param void
 * \return void
 */ 
Leaf::~Leaf() {
    delete right;
    delete left;
    delete room;
}

/**
 * \fn Leaf* Leaf::getRight()
 * \brief Renvoit le fils droit
 * \param void 
 * \return Leaf*
 */ 
Leaf* Leaf::getRight() {
    return right;
}

/**
 * \fn Leaf* Leaf::getLeft()
 * \brief Renvoit le fils gauche
 * \param void
 * \return Leaf*
 */ 
Leaf* Leaf::getLeft() {
    return left;
}

/**
 * \fn Rectangle* Leaf::getRoom()
 * \brief Renvoit la pièce a l'intérieur de la feuille
 * \param void
 * \return Rectangle*
 */ 
Rectangle* Leaf::getRoom() {
    return room;
}


/* Split : feuille trop large ? on coupe verticalement.
    feuille trop longue ? On coupe horizontalement 
    ses deux fils prennent chaque partie coupée */
/**
 * \fn bool Leaf::split(vector<Leaf*> *leafs, int seed) 
 * \brief coupe la feuille en 2.
 * \param vector<Leaf*> *leafs, int seed
 * \return bool
 *
 * Split : feuille trop large ? on coupe verticalement.
 * Feuille trop longue ? On coupe horizontalement 
 * ses deux fils prennent chaque partie coupée
 */     
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

/**
 * \fn void Leaf::join()
 * \brief Indique qu'une feuille est jointe a une autre
 * \param void
 * \return void
 */ 
void Leaf::join() {
    linked = true;
}

/**
 * \fn bool Leaf::isJoined() 
 * \brief teste si une feuille est liée à une autre
 * \param void
 * \return bool
 */ 
bool Leaf::isJoined() {
    return linked;
}

/**
 * \fn bool Leaf::isEmpty()
 * \brief teste si une feuille contient une pièce
 * \param void
 * \return bool
 */ 
bool Leaf::isEmpty() {
    return empty;
}

/**
 * \fn void Leaf::setFull() 
 * \brief remplit une feuille vec une pièce
 * \param void
 * \return void
 */ 
void Leaf::setFull() {
	empty = false;
}

/**
 * \fn int Leaf::getRoomSurface()
 * \brief Renvoit la surface de la pièce à l'intérieur de la feuille
 * \param void
 * \return int
 */ 
int Leaf::getRoomSurface() {
    return (room -> getWidth() * room -> getHeight());
}

/**
 * \fn int Leaf::getRoomCenterX()
 * \brief renvoit l'abscisse du centre de la pièce dans la room
 * \param void
 * \return int
 */ 
int Leaf::getRoomCenterX() {
    if (room != NULL) {
        return room -> getXCenter();
    } else {
        return 0;
    }
}

/**
 * \fn int Leaf::getRoomCenterY()
 * \brief renvoit l'ordonnée du centre de la pièce dans la room
 * \param void
 * \return int
 */ 
int Leaf::getRoomCenterY() {
    if (room != NULL) {
        return room -> getYCenter();
    } else {
        return 0;
    }
}

/**
 * \fn bool Leaf::createRoom(int seed)
 * \brief Crée une room à l'intérieur de la feuille
 * \param int seed
 * \return bool
 */ 
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

/**
 * \fn void Leaf::getInfoRec()
 * \brief appelle getInfo sur la feuille terminale récursivement
 * \param void
 * \return void
 * \deprecated Déprécié
 */ 
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

/**
 * \fn void Leaf::getInfo()
 * \brief affiche les infos ... Pour le debug
 * \param void 
 * \return void
 * \deprecated Déprécié
 */ 
void Leaf::getInfo() {
    cout << " x,y: " << x << "," << y << " width*height: " << width << "*" << height <<endl;
    if (room != NULL) {
        cout << "Room :" << " x,y: " << room -> getX() << "," << room -> getY() << " width*height: " << room -> getWidth() << "*" << room -> getHeight() <<endl;
    }
}

/**
 * \fn int randomize(int min, int max, int seed)
 * \brief Renvoit un nombre aléatoire entre min et max. 
 * \param int min, int max, int seed
 * \return int
 * La seed permet d'avoir des nombres plus aléatoires quand on appelle la méthode
 * dans une courte période. 
 */ 
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

