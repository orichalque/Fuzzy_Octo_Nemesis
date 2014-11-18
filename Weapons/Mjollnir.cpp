class Mjollnir : public Weapon {
    public:
        Mjollnir() {
            Item::name_ = "Mjollnir";
		    Item::desc_ = "Ce marteau est dévastateur, mais terriblement lourd. ";
            Equipement::att = 51;
            Equipement::def = 15;
            Equipement::dext = 9;
        }
};
