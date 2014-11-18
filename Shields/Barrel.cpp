class Barrel : public Shield {
    public:
        Barrel() {
            Item::name_ = "Couvercle de tonneau";
		    Item::desc_ = "Un couvercle de tonneau avec une poignée. Fragile.";
            Equipement::att = 0;
            Equipement::def = 4;
            Equipement::dext = 0;
                            
        }
};

