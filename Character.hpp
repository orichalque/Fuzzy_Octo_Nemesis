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
	
	public:
		Character();
		~Character();
		
		//Getters
		int life();
		int attack();
		int def();
		int dext();
		int x();
		int y();
		std::string name();
		std::string desc();
		
		//Setters		
		virtual void setLife(int _life) = 0; //Virtual pure
		void setAttack(int _attack);
		void setDef(int _def);
		void setDext(int _dext);
		void setX(int _x);
		void setY(int _y);
		void setName(std::string _name);
		void setDesc(std::string _desc);
		
		//Other Methods
		void substractLife(int damages);
		void addLife(int heal);
		
		//Deplacement methods
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
};

#endif
