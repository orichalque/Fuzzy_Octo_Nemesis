class HellHound : public Monster {
    public: 
	HellHound() {
		Character::desc_ = "Un monstrueux chien avec des yeux enflammés";
		Character::name_ = "Chien de l\'enfer";
		Character::attack_ = 35;
		Character::def_ = 25;
		Character::life_ = 100;
		Character::dext_ = 18;
		Character::symbol_ = 'H';
		Monster::lootList = {7 , 12, 17, 22};
	}
	
	
	bool isBoss() {
		return true;
	}
};
