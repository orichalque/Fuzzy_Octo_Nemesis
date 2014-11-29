

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
         this_thread::sleep_for(chrono::milliseconds(150));
    }
    int ch(0);
    string s2 = "Press Enter";
    while (ch != 10) {
        mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, this -> win, s2);
        wrefresh(win);
        this_thread::sleep_for(chrono::milliseconds(500));
        mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, this -> win, "           ");
        wrefresh(win);
        ch = getch();
    } 
    win = createWindow(LINES, COLS, 0, 0); //Initialise Main Window
    wrefresh(win);
}


void Screen::windowBuilding(int size) {
    //we assume that introduction has already been displayed
	winStat = createWindow(size +5 , 27, 0, 0);
	
	winMap = createWindow(size+5, size+13, 0, 27);
	
	winTxt = createWindow(LINES - (size + 5), COLS, LINES - 14, 0);
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

shared_ptr<Character> Screen::chooseCharacter(void) {
    /* Precondition : Screen already displayed, but not the maps */
    string choose = "Choisissez votre personnage";
    string key = "avec les touches directionnelles";
    int x = 0.5*(COLS - choose.length());
    int y = 2;
    mvwprintW(x, y, win, choose);
    x = 0.5*(COLS -key.length());
    mvwprintW(x, y+1, win, key);
    
    mvwprintW(13, 10, win, "Guerrier");
    mvwprintW(13, 12, win, "Un guerrier équilibré"  );
    mvwprintW(13, 13, win, "déjà armé d'un couteau");
    mvwprintW(13, 14, win, "et d'un bouclier");
    
    mvwprintW(45, 10, win, "Paladin");
    mvwprintW(45, 12, win, "Un soldat en armure" ); 
    mvwprintW(45, 13, win, "capable d'encaisser" );
    mvwprintW(45, 14, win, "des tonnes de dégats" );
    
    mvwprintW(13, 30, win, "Voleur");
    mvwprintW(13, 32, win, "Un rapide brigand"  );
    mvwprintW(13, 33, win, "armé d'une dague affutée");
    mvwprintW(13, 34, win, "et d'une bonne dexterité ");
    
    mvwprintW(45, 30, win, "Berserk");
    mvwprintW(45, 32, win, "Un sanguinaire"  );
    mvwprintW(45, 33, win, "assoiffé de combats, ");
    mvwprintW(45, 34, win, "fort et endurant. ");
    
	x = 10 ;
    y = 10 ;
    mvwprintW(x, y,win, "->");
    int button = getch();
    
    while (button != 10) {
    	mvwprintW(x, y,win, "->");
    	switch(button) {
    		case (KEY_UP):
    			if (y==30)  {
    				mvwprintW(x, y,win, "  ");
    				y = 10;
    			}
    			break;
    		case (KEY_DOWN):
    			if (y==10) {
    				mvwprintW(x, y, win,"  ");
    				y = 30;
    			}
    			break;
    		case (KEY_LEFT):
    			if (x==42)  {
    				mvwprintW(x, y,win, "  ");
    				x = 10;
    			}
    			break;
    		case (KEY_RIGHT):
    			if (x==10) {
    				mvwprintW(x, y, win,"  ");
    				x = 42;
    			}
    			break;
    	};
    	mvwprintW(x, y, win,"->");
    	
    	if (button != KEY_UP and button != KEY_DOWN and button != KEY_RIGHT and button != KEY_LEFT) {
		    mvwprintW(0.5*(COLS - 44), 40, win, "Choisissez avec les touches directionnelles!");
		    this_thread::sleep_for(chrono::milliseconds(1000));
		    mvwprintW(0.5*(COLS - 44), 40, win, "                                            ");
  		}
  		
    	button = getch();
    }

    
    if (x == 10 and y == 30) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Voleur choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Voleur>();
    } else if (x == 42 and y == 30) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Berserk choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Berserk>();
    } else if (x == 42 and y == 10) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Paladin choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Paladin>();
    } else if (x == 10 and y == 10) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Guerrier choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Guerrier>();
    }
}


void Screen::updateCharacterInfo(shared_ptr<Character> character) {
    clearStat();
    mvprintStat(7, 1, character -> name());
    mvprintStat(1, 3, "Attaque: "+to_string(character -> getCombinedAtt()));
    mvprintStat(1, 4, "Defense: "+to_string(character -> getCombinedDef()));
    mvprintStat(1, 5, "Points de vie: "+to_string(character -> life()));
    mvprintStat(1, 6, "Dextérité: "+to_string(character -> getCombinedDext()));
 
    mvprintStat(7, 9, "Equipement");

    string s = "";
    if (character -> getShield() == NULL) {
        s = "Bouclier: Aucun";
    } else {
        s = "Bouclier: "+character -> getShield() -> getName();
    }
    mvprintStat(1, 11, s);   
    if (character -> getArmor() == NULL) {
        s = "Armure: Aucune";
    } else {
        s = "Armure: "+character -> getArmor() -> getName();
    }
    mvprintStat(1, 12, s);   
    if (character -> getHelmet() == NULL) {
        s = "Casque: Aucun";
    } else {
        s = "Casque: "+character -> getHelmet() -> getName();
    }
    mvprintStat(1, 13, s);   
    mvprintStat(1, 14, "Arme: "+character -> getWeapon() -> getName());
}

