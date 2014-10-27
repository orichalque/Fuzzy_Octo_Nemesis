#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include<stdint.h>

class Generator {
    private:
        static const uint32_t MAX_LEAF_SIZE = 20;
        static const uint32_t w = 10;
        static const uint32_t h = 10;
        
        
    public:
        std::vector<Leaf> leafs;
        Generator();
        void fetchNodes(Leaf f);
        void generate(void);
        Leaf getRoot(void);
};


#endif
