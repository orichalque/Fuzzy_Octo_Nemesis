#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include<stdint.h>

class Generator {
    private:
        static const uint32_t w = 32;
        static const uint32_t h = 32;
        
        
    public:
        std::vector<Rectangle> halls; //Hallway between rooms
        std::vector<Leaf> leafs;
        Generator();
        void fetchNodes(Leaf f);
        void generate(void);
        void draw(void);
        void displayHalls();
        Leaf getRoot(void);
		void getRoomsAndHalls();
};


#endif
