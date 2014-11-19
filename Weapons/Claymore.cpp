class Claymore : public Weapon {
    public:
        Claymore() {
            Item::name_ = "Claymore";
		    Item::desc_ = "Une monstrueuse épée large. Se tient à deux mains. ";
            Equipement::att = 36;
            Equipement::def = 8;
            Equipement::dext = 2;
        }

        
};
