#include"../Monster.cpp"

class Orc : public Monster {
	Orc() {
		desc_ = "Un orc à l'allure aggressive";
		name_ = "Orc";
		attack_ = 18;
		def_ = 11;
		life_ = 45;
		dext_ = 6;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
