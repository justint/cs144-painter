//
//  Rectangle.cpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/26/16.
//
//

#include <stdio.h>
#include <vector>
#include <typeinfo>

#include "Drawable.hpp"

template<typename T>
class Rectangle : public Drawable<T> {
public:
    Rectangle(T x1, T y1, T x2, T y2);
    void draw(const Context& c);
    
private:
    T x1, x2, y1, y2;
};

template<typename T>
Rectangle<T>::Rectangle(T x1, T y1, T x2, T y2) : Drawable<T>() {
    std::vector<T> v;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
};