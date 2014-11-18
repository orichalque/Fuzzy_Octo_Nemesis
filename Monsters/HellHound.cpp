#include"../Monster.cpp"

class HellHound : public Monster {
	HellHound() {
		desc_ = "Un monstrueux chien avec des yeux enflammés";
		name_ = "Chien de l\'enfer";
		attack_ = 35;
		def_ = 25;
		life_ = 100;
		dext_ = 18;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
