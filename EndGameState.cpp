#include"EndGameState.hpp"

EndGameState::EndGameState(Game* game) : GameState(game)
{}

void EndGameState::action(bool victory) {
	string s;
	if (victory) { //if the player beat the last boss		
		s = "Victoire !";
	} else { // He died in a fight
		s = "Défaite ...";
	}
	_game -> getScreen() -> endGameScreen(s, _game -> getCharacter());
	_game -> setLevel(0); //On met le niveau à zéro pour quitter la boucle. 
}
