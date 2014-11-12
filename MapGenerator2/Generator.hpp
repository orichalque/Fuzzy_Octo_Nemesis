#ifndef GENERATOR_HPP
#define GENERATOR_HPP


class Generator {
    private:
        int static const SIZE = 32; //we assume using a square map.
        std::vector<Leaf*> leafs; //vector avec toutes les feuilles terminales
        std::vector<Rectangle*> halls;
        Leaf* root;  
        std::vector< std::vector<char> > mat;
                 
    public:
        Generator();
        ~Generator();
        void split();
        void createRoom();
        void createHalls();
        void  buildMap();
        bool findLeaf(Rectangle* l);
        vector< vector<char> >  getMap();
    
};

#endif
