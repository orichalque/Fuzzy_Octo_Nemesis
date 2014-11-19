#ifndef __EQUIPEMENTFACTORY_HPP__
#define __EQUIPEMENTFACTORY_HPP__

class EquipementFactory : public Factory {
	private:
	
	public:
		EquipementFactory();
		~EquipementFactory();
		shared_ptr<Equipement> create(int i);
};

#endif
