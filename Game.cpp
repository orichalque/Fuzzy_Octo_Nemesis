/*! \mainpage Auteur : Thibault BLF. Corentin M.
*
* \section intro_sec Introduction
*
* Fuzzy Octo Nemesis est un jeu de rôle type RogueLike, adapté pour terminal UNIX.\n
* L'objectif est de parcourir le donjon, tuer les monstres et atteindre le boss final.\n
* Pour ce, l'utilisateur peut incarner 4 personnages différents avec chacun leurs attributs propres: \n
* - Le guerrier, un combattant équilibré commençant avec une armure et une épée. \n
* - Le paladin, un soldat à la haute défense, capable d'encaisser beaucoup d'attaques \n
* - Le voleur, un rôdeur à la frappe implaccable, capable d'esquives incroyables \n
* - Le berserk, un batailleur sanguinaire avec une grosse épée \n \n
* Chaque ennemi tué à une chance de laisser des équipements derrière lui. Vous pouvez directement attaquer le boss de chaque étage du donjon, \n
* mais il est conseillé de récupérer de l'équipement sur les sbires environnants. \n
* Vous pourrez vous frotter à une vingtaine de monstres, et trouver des dizaines de pièces d'équipement différents ! \n
* A l'attaque ! \n
* \section install_sec Execution
* make pour compiler \n
* make run pour executer l'application \n
* make clean pour nettoyer le répertoire \n
* make site pour afficher le site \n
*
* \section tools_subsec Compilation (nécessaire si l'exécution ne fonctionne pas)
*
* Entrer dans le terminal la commande suivante:
* g++ -std=c++11 Game.cpp -lncurses
*
* \section copyright Copyright & License
* OpenSource! Faites en ce que vous désirez. Ce projet est uniquement à but éducatif.
* <BR><BR>
*
*/

#include"header.hpp"


///
/// \fn Game::Game()
/// \brief Constructeur de la classe cliente game. Initialisation des attributs
///
/// \param No parameter
/// \return Instance nouvellement allouée d'un objet de type Game
///
Game::Game() 
{
    _fightState = make_shared<FightState>(this);
    _moveState = make_shared<MoveState>(this);
    _lootState = make_shared<LootState>(this);
    _endGameState = make_shared<EndGameState>(this);
    
    generator = make_shared<Generator>();
    screen = make_shared<Screen>();
    monsterFactory = make_shared<MonsterFactoryConcrete>();
    bossFactory = make_shared<BossFactory>();
    equipementFactory = make_shared<EquipementFactory>();
    level = 1;
    _currentState = _moveState;

}

///
/// \fn Game::~Game()
/// \brief Destructeur de la classe cliente game.
///
/// \param No parameter
/// \return Void
///
Game::~Game() {
    
}


///
/// \fn shared_ptr<Generator> Game::getGenerator() const
/// \brief Getter de l'attribut Generator
///
/// \param No parameter
/// \return Shared_ptr<Generator> 
/// Renvoit le generator
///
shared_ptr<Generator> Game::getGenerator() const
{
    return generator;
}

/**
 * \fn shared_ptr<Character> Game::getCharacter() const
 * \brief Getter de l'attribut Character
 *
 * \param No parameter
 * \return Shared_ptr<Character> 
 */
shared_ptr<Character> Game::getCharacter() const
{
    return character;
}

/**
 * \fn shared_ptr<Screen> Game::getScreen() const
 * \brief Getter de l'attribut Screen
 *
 * \param No parameter
 * \return Shared_ptr<Screen> 
 */
shared_ptr<Screen> Game::getScreen() const
{
    return screen;
}

/**
 * \fn shared_ptr<GameState> Game::getFightState()
 * \brief Getter de l'attribut _fightState
 *
 * \param No parameter
 * \return Shared_ptr<GameState> 
 */
shared_ptr<GameState> Game::getFightState() {
    return _fightState;
}

/**
 * \fn shared_ptr<GameState> Game::getMoveState()
 * \brief Getter de l'attribut _moveState
 *
 * \param No parameter
 * \return Shared_ptr<GameState> 
 */
shared_ptr<GameState> Game::getMoveState() {
    return _moveState;
}

/**
 * \fn shared_ptr<GameState> Game::getLootState()
 * \brief Getter de l'attribut _lootState
 *
 * \param No parameter
 * \return Shared_ptr<GameState> 
 */
shared_ptr<GameState> Game::getLootState() {
    return _lootState;
}

/**
 * \fn shared_ptr<GameState> Game::getEndGameState()
 * \brief Getter de l'attribut _endGameState
 *
 * \param No parameter
 * \return Shared_ptr<GameState> 
 */
shared_ptr<GameState> Game::getEndGameState() {
    return _endGameState;
}

/**
 * \fn int Game::getLevel()
 * \brief Getter de l'attribut level
 *
 * \param No parameter
 * \return int
 */
