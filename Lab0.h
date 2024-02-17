#pragma once
#ifndef C_LAB0_H
#define C_LAB0_H

#include <iostream>
#include <vector>

struct StructBox{
    int length;
    int width;
    int height;
    double weight;
    int value;
};

using namespace std;

int  totalValue(vector<StructBox> boxes);

bool checkSum(vector<StructBox> boxes, int maxSum);

bool canBeStacked(std::vector<StructBox> boxes);
bool equal(StructBox b1, StructBox b2);
ostream &operator<<(ostream &os, const StructBox &box);
istream& operator>>(istream& is, StructBox box);


#endif //C_LAB0_H