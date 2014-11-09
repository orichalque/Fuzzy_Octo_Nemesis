#include<vector>
#include"Leaf.cpp"
#include"Generator.hpp"

using namespace std;

Generator::Generator() {
    root = new Leaf(0,0, SIZE, SIZE); // main leaf
    
}

Generator::~Generator() {
    delete root;
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
            mat[i][j] = ' ';
        }
    }
    
    //très propre en complexité
    for (Leaf* l : leafs) {
        int abs = l -> getRoom() -> getX();
        int w2 = l -> getRoom() -> getWidth();
        int ord = l -> getRoom() -> getY();
        int h2 = l -> getRoom() -> getHeight();
        for (int l = abs; l < (abs + w2); l++) {
            for (int m = ord; m < (ord + h2); m++) {
                mat[l][m] = '#';
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
