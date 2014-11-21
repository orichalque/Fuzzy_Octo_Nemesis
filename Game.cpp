#include<iostream>
#include<cassert>
#include<string>
#include<memory>
#include<vector>
#include<ncurses.h>

#include "Item.cpp"
#include "Equipement.cpp"
#include "Shield.cpp"
#include "Armor.cpp"
#include "Weapon.cpp"
#include "Helmet.cpp"
#include "Weapons.hpp"
#include "Armors.hpp"
#include "Helmets.hpp"
#include "Shields.hpp"
#include "Character.cpp"
#include "Monster.cpp"
#include "Characters.hpp"
#include "Monsters.hpp"
#include "Weapons.hpp"
#include "Armors.hpp"
#include "Helmets.hpp"
#include "Shields.hpp"

#include "Factory.cpp"
#include "MonsterFactory.cpp"
#include "MonsterFactoryConcrete.cpp"

#include "BossFactory.cpp"
#include "EquipementFactory.cpp"

#include "Display/Screen.cpp"
#include "MapGenerator2/Rectangle.cpp"
#include "MapGenerator2/Leaf.cpp"
#include "MapGenerator2/Generator.cpp"


#include"Game.hpp"



Game::Game() {
    generator = make_shared<Generator>();
    screen = make_shared<Screen>();
    monsterFactory = make_shared<MonsterFactoryConcrete>();
    bossFactory = make_shared<BossFactory>();
    equipementFactory = make_shared<EquipementFactory>();
    level = 1;
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
    //screen -> displayIntro(); 
    character = (screen -> chooseCharacter());
    screen -> windowBuilding(generator -> getSize());
}

void Game::moveCharacter() {
    int ch = getch();
    if ((ch == KEY_UP) or (ch == KEY_DOWN) or (ch == KEY_RIGHT) or (ch == KEY_LEFT)) {
        /* Update the model */
        character -> updatePosition(ch, generator -> getSize(), generator -> getMap());        
        /* Warn the view */ 
        generator -> updateCharPosition(character);
    }
}

void Game::equip(shared_ptr<Equipement> equipement) {
    if (equipement -> isWeapon()) {
        character -> setWeapon(equipement);
    } else 
    if (equipement -> isArmor()) {
        character -> setArmor(equipement);
    } else 
    if (equipement -> isHelmet()) {
        character -> setHelmet(equipement);
    } else
    if (equipement -> isShield()) {
        character -> setShield(equipement);
    }
    screen -> updateCharacterInfo(character);
}

void Game::generateMap() {
    generator -> init();
    generator -> split();
    generator -> createRoom();
    generator -> createHalls();
    generator -> buildMap();
    generator -> placeCharacter(character);
    generator -> placeMonsters(level, monsterFactory, bossFactory);
    screen -> updateCharacterInfo(character);
}

void Game::displayMap() {
    screen -> clearMap();
    vector< vector<char> > map = generator -> getMap();
    string line = "";
    string vLine = "";   
    for (int i = 0; i < (generator -> getSize() + 2); ++i) {
        vLine = vLine + "#";
    }   
    wattron(screen -> getWinMap(), COLOR_PAIR(1));
    screen -> mvprintMap(7,1,vLine);    
    screen -> mvprintMap(7,1+generator->getSize()+1,vLine);
    for (int i = 0; i < generator -> getSize(); i++) {
        line = "";
        line = line + "#";
        for (int j = 0; j < generator -> getSize(); j++) {
            line = line + map[j][i];
        }
        line = line + "#";
        screen -> mvprintMap(7, i+2, line);    
    }
}

int Game::fight(shared_ptr<Character> character, shared_ptr<Character> monster) {
	bool fightEnd = false;
	int choice;
	while(!fightEnd) {
		choice = screen -> chooseAction();
		switch(choice){
			case 1:
			
				break;
			case 2:
			
				break;
				
			case 3:
			
				break;
		};
	}
}

int main() {
    Game game;
    game.launchGame();
    game.generateMap();
    game.displayMap();
    game.generateMap();
    game.displayMap();
    while (true) {
        game.moveCharacter();
        game.displayMap();
    }
            
    /* endwin(); */
}