int Game::getLevel() {
    return level;
}

/**
 * \fn vector< shared_ptr<Monster> >* Game::getMonstersList()
 * \brief Getter de l'attribut monsterList
 *
 * \param No parameter
 * \return vector< shared_ptr<Monster> >*
 *
 * Retourne la liste des monstres du niveau actuel
 */
vector< shared_ptr<Monster> >* Game::getMonstersList() {
    return &monsters;
} 


/**
 * \fn shared_ptr<EquipementFactory> Game::getEquipementFactory()
 * \brief Getter de l'attribut equipementFactory
 *
 * \param No parameter
 * \return shared_ptr<EquipementFactory>
 */
shared_ptr<EquipementFactory> Game::getEquipementFactory() {
    return equipementFactory;
}

/**
 * \fn void Game::setLevel(int newLevel)
 * \brief setter du niveau actuel de la partie
 *
 * \param int newLevel
 * \return void
 */        
void Game::setLevel(int newLevel) {
	level = newLevel;
}

/**
 * \fn void Game::setState(shared_ptr<GameState> s)
 * \brief setter de l'état actuel de la classe cliente
 *
 * \param shared_ptr<GameState> s
 * \return void
 */                  
void Game::setState(shared_ptr<GameState> s) {
    _currentState = s;
}

/**
 * \fn void Game::action()
 * \brief appelle la methode action sur l'attribut d'état
 *
 * \param void
 * \return void
 *
 *  Effectue l'action dépendente de l'état actuel
 */  
void Game::action() {
    _currentState -> action();
}

/**
 * \fn void Game::action(shared_ptr<Monster> mons)
 * \brief appelle la methode action sur l'attribut d'état avec un monstre en entrée
 *
 * \param shared_ptr<Monster> mons
 * \return void
 *
 *  Effectue l'action dépendente de l'état actuel
 */  
void Game::action(shared_ptr<Monster> mons) {
    _currentState -> action(mons);
}

/**
 * \fn void Game::action(bool b)
 * \brief appelle la méthode action sur l'attribut d'état avec un booléen en entrée
 *
 * \param bool b
 * \return void
 *
 *  Effectue l'action dépendente de l'état actuel
 */  
void Game::action(bool b) {
    _currentState -> action(b);
}


/**
 * \fn void Game::launchGame()
 * \brief appelle la méthode de lancement du jeu
 *
 * \param void
 * \return void
 *
 *  Démarre le jeu : initialise l'affichage, affiche l'introduction et lance l'écran de chargement du personnage
 */ 
void Game::launchGame() {
    int x = 40 + generator -> getSize();
    int y = 18 + generator -> getSize();
    string str = "resize -s "+to_string(y)+" "+to_string(x);
    //resizing the window with a bash script
    system((char*)str.c_str());    
    screen -> init(); 
    screen -> displayIntro(); 
    character = (screen -> chooseCharacter());
    screen -> windowBuilding(generator -> getSize());
}


/**
 * \fn void Game::moveCharacter()
 * \brief Methode de déplacement du personnage
 *
 * \param void
 * \return void
 *
 *  Récupère les entrées clavier, notifie le personnage, et modifie l'affichage. MVC
 */ 
void Game::moveCharacter() {
    int ch = getch();
    if ((ch == KEY_UP) or (ch == KEY_DOWN) or (ch == KEY_RIGHT) or (ch == KEY_LEFT)) {
        /* Update the model */
        character -> updatePosition(ch, generator -> getSize(), generator -> getMap());        
        /* Warn the view */ 
        generator -> updateCharPosition(character);
    } 
}


/**
 * \fn void Game::equip(shared_ptr<Equipement> equipement)
 * \brief Methode d'équipement du personnage
 *
 * \param shared_ptr<Equipement> equipement
 * \return void
 *
 *  Prend un équipement, met à jour le personnage, et modifie l'affichage.
 */ 
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


/**
 * \fn void Game::generateMap()
 * \brief Methode de génération aléatoire de la map
 *
 * \param void
 * \return void
 *
 * appelle les méthodes de génération aléatoire de la carte du niveau
 * place les monstres, notifie le personnage de sa position, et met à jour l'affichage
 */ 
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

/**
 * \fn void Game::displayMap()
 * \brief Methode d'affichage de la carte
 *
 * \param void
 * \return void
 *
 * Parcours la map, et l'affichage
 */ 
void Game::displayMap() {
    screen -> displayMap(generator -> getMap(), generator -> getSize(), level);
}




int main() {
    Game game;
    game.launchGame();
    game.generateMap();
    game.displayMap();
    game.generateMap();
    game.displayMap();
    
    /* quand on perd, le niveau est amené à 0 */
    while (game.getLevel()) {
        game.action();
        game.displayMap();
    }
    endwin();
	exit(1);
}
