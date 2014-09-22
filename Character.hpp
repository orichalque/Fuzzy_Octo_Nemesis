/*
* Character Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef CHARACTER.HPP
#define CHARACTER.HPP

#include<iostream>
#include<cassert>
#include<string>

using namespace std;

class Character{ //Abstract Class 
	protected:
		int life; //Life Points of the character 
		int attack; //Attack points of the character
		int def; //Defence points of the character
		int dext; //Dexterity of the Character
		int x; //X Axis of the character. Used for graphic display
		int y; //Y Axis of the character. Used for graphic display
		string name; //Name of the character. 
		string desc; //Short description of the character
	
	public:
		virtual	Character() = 0; //Virtual pure
		int getLife();
		int getAttack();
		int getDef();
		int getDext();
			
