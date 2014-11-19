#ifndef SCREEN_HPP
#define SCREEN_HPP

class Screen {
    private:
        WINDOW* winStat; //For Stats display
        WINDOW* winTxt; //For text instructions display
        WINDOW* winMap; //For map display
        WINDOW* win; // for multiple and temporary displays, as the introduction
        
    public:
        Screen();
        ~Screen();
        WINDOW* getWinStat(void);
        WINDOW* getWinTxt(void);
        WINDOW* getWinMap(void);
        void init(void);
        void printW(std::string s);
        void mvwprintW(int x, int y, WINDOW* win, std::string s);
        void wprintW(WINDOW* win, std::string s);
        void mvprintStat(int x, int y, std::string s);
        void mvprintMap(int x, int y, std::string s);
        void mvprintTxt(int x, int y, std::string s);
        WINDOW* createWindow(int height, int width, int starty, int startx);
        void destroyWindow(WINDOW* win);
        void displayIntro(void);
        shared_ptr<Character> chooseCharacter(void);
        void windowBuilding(int size);
        void clearTxt();
        void clearMap();
        void clearStat();
};

#endif
