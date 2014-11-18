#include"../Monster.cpp"

class Troll : public Monster {
	Troll() {
		desc_ = "Un immense troll à l\'imposante massue.";
		name_ = "Troll";
		attack_ = 22;
		def_ = 15;
		life_ = 75;
		dext_ = 9;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
