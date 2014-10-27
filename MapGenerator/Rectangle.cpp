
#include<iostream>
#include"Rectangle.hpp"

using namespace std;

Rectangle::Rectangle() {
    x = y = width = height = 0;
}

Rectangle::Rectangle(int x_, int y_, int width_, int height_) {
    x = x_;
    y = y_;
    width = width_;
    height = height_; 
}

int Rectangle::getX() {
    return x;
}

int Rectangle::getY() {
    return y;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

