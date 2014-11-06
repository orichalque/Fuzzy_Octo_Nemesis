#include<string>
#include<iostream>
#include<ncurses.h>
#include"Display.hpp"


/*http://en.tldp.org/HOWTO/NCURSES-Programming-HOWTO/windows.html*/
using namespace std;
void printW(string s);
void wprintW(WINDOW* w, string s);

Display::Display() {

}


WINDOW* Display::createWindow(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0,0); // 0,0 : default characters for vertical and horizontal lines
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(local_win); //show the box
	return local_win;
}

void Display::destroyWindow(WINDOW* local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	//empty char for each corners and side of the window
	wrefresh(local_win);
	delwin(local_win);
}

void Display::windowBuilding(void) {
	WINDOW *winMap;
	WINDOW *winStat;
	WINDOW *winTxt;
	int ch;
	int x; int y; int height; int width;

	initscr(); //start curses mode
	cbreak(); //line buffering disabled
	keypad(stdscr, TRUE); //allow FA ... F12 buttons
	height = LINES;
	width = COLS * 0.25;
	x = (LINES - height) /2;
	y = (COLS - width) /2;
	refresh();
	winStat = createWindow(height, width, 0, 0);
	wprintw(winStat, "Ki \n ko \n o");
	wrefresh(winStat);
	getch();
	winMap = createWindow(0.75*LINES, 0.75*COLS, 0, 0.26*COLS);
	getch();
	winTxt = createWindow(0.26*LINES, 0.75*COLS, 0.75*LINES, 0.26*COLS);
	getch();
	wprintw(winStat, "Kikoo");
	refresh();
	ch = getch();
	
	endwin();
	
}

void Display::display(string s){
	initscr();	
	printW(s);
	refresh();
	getch();
	endwin();
}


void Display::bold(){
	int ch;
	char* str;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	printW("Type smthing to see it in bold");
	ch = getch();
	while(ch != KEY_END) {
		printW("The key pressed is: ");
		attron(A_BOLD);
		printw("%c\n", ch);
		attroff(A_BOLD);
		refresh();
		ch = getch();
	}
	endwin();
}

void wprintW(WINDOW* w, string s) {
    char* s2;
	s2 = (char*)s.c_str();
	wprintw(w, s2);
	refresh();
}

void printW(string s) {
	char* s2;
	s2 = (char*)s.c_str();
	printw(s2);
}