void Screen::updateMonsterInfo(shared_ptr<Character>monster) {
	mvprintTxt(COLS -22, 10, "Vie du monstre: "+to_string(monster -> life()));   
}

void Screen::getMyEquipement(shared_ptr<Equipement> equipement) {
    if (equipement == NULL) {
        mvprintTxt(2, 4, "Equipé: Rien") ;
        mvprintTxt(2, 5, "Attaque: 0"); 
        mvprintTxt(2, 6, "Defense: 0"); 
        mvprintTxt(2, 7, "Dexterité: 0"); 
    } else {
        mvprintTxt(2, 4, "Equipé: "+ equipement -> getName()) ;
        mvprintTxt(2, 5, "Attaque: "+ to_string(equipement -> getAtt())); 
        mvprintTxt(2, 6, "Defense: "+ to_string(equipement -> getDef())); 
        mvprintTxt(2, 7, "Dexterité: "+ to_string(equipement -> getDext())); 
    }
}

void Screen::getNewEquipement(shared_ptr<Equipement> equipement) {
    mvprintTxt(40, 4, "Ramassé: "+ equipement -> getName()) ;
    mvprintTxt(40, 5, "Attaque: "+ to_string(equipement -> getAtt())); 
    mvprintTxt(40, 6, "Defense: "+ to_string(equipement -> getDef())); 
    mvprintTxt(40, 7, "Dexterité: "+ to_string(equipement -> getDext())); 
}
        
int Screen::chooseAction() {
	enum choices:int { ATTACK = 1, DEFENSE=2, RUN=3};
	mvprintTxt(2, 9, "Choisissez votre action");
	mvprintTxt(4, 10, "Attaquer");
	mvprintTxt(16, 10, "Défendre");
	mvprintTxt(29, 10, "Fuir");
	mvprintTxt(2, 10, ">");
	int ch = getch();
	int x(2);
	while (ch != 10) {
		if (ch == KEY_RIGHT and x < 26) {
			mvprintTxt(x, 10, " ");
			mvprintTxt(x+12, 10, ">");
			x +=12;
		}
		
		if (ch == KEY_LEFT and x > 2) {
			mvprintTxt(x, 10, " ");
			mvprintTxt(x-12, 10, ">");
			x -=12;
		}
		ch = getch();
	}
	
	if (x == 2) {
		 mvprintTxt(x, 10, " "); 
		 return ATTACK;
	} else if (x == 14) {
		mvprintTxt(x, 10, " "); 
		return DEFENSE;
	} else if (x == 26) {
		mvprintTxt(x, 10, " "); 
		return RUN;
	}
	return ATTACK;
}

bool Screen::equip() { 
    int ch; int x(18);
    mvprintTxt(2, 9, "Equiper ?") ;
    mvprintTxt(x, 9, ">") ;
    mvprintTxt(20, 9, "Oui") ;
    mvprintTxt(30, 9, "Non") ;
    ch = getch();
    while (ch != 10) {
        if (ch == KEY_RIGHT and x == 18) {
            mvprintTxt(18, 9, " ") ;
            x += 10;
        }
           
        if (ch == KEY_LEFT and x == 28) {
            mvprintTxt(28, 9, " ") ;
            x -= 10;
        }
        mvprintTxt(x, 9, ">") ;
        ch = getch();
    }
        
    if (x == 18) {
        return true;        
    } else {
        return false;
    }
}
 
void Screen::endGameScreen(string s, shared_ptr<Character> character) {
	init();
	int x(COLS/2 - (0.5)*s.length());
    int y(LINES - 5); //Bottom of the window. -3 is meant to avoid erasing the borders of the window.
	while (y > 1) {
		mvwprintW(x, y, win, s);
		mvwprintW(x, y + 1 , win, "                ");
		wrefresh(win);
		y--;
		this_thread::sleep_for(chrono::milliseconds(150));
	}
	s = "Score : ";
	int score = character -> getCombinedDef() + character -> getCombinedDef() + character -> maxLife() + character -> getCombinedDext();
	s = s + to_string(score);
	y = LINES - 5;
	x = (COLS/2 - (0.5)*s.length());
	this_thread::sleep_for(chrono::milliseconds(1000));
	while (y > 2) {
	     mvwprintW(x, y, win, s);
	     mvwprintW(x, y + 1 , win, "                ");
	     wrefresh(win);
	     y--;
	     this_thread::sleep_for(chrono::milliseconds(150));
	}
	
	this_thread::sleep_for(chrono::milliseconds(1000));
	s = "Félicitations !";
	y = LINES - 5;	
	x = (COLS/2 - (0.5)*s.length());
	while (y > 3) {
	     mvwprintW(x, y, win, s);
	     mvwprintW(x, y + 1 , win, "                ");
	     wrefresh(win);					
	     y--;
	     this_thread::sleep_for(chrono::milliseconds(150));
	}
	string s2 = "Press Enter to exit";
	int ch(0);
	while (ch != 10) {
	    mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, win, s2);
	    wrefresh(win);
	    this_thread::sleep_for(chrono::milliseconds(1000));
	    mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, win, "                       ");
	    wrefresh(win);
	    ch = getch();
	}
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

