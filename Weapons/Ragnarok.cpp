class Ragnarok : public Weapon {
    public:
        Ragnarok() {
            Item::name_ = "Ragnarok";
		    Item::desc_ = "La lame maîtresse à la puissance incommensurable. ";
            Equipement::att = 74;
            Equipement::def = 18;
            Equipement::dext = 15;
        }
};
