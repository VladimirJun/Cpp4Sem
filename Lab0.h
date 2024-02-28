#pragma once
#ifndef C_LAB0_H
#define C_LAB0_H

#include <iostream>
#include <vector>

struct StructBox {
    int length;
    int width;
    int height;
    double weight;
    int value;

    StructBox(int l, int wdth, int h, double wght, int v);

    bool operator==(const StructBox &other) const;
};

std::ostream &operator<<(std::ostream &os, const StructBox &box);
std::istream& operator>>(std::istream& is, StructBox box);



int totalValue(std::vector<StructBox> &boxes);

bool checkSum(std::vector<StructBox> &boxes, int maxSum);

bool canBeStacked(std::vector<StructBox> &boxes);


#endif //C_LAB0_H