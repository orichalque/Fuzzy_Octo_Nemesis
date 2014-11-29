/**
 * \file Game.hpp
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

class GameState;
class MoveState;
class FightState;
class LootState;
class EndGameState;


class Game { /*Controler of the MVC*/

/* share from this permits to return a shared_ptr with this. actually buggy, gotta correct it */

    private:
        shared_ptr<Generator> generator; //View with Screen
        shared_ptr<Screen> screen; //View with Screen
        shared_ptr<Character> character; //Model
        vector< shared_ptr<Monster> > monsters;
        shared_ptr<MonsterFactoryConcrete> monsterFactory;
        shared_ptr<BossFactory> bossFactory;
        shared_ptr<EquipementFactory> equipementFactory;
        
        int level;
        
        // States
        shared_ptr<FightState> _fightState;
        shared_ptr<MoveState> _moveState;
        shared_ptr<LootState> _lootState;
		shared_ptr<EndGameState> _endGameState;
        
        shared_ptr<GameState> _currentState;
    
    public:
        Game();
        ~Game();
        
        shared_ptr<Game> getSharedPtrThis();
        shared_ptr<Generator> getGenerator() const;
        shared_ptr<Character> getCharacter() const;
        shared_ptr<Screen> getScreen() const;
        vector < shared_ptr<Monster> >* getMonstersList();
        shared_ptr<EquipementFactory> getEquipementFactory();
        void launchGame();
        void displayMap();
        void generateMap();
        void moveCharacter();
        void equip(shared_ptr<Equipement> equipement);
        int fight(shared_ptr<Character> monster);
        int loot(shared_ptr<Monster> monster);
        void action();
        void action(shared_ptr<Monster> mons);
        void action(bool b);
        int getLevel();
        
        
        // States getters-setters
        shared_ptr<GameState> getFightState();
        shared_ptr<GameState> getMoveState();
        shared_ptr<GameState> getLootState();
        shared_ptr<GameState> getEndGameState();
        
        //LootState getLootState() const;
        //WonLevelState getWonLevelState() const;
        //DeadState getDeadState() const;
        //PauseState getPauseState() const;
        
        void setLevel(int newLevel);
        void setState(shared_ptr<GameState> s);
};

#endif	

		
