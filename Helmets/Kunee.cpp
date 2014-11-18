class Kunee : public Helmet {
    public:
        Kunee() {
            Item::name_ = "Kunée";
		    Item::desc_ = "Le casque légendaire Kunée. Il dégage une atmosphère confortante. ";
            Equipement::att = 4;
            Equipement::def = 25;
            Equipement::dext = 7;
                            
        }
};

