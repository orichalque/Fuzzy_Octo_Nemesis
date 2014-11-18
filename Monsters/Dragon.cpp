class Dragon : public Monster {
    public: 
	Dragon() {
		Character::desc_ = "Un lézard vert de 15 mètres crachant du feu";
        Character::name_ = "Dragon";
        Character::attack_ = 60;
        Character::def_ = 40;
        Character::life_ = 230;
        Character::dext_ = 29;
	}
};
