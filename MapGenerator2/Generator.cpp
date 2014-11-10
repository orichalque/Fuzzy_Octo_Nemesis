#include<vector>
#include"Leaf.cpp"
#include"Generator.hpp"

using namespace std;

Generator::Generator() {
    root = new Leaf(0,0, SIZE, SIZE); // main leaf
}

Generator::~Generator() {

}

void Generator::split() {
    root -> split(&leafs, 1); //on met en entrée l'adresse du vector.
    for (Leaf* l : leafs) {
         l -> getInfo(); 
    }
}

void Generator::createRoom() {
    int n = 0;
    for (Leaf* l : leafs) {
        ++n;
        l -> createRoom(n);
    }
    for (Leaf* l : leafs) {
         l -> getInfo(); 
    }
}

void Generator::display() {
    char mat[SIZE][SIZE]; 
    int k(0);
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mat[i][j] = '#';
        }
    }
    
    int abs, w2, ord, h2;
    // 3 for that kinda makes a lot of executions 
    for (Leaf* l : leafs) {
        if (l -> getRoom() != NULL) {
            abs = l -> getRoom() -> getX();
            w2 = l -> getRoom() -> getWidth();
            ord = l -> getRoom() -> getY();
            h2 = l -> getRoom() -> getHeight();
            
            for (int i = abs; i < (abs+w2); ++i) {
                for (int j = ord; j < (ord+h2); ++j) {
                    mat[j-1][i-1] = ' ';
                }
            }
        }
        ++k;
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
    
    
}

int main() {
    Generator g;
    g.split();
    g.createRoom();
    g.display();
}
