class Sorcerer : public Monster {
    public: 
	Sorcerer() {
		Character::desc_ = "Un Sorcier armé d\'un sceptre ensorcelé !";
		Character::name_ = "Sorcier";
		Character::symbol_ = 'S';
		Character::attack_ = 26;
		Character::def_ = 5;
		Character::life_ = 35;
		Character::dext_ = 16;
		Monster::lootList = {3 , 11};
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
