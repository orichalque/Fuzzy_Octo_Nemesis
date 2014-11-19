
class ArchMagus : public Monster {
    public: 
	ArchMagus() {
		Character::desc_ = "Un archimage dégageant une aura sinistre";
        Character::name_ = "Archimage";
        Character::attack_ = 52;
        Character::def_ = 23;
        Character::life_ = 99;
		Character::dext_ = 27;	
		Character::symbol_ = "A";
		Monster::lootList = {6 ,13 };
	}
};




