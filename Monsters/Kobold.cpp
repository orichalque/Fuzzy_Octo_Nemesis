#include"../Monster.cpp"

class Kobold : public Monster {
	Kobold() {
		desc_ = "Un Kobold poilu. Il sent très mauvais";
		name_ = "Kobold";
		attack_ = 16;
		def_ = 12;
		life_ = 55;
		dext_ = 14;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
