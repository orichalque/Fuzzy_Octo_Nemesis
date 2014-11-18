class Troll : public Monster {
    public: 
	Troll() {
		Character::desc_ = "Un immense troll à l\'imposante massue.";
		Character::name_ = "Troll";
		Character::attack_ = 22;
		Character::def_ = 15;
		Character::life_ = 75;
		Character::dext_ = 9;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
