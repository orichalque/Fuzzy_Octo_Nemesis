#include"Leaf.cpp"
#include"Generator.hpp"
#include<vector>

using namespace std;

Generator::Generator(void) {
    
}

void Generator::generate(void) {
    Leaf root(0,0,w,h);
    root.split(leafs);
}

int main() {
    Generator g;
    g.generate();
    for (Leaf l : g.leafs) {
        //l.getStat();
    }
    cout << g.leafs.size();
    return 0;
}
