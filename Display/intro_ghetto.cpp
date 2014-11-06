#include<string>
#include<iostream>
#include<ncurses.h>
#include"Display.cpp"

WINDOW* createWindow(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0,0); // 0,0 : default characters for vertical and horizontal lines
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(local_win); //show the box
	return local_win;
}

void mvwprintW(int x, int y, WINDOW* win, string s) {
    char* s2;
	s2 = (char*)s.c_str();
	mvwprintw(win, y, x, "%s", s2);
}

void intro(void) {
    initscr();
    WINDOW *win;
    if (LINES < 20) {
        printW("Agrandissez la fenêtre en hauteur !");
        getch();
        endwin();
    } else if (COLS < 50) {
        printW("Agrandissez la fenetre en largeur !");
        getch();
        endwin();
    }
   
string s2=
  "   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _  \n  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ \n ( F   u   z   z   y | O   c   t   o | N   e   m   e   s   i   s )\n  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \n "; //title 1
  
string s = " FUZZY OCTO NEMESIS";      //title2                                                      
//printW(s);
    refresh(); //SINON CA MARCHE PAS
    win = createWindow(LINES, COLS, 0, 0);
    mvwprintW(COLS/2 - 15, 13,win, s);
    wrefresh(win);
    getch();  
    endwin();                                                       
}

int main() {
    intro();
}


