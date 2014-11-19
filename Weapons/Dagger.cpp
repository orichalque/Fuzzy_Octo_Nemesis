class Dagger : public Weapon {
    public:
        Dagger() {
            Item::name_ = "Dague";
		    Item::desc_ = "Une dague affutée.";
            Equipement::att = 12;
            Equipement::def = 3;
            Equipement::dext = 4;
        }

};
