class ShortSword : public Weapon {
    public:
        ShortSword() {
            Item::name_ = "Epee courte";
		    Item::desc_ = "Une épée courte à la lame bien affutée. ";
            Equipement::att = 18;
            Equipement::def = 6;
            Equipement::dext = 3;
        }
        
};
