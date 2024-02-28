#include <iostream>
#include <cassert>
#include "ClassBox.h"
using namespace std;
//task10
using namespace MyNameSpace;
    Box:: Box(int l, int wdth, int h, double wght, int v){
        assert(l>0);
        assert(wdth>0);
        assert(h>0);
        assert(wght>0);
        assert(v>0);
        length = l;
        width = wdth;
        height = h;
        weight = wght;
        value = v;
    }

int Box::getLength() const {
    return length;
}

void Box::setLength(int length) {
    assert(length>=0);
    Box::length = length;
}

int Box::getWidth() const {
    return width;
}

void Box::setWidth(int width) {
    assert(width>=0);
    Box::width = width;
}

int Box::getHeight() const {
    return height;
}

void Box::setHeight(int height) {
    assert(height>=0);
    Box::height = height;
}

double Box::getWeight() const {
    return weight;
}

void Box::setWeight(double weight) {
    assert(weight>=0);
    Box::weight = weight;
}

int Box::getValue() const {
    return value;
}

void Box::setValue(int value) {
    assert(value>0);
    Box::value = value;
}

std:: ostream  &operator<<(ostream &os, const Box &box) {
    os << "length: " << box.getLength() << " width: " << box.getWidth() << " height: " << box.getHeight() << " weight: " << box.getWeight()
       << " value: " << box.getValue();
    return os;
}
bool Box:: operator==(const Box &other) const {
    return length == other.length && width == other.width && height == other.height &&
           weight == other.weight && value == other.value;
}
std::istream &operator>>(std::istream &is, Box &box) {
    int length, height, width,  value;
    double weight;
    is >> length >> height >> width>> value >> weight;
    box.setLength(length);
    box.setHeight(height);
    box.setWidth(width);
    box.setValue(value);
    box.setWeight(weight);
    return is;
}