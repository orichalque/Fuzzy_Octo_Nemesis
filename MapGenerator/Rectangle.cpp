
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

<<<<<<< HEAD
void Rectangle::displayInfo() {
    cout << "Coordonnées :"<<x<<"*"<<y<<" Dimensions :"<<width<<"*"<<height<<endl;
}

=======
void Rectangle::getInfo() {
	cout << "("<<x<<","<<y<<") de taille "<<width<<"*"<<height<<" .";
}
>>>>>>> ff879ccdb39ccbc7ee3f32a55d6a42bb9cf1d31a
int Rectangle::getX() {
    return x;
}

int Rectangle::getY() {
    return y;
}

int Rectangle::getX2() { //up left corner
    return (x+width);
}

int Rectangle::getY2() { //bottom right corner
    return (y+height);
}


int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

