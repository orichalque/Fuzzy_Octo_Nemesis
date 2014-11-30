#include"EndGameState.hpp"

/**
 * \fn EndGameState::EndGameState(Game* game) : GameState(game)
 * \brief Constructeur d'etat de fin de jeu
 *
 * \param Game* game
 * \return nouvelle instance de endGameState
 *
 * Instancie l'état de fin de jeu. Après défaite ou victoire contre le boss de fin
 */ 
EndGameState::EndGameState(Game* game) : GameState(game)
{}

/**
 * \fn void EndGameState::action(bool victory)
 * \brief Lance l'animation de fin du jeu
 *
 * \param bool victory
 * \return void
 *
 * Lance l'animation de fin du jeu, calcule le score, et dépendante de l'état du personnage.
 */ 
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
