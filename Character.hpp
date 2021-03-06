/**
 * \file Character.hpp
 * \class Character
 * \brief Character class definition
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the playable character, Model for the MVC
 *
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character{ //Abstract Class 
	protected:
		int life_; /*!< Life Points of the character */
		int maxLife_; /*!< Nombre maximum de points de vie du personnage. */
		int attack_; /*!< Attack points of the character */
		int def_; /*!< Defense points of the character */
		int dext_; /*!< Dexterity of the Character */
		int x_; /*!< X Axis of the character. Used for graphic display */
		int y_; /*!< Y Axis of the character. Used for graphic display */
		std::string name_; /*!< Name of the character. */
		std::string desc_; /*!< Short description of the character	*/
		char symbol_; /*!< Graphic representation */
		
        shared_ptr<Equipement> weapon;/*!< Equiped Weapon */
        shared_ptr<Equipement> armor;/*!< Equiped armor */
        shared_ptr<Equipement> helmet;/*!< Equiped helmet */
        shared_ptr<Equipement> shield;/*!< Equiped shield */
	
	public:
		Character();
		~Character();
		
		//Getters
		virtual int life();
		virtual int attack();
		virtual int def();
		virtual int dext();
		virtual int maxLife();
		virtual int getCombinedAtt();
		virtual int getCombinedDef();
		virtual int getCombinedDext();
		virtual int getEquipementDef();
		virtual int x();
		virtual int y();
		virtual char getSymbol();
		virtual std::string name();
		virtual std::string desc();
		virtual shared_ptr<Equipement> getWeapon();
		virtual shared_ptr<Equipement> getShield();
		virtual shared_ptr<Equipement> getHelmet();
		virtual shared_ptr<Equipement> getArmor();
		
		//Setters		
		virtual void setLife(int _life); 
		virtual void setAttack(int _attack);
		virtual void setDef(int _def);
		virtual void setDext(int _dext);
		virtual void setX(int _x);
		virtual void setY(int _y);
		virtual void setName(std::string _name);
		virtual void setDesc(std::string _desc);
		
		virtual void setWeapon(shared_ptr<Equipement> weap);
        virtual void setHelmet(shared_ptr<Equipement> helm);
        virtual void setArmor(shared_ptr<Equipement> arm);
        virtual void setShield(shared_ptr<Equipement> shie);
		
		//Other Methods
		virtual void substractLife(int damages);
		virtual void addLife(int heal);
		virtual void heal();
		
		virtual bool hitFoe(shared_ptr<Character> mon);
		virtual int attackFoe(shared_ptr<Character> mon);
		virtual bool fleeFoe(shared_ptr<Character> mon);
		virtual int defendFromFoe();
		
		//Deplacement methods
		virtual void updatePosition(int ch, int size, vector< vector<char> > map);
};

#endif
