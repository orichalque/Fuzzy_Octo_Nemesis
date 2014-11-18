#include"../Monster.cpp"

class Elemental : public Monster {
	Elemental() {
		desc_ = "Un nuage dégageant des flammes et des éclairs ";
		name_ = "Elemental";
		attack_ = 46;
		def_ = 28;
		life_ = 135;
		dext_ = 28;
	}
};
