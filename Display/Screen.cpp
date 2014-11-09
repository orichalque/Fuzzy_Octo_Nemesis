#include<chrono>
#include<thread>
#include<ncurses.h>
#include<string>

#include"Screen.hpp"

using namespace std;

Screen::Screen() {
    initscr();
    refresh();
    curs_set(0); //hide the cursor 
    keypad(stdscr, TRUE); //For keyboard complete use
    win = createWindow(LINES, COLS, 0, 0); //Initialise Main Window
    wrefresh(win);
}

WINDOW* Screen::getWinStat(void) {
    return winStat;
}

WINDOW* Screen::getWinTxt(void) {
    return winTxt;
} 
        
WINDOW* Screen::getWinMap(void) {
    return winMap;
}       
        
void Screen::displayIntro(void) {
    string s = "FUZZY OCTO NEMESIS";
    int x(COLS/2 - (0.5)*s.length());
    int y(LINES - 3); //Bottom of the window. -3 is meant to avoid erasing the borders of the window.
    while (y > LINES/2) {
         mvwprintW(x, y,this -> win, s);
         mvwprintW(x, y + 1 , this -> win, "                       ");
         wrefresh(win);
         y--;
         this_thread::sleep_for(chrono::milliseconds(500));
    }
    int ch(0);
    string s2 = "Press End";
    while (ch != KEY_END) {
        mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, this -> win, s2);
        wrefresh(win);
        this_thread::sleep_for(chrono::milliseconds(1000));
        mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, this -> win, "           ");
        wrefresh(win);
        ch = getch();
    } 
}

void Screen::windowBuilding(void) {
    //we assume that introduction has already been displayed
	winStat = createWindow(LINES , COLS*0.25, 0, 0);
	winMap = createWindow(0.75*LINES, 0.77*COLS, 0, 0.24*COLS);
	winTxt = createWindow(0.30*LINES, 0.77*COLS, 0.73*LINES, 0.24*COLS);
	getch();
}

void Screen::wprintW(WINDOW* win, string s) {
    char* s2;
	s2 = (char*)s.c_str();
	wprintw(win, s2);
	wrefresh(win);
}

void Screen::mvprintStat(int x, int y, string s) {
    mvwprintW(x, y, winStat, s);
}

void Screen::mvprintMap(int x, int y, string s) {
    mvwprintW(x, y, winMap, s);
}

void Screen::mvprintTxt(int x, int y, string s) {
    mvwprintW(x, y, winTxt, s);
}

void Screen::mvwprintW(int x, int y, WINDOW* win, string s) {
    char* s2;
	s2 = (char*)s.c_str();
	mvwprintw(win, y, x, "%s", s2);
	wrefresh(win);
}

void Screen::printW(std::string s) {
    char* s2;
	s2 = (char*)s.c_str(); //most of ncurses methods don't allow string parameters, only char* ...
	printw(s2);
}

WINDOW* Screen::createWindow(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0,0); // 0,0 : default characters for vertical and horizontal lines
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(local_win); //show the box
	return local_win;
}

void Screen::destroyWindow(WINDOW* local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	//empty char for each corners and side of the window
	wrefresh(local_win);
	delwin(local_win);
}


int main() {
    Screen s;
    s.displayIntro();
    s.windowBuilding();
    s.mvprintStat(1, 1, "Statistiques");
    s.mvprintMap(1, 1, "Map");
    s.mvprintTxt(1, 1, "Texte");
    getch();
    endwin();
    return 0;
}
