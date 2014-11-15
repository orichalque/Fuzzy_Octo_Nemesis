#include<chrono>
#include<thread>
#include<ncurses.h>
#include<string>

#include"Screen.hpp"

using namespace std;

Screen::Screen() {
	win = NULL;
	winTxt = NULL;
	winMap = NULL;
	winStat = NULL;
}

Screen::~Screen() {
	if ((win != NULL) || (winTxt != NULL) || (winMap != NULL) || (winStat != NULL)) {
	    endwin();
	    //endwin() kill the WINDOW item from ncurses
	}
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

void Screen::clearTxt() {
    wclear(winTxt);
    wborder(winTxt, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(winTxt);
}
    
void Screen::clearMap() {
    wclear(winMap);
    wborder(winMap, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(winMap);
}

void Screen::clearStat() {
    wclear(winStat);
    wborder(winStat, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(winStat);
}
        
void Screen::init(void) {
    initscr();
    refresh();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    curs_set(0); //hide the cursor 
    keypad(stdscr, TRUE); //For keyboard complete use
    win = createWindow(LINES, COLS, 0, 0); //Initialise Main Window
    wrefresh(win);
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
         this_thread::sleep_for(chrono::milliseconds(200));
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


void Screen::windowBuilding(int size) {
    //we assume that introduction has already been displayed
	winStat = createWindow(size +5 , 25, 0, 0);
	
	winMap = createWindow(size+5, size+15, 0, 25);
	
	winTxt = createWindow(LINES - (size + 5), COLS, LINES - 13, 0);
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
	wattron(local_win, COLOR_PAIR(1));
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

