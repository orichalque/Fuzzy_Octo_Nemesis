class Knife : public Weapon {
    public:
        Knife() {
            Item::name_ = "Couteau";
		    Item::desc_ = "Un petit couteau de cuisine. Mal barré";
            Equipement::att = 5;
            Equipement::def = 0;
            Equipement::dext = 1;
        }
        

};
