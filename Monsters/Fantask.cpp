#include"../Monster.cpp"

class Fantask : public Monster {
	Fantask() {
		desc_ = "Un fantassin squelette, caché derrière un immense bouclier";
		name_ = "Fantassin Squelette";
		attack_ = 26;
		def_ = 35;
		life_ = 78;
		dext_ = 25;
	}
};
