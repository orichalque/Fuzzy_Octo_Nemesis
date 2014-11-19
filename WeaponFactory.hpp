#ifndef __WEAPONFACTORY_HPP__
#define __WEAPONFACTORY_HPP__

class WeaponFactory : public Factory {
	
	private:
	
	public:
		WeaponFactory();
		~WeaponFactory();
		shared_ptr<Equipement> create(int i);
}

#endif
