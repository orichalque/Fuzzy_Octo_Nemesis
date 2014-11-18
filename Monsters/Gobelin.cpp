#include"../Monster.cpp"

class Gobelin : public Monster {
	Gobelin() {
		desc_ = "Un gobelin verreux";
		name_ = "Gobelin";
		attack_ = 12;
		def_ = 5;
		life_ = 35;
		dext_ = 8;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
