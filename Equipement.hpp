#ifndef EQUIPEMENT_HPP
#define EQUIPEMENT_HPP

class Equipement : public Item {
	protected :
		int att;
	    int def;
		int dext;
	
	public:
	    ~Equipement();
		virtual bool isEquipement();
		virtual int getAtt();
		virtual	int getDef();
		virtual	int getDext();
		
};

#endif
