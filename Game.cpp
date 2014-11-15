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
    generator -> init();
    generator -> split();
    generator -> createRoom();
    generator -> createHalls();
    generator -> buildMap();
}

void Game::displayMap() {
    init_pair(1, COLOR_RED, COLOR_BLUE);
    screen -> clearMap();
    vector< vector<char> > map = generator -> getMap();
    string line = "";
    string vLine = "";
    
    for (int i = 0; i < (generator -> getSize() + 2); ++i) {
        vLine = vLine + "#";
    }
    
    attron(1);
    screen -> mvprintMap(7,1,vLine);    
    screen -> mvprintMap(7,1+generator->getSize()+1,vLine);

    
    for (int i = 0; i < generator -> getSize(); i++) {
        line = line + "#";
        for (int j = 0; j < generator -> getSize(); j++) {
            //screen -> mvprintMap(7+j, i+3, to_string(map[i][j]));
            line = line + map[i][j];
        }
        line  = line + "#";
        screen -> mvprintMap(7,i+2,line);    
        line = "";  
    }

    getch();
    screen -> clearMap();
}

int main() {
    Game game;
    game.launchGame();
    start_color();
    while (true) {
        game.generateMap();
        game.displayMap();
        getch();
    }
    /* endwin(); */
}
