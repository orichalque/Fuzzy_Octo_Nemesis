#include "LootState.hpp"

LootState::LootState(shared_ptr<Game> game) : GameState(game)
{}

void LootState::action(bool b)
{
	game->loot();
	if(b)
	{
		game->setState(game->getWonLevelState());
	}
}
