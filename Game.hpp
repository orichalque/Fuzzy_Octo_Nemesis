/*
 *  Game class
 *  Main class, creating and managing the display, the map generator, and the game itself
 *  An awesome work though, thanks to you Thibault
 *  Ooow stop it you =3
 */
#ifndef GAME_CPP
#define GAME_CPP

class Game {
    private:
        shared_ptr<Generator> generator;
        shared_ptr<Screen> screen;
    
    public:
        Game();
        ~Game();
        void launchGame();
        void displayMap();
        void generateMap();
};

#endif
