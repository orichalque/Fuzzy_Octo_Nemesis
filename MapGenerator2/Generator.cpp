#include"Generator.hpp"

using namespace std;

/* ~~~~~~~~~~~~~~~~~~~~~~~~ Constructor and Destructor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
Generator::Generator() {
    root = new Leaf(0,0, SIZE, SIZE); // main leaf
    mat.resize( SIZE, vector<char>( SIZE, '#'));
}


Generator::~Generator() {
    delete root;
    for (Leaf *l : leafs) {
        if (l != NULL) {
            delete l;
        } 
    }
    for (Rectangle *r : halls) {
        if (r != NULL) {
            delete r;
        } 
    }
}

int Generator::getSize() {
   return SIZE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

/* Find Leaf Method
/* Return True if the room in parameter is in one of the leafs                          */
bool Generator::findLeaf(Rectangle* l) {
    for (Leaf* i : leafs) {
        if (i -> getRoom() == l) { //Pointing the same Rectangle object ...
            return true;
        }
    }
    return false;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */


/* GetMap
/* Return the matrice containing the map. 
/* PRE : createHalls already called                                                     */
vector< vector<char> >  Generator::getMap() {
	return mat;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */


/*  Split method                                                                        */
/*  Uses Binary Space Partioning trees                                                  */
/*  Starts from root leaf, and divide it recursiveley until there's no space remaining  */
void Generator::split() {
    root -> split(&leafs, 1); //on met en entrée l'adresse du vector.
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

/*  CreateRoom method                                                                   */
/*  Uses the CreateRoom method on each leaf                                             */
/*  PreCondition : split methods already called                                         */
void Generator::createRoom() {
    int n = 0;
    for (Leaf* l : leafs) {
        ++n;
        l -> createRoom(n);
    }   
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

/*  CreateHalls method                                                                   */
/*  Create the halls between the rooms.                                                  */
/*  PreCondition : createRoom methods already called                                     */
void Generator::createHalls() {
    int i(0); 
    Rectangle * thisR;
    Rectangle * itR;
    int Nearestroom(0);
    int tmp(0);
    int min(0);
    int w(0);
    vector<Rectangle*> unions;
    
    for (Leaf* l : leafs ) {
        unions.push_back(l -> getRoom());
        min = SIZE+SIZE;
        i++;
        for (int j = i; j < leafs.size(); ++j) {
            tmp = l -> getRoom() -> distFromThis(leafs.at(j) -> getRoom());
            if (tmp >= min and tmp != 0 and !findLeaf(leafs.at(j) -> getRoom())) {
                min = tmp;
                Nearestroom = j;
            }
        }
        unions.push_back(leafs.at(Nearestroom) -> getRoom());
        /* Rooms are now joined */
        leafs.at(Nearestroom) -> join();
        l -> join();
            thisR = l -> getRoom(); // Rectangle of the main leaf 
            itR = leafs.at(Nearestroom) -> getRoom(); // Rectangle of the nearest leaf
            
            if (thisR -> getXCenter() > itR -> getXCenter()) {
                /* The nearest room is on the left side */
                
                halls.push_back(new Rectangle(itR -> getXCenter(), thisR -> getYCenter(), abs(thisR -> getXCenter() - itR -> getXCenter()) , 1));
                
                if (thisR -> getYCenter() > itR -> getYCenter()) {
                    /* the nearest room is at the top */
                    
                    halls.push_back(new Rectangle(itR -> getXCenter(), itR -> getYCenter(), 1, abs ( itR -> getYCenter() - thisR -> getYCenter())));
                    
                } else if (thisR -> getYCenter() < itR -> getYCenter()) {
                    /* Nearest room is at the bottom */
                   halls.push_back(new Rectangle(itR -> getXCenter(), thisR -> getYCenter(), 1, abs ( itR -> getYCenter() - thisR -> getYCenter())));
                    
                } else {
                    /* Same level, only the horizontal hall is necessary */
                    /* Empty IF */
                }
            } else if (thisR -> getXCenter() > itR -> getXCenter()) {
                /* the Nearest room is on the right side */
                    halls.push_back(new Rectangle(thisR -> getXCenter(), thisR -> getYCenter(), abs ( thisR -> getXCenter() - itR -> getXCenter()), 1));
                    
                if (thisR -> getYCenter() > itR -> getYCenter()) {
                    /* the nearest room is at the top */
                    halls.push_back(new Rectangle(itR -> getXCenter(), itR -> getYCenter(), 1, abs ( itR -> getYCenter() - thisR -> getYCenter())));
                } else if (thisR -> getYCenter() < itR -> getYCenter()) {
                    /* Nearest room is at the bottom */
                   halls.push_back(new Rectangle(itR -> getXCenter(), thisR -> getYCenter(), 1, abs ( itR -> getYCenter() - thisR -> getYCenter())));
                } else {
                    /* Same level, only the horizontal hall is necessary */
                    /* Empty IF */
                }
            } else {
            /* Rooms are at the same level */
            /* Only vertical lines are necessary */
                if (thisR -> getYCenter() > itR -> getYCenter()) {
                    /* the nearest room is at the top */
                    halls.push_back(new Rectangle(itR -> getXCenter(), itR -> getYCenter(), 1, abs ( itR -> getYCenter() - thisR -> getYCenter())));
                    
                } else if (thisR -> getYCenter() < itR -> getYCenter()) {
                    /* Nearest room is at the bottom */
                   halls.push_back(new Rectangle(thisR -> getXCenter(), thisR -> getYCenter(), 1, abs ( itR -> getYCenter() - thisR -> getYCenter())));
                }
            }
    }   
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */


/*  BuildMap method
/*  Build the map inside the matrix
/*  PreCondition : createHalls already called.                              */           
void Generator::buildMap() {
    int k(0);
    int abs, w2, ord, h2;
    // 3 for that kinda makes a lot of executions
     
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            mat[i][j] = '#'; //init map before building it
        }
    }
    
    for (Leaf* l : leafs) {
        if (l -> getRoom() != NULL) {
            abs = l -> getRoom() -> getX();
            w2 = l -> getRoom() -> getWidth();
            ord = l -> getRoom() -> getY();
            h2 = l -> getRoom() -> getHeight();
            
            for (int i = abs; i < (abs+w2); ++i) {
                for (int j = ord; j < (ord+h2); ++j) {
                 
                    mat[j][i] = ' ';
                }
            }
        }
        ++k;
    } 
    for (Rectangle * r : halls )  {
        abs = r ->  getX();
        w2 = r -> getWidth();
        ord = r -> getY();
        h2 = r -> getHeight();
        
        for (int i = abs; i < (abs+w2); ++i) {
            for (int j = ord; j < (ord+h2); ++j) {
                mat[j][i] = ' ';
            }
        }
    }
    
}

/*
 *  Init Method
 *  Clear all the vectors for new Map Generation
 */
void Generator::init() {
    root = new Leaf(0,0, SIZE, SIZE); // main leaf
    mat.resize( SIZE, vector<char>( SIZE, '#'));
    leafs.clear();
    halls.clear();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

void Generator::updateCharPosition(shared_ptr<Character> character ) {
    mat[character -> x()][character -> y()] = '@';
    if (character -> x() > 0) {
        if (mat[character -> x()-1][character -> y()] == '@') {
            mat[(character -> x())-1][character -> y()] = ' ';
        }
    }
    if (character -> y() > 0) {
        if (mat[character -> x()][character -> y()-1] == '@') {
            mat[character -> x()][character -> y()-1] = ' ';
        }
    }
    if (character -> x() < SIZE-1) {
        if (mat[character -> x()+1][character -> y()] == '@') {
            mat[character -> x()+1][character -> y()] = ' ';
        }
    }
    if (character -> y() < SIZE-1) {
        if (mat[character -> x()][character -> y()+1] == '@') {
            mat[character -> x()][character -> y()+1] = ' ';
        }
    }
}

shared_ptr<Rectangle> Generator::placeCharacter(shared_ptr<Character> c) {
   for (Leaf* l : leafs) {
        if (l -> isJoined() and l -> isEmpty()) {
        	l -> setFull();
        	mat[l->getRoom() -> getYCenter()][l -> getRoom() -> getXCenter()] = '@';
        	c -> setY(l->getRoom() -> getXCenter());
        	c -> setX(l->getRoom() -> getYCenter());
            return make_shared<Rectangle>(*(l -> getRoom()));
        }
   }   
}


shared_ptr<Monster> Generator::placeBoss(int level, shared_ptr<BossFactory> mf) {
	Leaf* l;
	for (int i = leafs.size()-1; i != 0; i--) {
		l = leafs.at(i);
		if (l -> isJoined() and l -> isEmpty()) {
        	l -> setFull();
        	shared_ptr<Monster> boss = mf -> create(level);
        	mat[l->getRoom() -> getYCenter()][l -> getRoom() -> getXCenter()] = boss -> getSymbol();
      	  	return boss;
      	}
	}
}

vector< shared_ptr<Monster> > Generator::placeMonsters(int level, shared_ptr<MonsterFactoryConcrete> mfc, shared_ptr<BossFactory> bf) {
	vector< shared_ptr<Monster> > monsters;
	monsters.push_back(placeBoss(level, bf));
	int mobs_to_add[3];
	int seed_for_random(0);
	
	/* get the 3 right monsters for the actual level */
	
	for (int i = -1; i < 2; ++i) {
		mobs_to_add[i+1] = (2*level + (level-1)) +i;
	}
	
	for (Leaf* l : leafs) {
		srand (time(NULL) + seed_for_random);
		++seed_for_random;
		if (l -> isJoined() and l -> isEmpty()) {
			monsters.push_back(mfc -> create(mobs_to_add[rand()%3]));
        	l -> setFull();
        	mat[l->getRoom() -> getYCenter()][l -> getRoom() -> getXCenter()] = monsters.back() -> getSymbol();
        	monsters.back() -> setX(l->getRoom() -> getXCenter());
        	monsters.back() -> setY(l->getRoom() -> getYCenter());
        }
	} 
	
	return monsters;
	
}

	
