#include "GameState.hpp"

/**
 * \fn GameState::GameState(Game* game)
 * \brief Construit un etat sur la classe client
 * 
 * \param Game* game
 * \return void
 *
 */ 
GameState::GameState(Game* game)
{
    _game = game;
}

/**
 * \fn void GameState::action()
 * \brief lance l'action associée à l'état
 * 
 * \param void
 * \return void
 *
 */ 
void GameState::action()
{}

/**
 * \fn void GameState::action(bool b)
 * \brief lance l'action associée à l'état
 * 
 * \param bool 
 * \return void
 *
 */ 
void GameState::action(bool b)
{}

/**
 * \fn void GameState::action(shared_ptr<Monster> m)
 * \brief lance l'action associée à l'état
 * 
 * \param shared_ptr<Monster> m
 * \return void
 *
 */ 
void GameState::action(shared_ptr<Monster> m)
{}
