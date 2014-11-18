class Sorcerer : public Monster {
    public: 
	Sorcerer() {
		Character::desc_ = "Un Sorcier armé d\'un sceptre ensorcelé !";
		Character::name_ = "Sorcier";
		Character::attack_ = 26;
		Character::def_ = 5;
		Character::life_ = 35;
		Character::dext_ = 16;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
