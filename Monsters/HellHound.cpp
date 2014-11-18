class HellHound : public Monster {
    public: 
	HellHound() {
		Character::desc_ = "Un monstrueux chien avec des yeux enflammés";
		Character::name_ = "Chien de l\'enfer";
		Character::attack_ = 35;
		Character::def_ = 25;
		Character::life_ = 100;
		Character::dext_ = 18;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
