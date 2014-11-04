#include"Rectangle.cpp"
#include"Point.cpp"
#include"Leaf.cpp"
#include"Generator.hpp"
#include<vector>

using namespace std;

Generator::Generator(void) {
    
}

void Generator::generate(void) {
    Leaf root(0,0,w,h);
    root.split(leafs);
    root.createRoom(halls);
}

void Generator::draw(void) {
    int mat[w][h];
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            mat[i][j] = 0;
        }
    }
    
    int k(0);
    for (Leaf l : leafs) {
        if (l.getRight() == NULL && l.getLeft() == NULL) { //feuille de taille minimum
            mat[l.getX()][l.getY()] = k;
            ++k;
        }
    }
    
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void Generator::displayHalls(void) {
    int i = 1;
    for (Leaf l : leafs) {
        if (l.getRoom2() != NULL) {
            l.getRoom2() -> displayInfo();
            i++;
        } 
    }
    if (i == 1) {
            cout << "pas de pieces du tout" << endl;
    }
}

void Generator::getRoomsAndHalls(void) {
	for (Leaf l : leafs) {
		if (l.getRight() == NULL && l.getLeft() == NULL) {
			l.getRoom() -> getInfo();
		}
	} 	
}

int main() {
    Generator g;
    g.generate();
<<<<<<< HEAD
    cout<< "LHDFILNPQSF" << endl;
    for (Leaf l : g.leafs) {
        if ((l.getLeft() == NULL) and (l.getRight() == NULL)) {
            l.getRoom2() -> displayInfo();
        }
    }
=======

    g.draw();
    g.getRoomsAndHalls();
>>>>>>> ff879ccdb39ccbc7ee3f32a55d6a42bb9cf1d31a
    return 0;
}


/* compiler avec g++ -std=c++11 -g Generator.cpp

La j'essaye avec une map de 10*10
Avec des pieces de taille minimum 5*5 
minimum -> on les coupe pas en 2 si elles sont en dessous de 5*5
on obtient ça
Feuille en 0:0 De taille 10 x 10  
Split Vertical à 6                      Grosse feuille, on la coupe en 2 verticalement
Feuille en 0:0 De taille 6 x 10
Split Horizontal à 6                    grosse feuille encore de 6 par 10 coupée en deux horizontalement
Feuille en 0:0 De taille 6 x 6
Split Vertical à 5                      grosse feuille encore. On la coupe en 2 verticalement 

 ______6____
|      |    |  Split 1
|      |    |
|      |    |
|      |    |
|      |    |
|      |    |
|      |    |
|      |    |
|      |    |
|______|____|

 ______6____
|      |    |  Split 2
|      |    |
|      |    |
|      |    |
|      |    |
|______|____|6
|      |    |
|      |    |
|      |    |
|______|____|

 ___5___6_____
|   |   |    |  Split 3 jusque là OK
|   |   |    |
|   |   |    |
|   |   |    |
|   |   |    |
|___|___|____|6
|       |    |
|       |    |
|       |    |
|_______|____|

en fait ça marche maintenant j'suis un boss sale nègre


*/


