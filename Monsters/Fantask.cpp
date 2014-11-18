class Fantask : public Monster {
    public: 
	Fantask() {
		Character::desc_ = "Un fantassin squelette, caché derrière un immense bouclier";
		Character::name_ = "Fantassin Squelette";
		Character::attack_ = 26;
		Character::def_ = 35;
		Character::life_ = 78;
		Character::dext_ = 25;
	}
};
