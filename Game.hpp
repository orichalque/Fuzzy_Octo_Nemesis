/**
 * \file Game.hpp
 * \class Game
 * \brief client class for FuzzyOctoNemesis
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * RogueLike Project
 *
 */

#ifndef __GAME_CPP__
#define __GAME_CPP__

/* Class Prototypes */
class GameState;
class MoveState;
class FightState;
class LootState;
class EndGameState;
/* ~~~~~~~~~~~~~~~~ */


 /**
  * \class Game
  * \brief Client class controled by the user
  */
class Game { /*Controler of the MVC*/

/* share from this permits to return a shared_ptr with this. actually buggy, gotta correct it */

    private:
        shared_ptr<Generator> generator; /*!<Map control */
        shared_ptr<Screen> screen; /*!< View with Screen */
        shared_ptr<Character> character; /*!< Model of the MVC */
        vector< shared_ptr<Monster> > monsters; /*!< Monsters of the level */
        shared_ptr<MonsterFactoryConcrete> monsterFactory; /*!< Factory creating the monsters */
        shared_ptr<BossFactory> bossFactory; /*!< Factory creating the bosses */
        shared_ptr<EquipementFactory> equipementFactory; /*!< Factory creating the equipements */
        
        int level; /*!< Actual level */
        
        // States
        shared_ptr<FightState> _fightState;/*!< State for fighting */
        shared_ptr<MoveState> _moveState;/*!< State for moving */
        shared_ptr<LootState> _lootState;/*!< State for looting the monsters */
		shared_ptr<EndGameState> _endGameState;  /*!< State for ending the game */ 
        shared_ptr<GameState> _currentState;/*!< Actual State of the game */
    
    public:
        Game();
        ~Game();
        
        /* Getters & Setters */
        shared_ptr<Generator> getGenerator() const;
        shared_ptr<Character> getCharacter() const;
        shared_ptr<Screen> getScreen() const;
        vector < shared_ptr<Monster> >* getMonstersList();
        shared_ptr<EquipementFactory> getEquipementFactory();
        int getLevel();
        void setLevel(int newLevel);
        void setState(shared_ptr<GameState> s);
        
        /* Game control methods */
        void launchGame();
        void displayMap();
        void generateMap();
        void moveCharacter();
        void equip(shared_ptr<Equipement> equipement);
        void action();
        void action(shared_ptr<Monster> mons);
        void action(bool b);
        
        // States getters-setters
        shared_ptr<GameState> getFightState();
        shared_ptr<GameState> getMoveState();
        shared_ptr<GameState> getLootState();
        shared_ptr<GameState> getEndGameState();

};

#endif	

		
