#include"../Monster.cpp"

class Dragon : public Monster {
	Dragon() {
		desc_ = "Un lézard vert de 15 mètres crachant du feu";
		name_ = "Dragon";
		attack_ = 60;
		def_ = 40;
		life_ = 230;
		dext_ = 29;
	}
};
