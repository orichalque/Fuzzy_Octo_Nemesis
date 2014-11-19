#ifndef __ARMORFACTORY_HPP__
#define __ARMORFACTORY_HPP__

class ArmorFactory : public Factory {
	
	private:
	
	public:
		ArmorFactory();
		~ArmorFactory();
		shared_ptr<Equipement> create(int i);
}

#endif
