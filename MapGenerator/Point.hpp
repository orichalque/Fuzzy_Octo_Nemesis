#ifndef POINT_HPP
#define POINT_HPP

class Point {
    private:
        int x;
        int y;
    
    public:
        Point();
        Point(int x_, int y_);
        int getX();
        int getY();
};

#endif