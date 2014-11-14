#include<cstdio>
#include<cstdlib>
#include<string>
#include<memory>
#include"Display/Screen.cpp"
#include"MapGenerator2/Generator.cpp"
#include"Game.hpp"

Game::Game() {
    generator = make_shared<Generator>();
    screen = make_shared<Screen>();
}

Game::~Game() {
    //All Hail for the SmartPointers !
}


void Game::launchGame() {
    int x = 40 + generator -> getSize();
    int y = 18 + generator -> getSize();
    string str = "resize -s "+to_string(y)+" "+to_string(x);
    //resizing the window with a bash script
    system((char*)str.c_str());    
    screen -> init(); 
   // screen -> displayIntro(); 
    screen -> windowBuilding(generator -> getSize());
}

void Game::generateMap() {
    generator -> split();
    generator -> createRoom();
    generator -> createHalls();
    generator -> buildMap();
}

void Game::displayMap() {
    screen -> clearMap();
    vector< vector<char> > map = generator -> getMap();
    string line = "";
    string vLine = "";
    
    for (int i = 0; i < (generator -> getSize() + 2); ++i) {
        vLine = vLine + "#";
    }
    
    screen -> mvprintMap(7,2,vLine);    
    screen -> mvprintMap(7,2+generator->getSize()+1,vLine);
    
    for (int i = 0; i < generator -> getSize(); i++) {
        for (int j = 0; j < generator -> getSize(); j++) {
            line = line + map[i][j];
        }
        screen -> mvprintMap(7,i+3,line);    
        line = "";  
    }
    

    
    getch();
    screen -> clearMap();
}

int main() {
    Game game;
    game.launchGame();
    while (true) {
        game.generateMap();
        game.displayMap();
        getch();
    }
    /* endwin(); */
}
