#include"../Monster.cpp"

class Sorcerer : public Monster {
	Sorcerer() {
		desc_ = "Un Sorcier armé d\'un sceptre ensorcelé !";
		name_ = "Sorcier";
		attack_ = 26;
		def_ = 5;
		life_ = 35;
		dext_ = 16;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
