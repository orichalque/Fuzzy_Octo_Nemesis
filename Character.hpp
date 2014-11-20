/*
* Character abstract Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character{ //Abstract Class 
	protected:
		int life_; //Life Points of the character 
		int attack_; //Attack points of the character
		int def_; //Defense points of the character
		int dext_; //Dexterity of the Character
		int x_; //X Axis of the character. Used for graphic display
		int y_; //Y Axis of the character. Used for graphic display
		std::string name_; //Name of the character. 
		std::string desc_; //Short description of the character	
		char symbol_; //Graphic representation	
		
        shared_ptr<Equipement> weapon;
        shared_ptr<Equipement> armor;
        shared_ptr<Equipement> helmet;
        shared_ptr<Equipement> shield;
	
	public:
		Character();
		~Character();
		
		//Getters
		int life();
		int attack();
		int def();
		int dext();
		int getCombinedAtt();
		int getCombinedDef();
		int getCombinedDext();
		int x();
		int y();
		char getSymbol();
		std::string name();
		std::string desc();
		shared_ptr<Equipement> getWeapon();
		shared_ptr<Equipement> getShield();
		shared_ptr<Equipement> getHelmet();
		shared_ptr<Equipement> getArmor();
		
		//Setters		
		void setLife(int _life); 
		void setAttack(int _attack);
		void setDef(int _def);
		void setDext(int _dext);
		void setX(int _x);
		void setY(int _y);
		void setName(std::string _name);
		void setDesc(std::string _desc);
		
		void setWeapon(shared_ptr<Equipement> weap);
        void setHelmet(shared_ptr<Equipement> helm);
        void setArmor(shared_ptr<Equipement> arm);
        void setShield(shared_ptr<Equipement> shie);
		
		//Other Methods
		void substractLife(int damages);
		void addLife(int heal);
		
		//Deplacement methods
		void updatePosition(int ch, int size, vector< vector<char> > map);
};

#endif
