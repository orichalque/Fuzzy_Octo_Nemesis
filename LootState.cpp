#include "LootState.hpp"

/**
 * \fn LootState::LootState(Game* game) : GameState(game)
 * \brief Instancie l'état de loot de la classe cliente
 *
 * \param Game* game
 * \return void
 *
 * Instancie l'état de distribution du butin pour la classe cliente
 * Répartie le butin pour le personnage, avec le monstre placée en paramètre de sa méthode
 */ 
LootState::LootState(Game* game) : GameState(game)
{}

/**
 * \fn void LootState::action(shared_ptr<Monster> monster)
 * \brief Lance la répartition du butin pour le personnage de la classe cliente
 *
 * \param shared_ptr<Monster> monster
 * \return void
 *
 * Lance la répartition aléatoire du butin
 * Permet à l'utilisateur de choisir s'il souhaite l'équiper ou non
 * Affiche en parallèle l'avancement avec la VUE du MVC
 */ 
void LootState::action(shared_ptr<Monster> monster)
{
	_game -> getScreen() -> clearTxt();
	vector< shared_ptr<Equipement> > loots;
    shared_ptr<Equipement> equipement;
    int ch; int x(18);
    //Crée la liste des objets laissés par le monstre 
	for (int i : monster -> getLootList()) {
		if (monster -> getLootPb() >= rand()%100) {
			loots.push_back(_game -> getEquipementFactory() -> create(i));
		}
	}	
	
	//Tant que tous les objets n'ont pas été affichés, on fait la selection
	while (not loots.empty()) {
   	    _game -> getScreen() -> clearTxt();
	    equipement = loots.back();
	    _game -> getScreen() -> mvprintTxt(2, 2, "Vous ramassez l'équipement: "+ equipement -> getName()+" !") ;
        _game -> getScreen() -> getNewEquipement(equipement);
        if (equipement -> isWeapon()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getWeapon());
            if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setWeapon(equipement);
            }
        } else 
        if (equipement -> isHelmet()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getHelmet());
             if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setHelmet(equipement);
            }
        } else 
        if (equipement -> isArmor()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getArmor());
             if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setArmor(equipement);
            }
        } else 
        if (equipement -> isShield()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getShield());
             if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setShield(equipement);
            }
        }
        
		_game -> getScreen() -> updateCharacterInfo(_game -> getCharacter());
    	this_thread::sleep_for(chrono::milliseconds(300));		
	    loots.pop_back();
	}
	
	_game -> getScreen() -> mvprintTxt(45, 9, "Appuyez sur entrée") ;
	while ((ch=getch())!=10) {
	    //On fait une pause pour terminer l'écran de distrib du butin
	}
	_game -> getScreen() -> clearTxt();
	_game -> setState(_game -> getMoveState());
	//On retourne à la carte du niveau
	
}
