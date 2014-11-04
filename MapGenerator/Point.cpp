#include"Point.hpp"

using namespace std;

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x_, int y_) {
    x = x_;
    y = y_;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}