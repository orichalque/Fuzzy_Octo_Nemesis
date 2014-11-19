class Squeleton : public Monster {
    public: 
	Squeleton() {
		Character::desc_ = "Un Squelette avec une épée et un bouclier";
		Character::name_ = "Squelette";
		Character::symbol_ = "S";
		Character::attack_ = 18;
		Character::def_ = 17;
		Character::life_ = 65;
		Character::dext_ = 13;
		Monster::lootList = {4, 21};
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
