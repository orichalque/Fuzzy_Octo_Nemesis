class Elemental : public Monster {
    public: 
	Elemental() {
		Character::     desc_ = "Un nuage dégageant des flammes et des éclairs ";
        Character::		name_ = "Elemental";
        Character::		attack_ = 46;
        Character::		def_ = 28;
        Character::		life_ = 135;
        Character::		dext_ = 28;
	}
};
