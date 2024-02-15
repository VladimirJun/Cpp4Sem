#pragma once
#ifndef C___LAB0_H
#define C___LAB0_H

#include <iostream>
#include <vector>

struct Box{
    int length;
    int width;
    int height;
    double weight;
    int value;
};

using namespace std;

int totalValue(vector<Box> boxes);

bool checkSum(vector<Box> boxes, int maxSum);

bool canBeStacked(std::vector<Box> boxes);
bool equal(Box b1, Box b2);
ostream &operator<<(ostream &os, const Box &box);
istream& operator>>(istream& is, Box box);


#endif //C___LAB0_H
