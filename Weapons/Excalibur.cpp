class Excalibur : public Weapon {
    public:
        Excalibur() {
            Item::name_ = "Excalibur";
		    Item::desc_ = "Elle dégage une aura sacrée";
            Equipement::att = 41;
            Equipement::def = 9;
            Equipement::dext = 9;
        }
        

};
