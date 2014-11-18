class Orc : public Monster {
    public: 
	Orc() {
		Character::desc_ = "Un orc à l'allure aggressive";
		Character::name_ = "Orc";
		Character::attack_ = 18;
		Character::def_ = 11;
		Character::life_ = 45;
		Character::dext_ = 6;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
