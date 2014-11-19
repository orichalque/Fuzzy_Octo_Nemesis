
class Kobold : public Monster {
    public:
	Kobold() {
		Character::desc_ = "Un Kobold poilu. Il sent très mauvais";
		Character::name_ = "Kobold";
		Character::symbol_ = "K";
		Character::attack_ = 16;
		Character::def_ = 12;
		Character::life_ = 55;
		Character::dext_ = 14;
		Monster::lootList = {4, 16};
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
