class MithrilArmor : public Armor {
    public:
        MithrilArmor() {
            Item::name_ = "Armure en mithril";
		    Item::desc_ = "Une somptueuse armure en mithril, légère comme du cuir et dure comme de la pierre. ";
            Equipement::att = 2;
            Equipement::def = 27;
            Equipement::dext = 4;
                            
        }
};

