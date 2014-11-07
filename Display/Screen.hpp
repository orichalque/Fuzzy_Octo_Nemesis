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
        void printW(std::string s);
        void mvwprintW(int x, int y, WINDOW* win, std::string s);
        WINDOW* createWindow(int height, int width, int starty, int startx);
        void destroyWindow(WINDOW* win);
        void displayIntro(void);
        void windowBuilding(void);
};

#endif
