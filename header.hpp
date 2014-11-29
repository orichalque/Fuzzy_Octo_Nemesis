#include<chrono>
#include<thread>
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
#include "EndGameState.cpp"
#include "LootState.cpp"
#include "FightState.cpp"
#include "MoveState.cpp"

