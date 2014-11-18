class IronArmor : public Armor {
    public:
        IronArmor() {
            Item::name_ = "Armure en fer";
		    Item::desc_ = "Un armure en fer légèrement rouillée. ";
            Equipement::att = 0;
            Equipement::def = 15;
            Equipement::dext = 1;
                            
        }
};

