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

#include "Game.hpp"
#include "GameState.cpp"
#include "LootState.cpp"
#include "FightState.cpp"
#include "MoveState.cpp"


Game::Game() 
{
    _fightState = make_shared<FightState>(this);
    _moveState = make_shared<MoveState>(this);
    _lootState = make_shared<LootState>(this);
    generator = make_shared<Generator>();
    screen = make_shared<Screen>();
    monsterFactory = make_shared<MonsterFactoryConcrete>();
    bossFactory = make_shared<BossFactory>();
    equipementFactory = make_shared<EquipementFactory>();
    level = 1;
    _currentState = _moveState;

}

Game::~Game() {
    //All Hail for the SmartPointers !
}


shared_ptr<Generator> Game::getGenerator() const
{
    return generator;
}

shared_ptr<Character> Game::getCharacter() const
{
    return character;
}

shared_ptr<Screen> Game::getScreen() const
{
    return screen;
}

shared_ptr<GameState> Game::getFightState() {
    return _fightState;
}

shared_ptr<GameState> Game::getMoveState() {
    return _moveState;
}

shared_ptr<GameState> Game::getLootState() {
    return _lootState;
}

int Game::getLevel() {
    return level;
}

shared_ptr<EquipementFactory> Game::getEquipementFactory() {
    return equipementFactory;
}
        
        
void Game::setState(shared_ptr<GameState> s) {
    _currentState = s;
}

void Game::action() {
    _currentState -> action();
}

void Game::action(shared_ptr<Monster> mons) {
    _currentState -> action(mons);
}

vector< shared_ptr<Monster> >* Game::getMonstersList() {
    return &monsters;
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
    monsters = generator -> placeMonsters(level, monsterFactory, bossFactory);
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
    screen -> mvprintMap(2, generator -> getSize() +3, "Level "+to_string(level));
}




int main() {
    Game game;
    game.launchGame();
    game.generateMap();
    game.displayMap();
    game.generateMap();
    game.displayMap();
    while (game.getLevel()) {
        game.action();
        game.displayMap();
    }
    /* to do */
    /*
    - Modifier la method display map pour la mettre dans la classe generator. Les mobs sont pas placés dynamiquement -> pas de combats après une fuite.
    - bug avec les méthodes de random à la con
    - ajouter des fonctions spéciales quand on tue le boss. Empecher la fuite contre le boss.         
    /* endwin(); */
}
