#include"../Monster.cpp"

class Squeleton : public Monster {
	Squeleton() {
		desc_ = "Un Squelette avec une épée et un bouclier";
		name_ = "Squelette";
		attack_ = 18;
		def_ = 17;
		life_ = 65;
		dext_ = 13;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
