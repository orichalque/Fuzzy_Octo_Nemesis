#include "GameState.hpp"

GameState::GameState(Game* game)
{
    _game = game;
}

/*void GameState::moveOnMob()
{}

void GameState::winFight(bool boss)
{}

void GameState::looseFight()
{}

void GameState::lootChoosed(bool boss)
{}

void GameState::nextLevel()
{}

void GameState::dead()
{}*/

void GameState::action()
{}

void GameState::action(bool b)
{}

void GameState::action(shared_ptr<Monster> m)
{}
