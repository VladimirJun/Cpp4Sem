#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "Lab0.h"




StructBox:: StructBox(int l, int wdth, int h, double wght, int v){
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

//task2
int totalValue(std::vector<StructBox>* boxes) {
    if (boxes== nullptr||!boxes->empty()) static_assert("boxes cannot be empty");
    int totalValue = 0;
    for (auto& box : *boxes) {
        totalValue += box.value;
    }
    return totalValue;
}
//task3
bool checkSum(std::vector<StructBox>* boxes, int maxSum) {
    if (boxes== nullptr||!boxes->empty()) static_assert("boxes cannot be empty");
    int sum = 0;
    for (auto box : *boxes) {
        sum += box.length + box.width + box.height;
    }
    return sum <= maxSum;
}
//task4
double maxWeight(std::vector<StructBox> *boxes, double maxV) {
    if (boxes== nullptr||!boxes->empty()) static_assert("boxes cannot be empty");
    double maxWeight = 0;
    for (auto box : *boxes) {
        if (box.length  *  box.width  *  box.height <= maxV) {
            maxWeight = std::max(maxWeight, box.weight);
        }
    }
    return maxWeight;
}

//task5
 bool  canBeStacked(std::vector<StructBox> boxes) {
    if (boxes.empty()) {
        return true;
    }
    int index = 0;
    // Найдем самую маленькую коробку
    StructBox smallestBox = boxes[0];
    for (auto box : boxes) {
        if (box.length < smallestBox.length || box.width < smallestBox.width || box.height < smallestBox.height) {
            smallestBox = box;
        }
    }
    boxes.erase(std::remove(boxes.begin(), boxes.end(), smallestBox), boxes.end());
    for (auto box : boxes) {
        if (!(box.length > smallestBox.length && box.width > smallestBox.width && box.height > smallestBox.height)) {
            return false;
        }
    }
    return true;
}
//оператор вывода
std:: ostream  &operator<<(std::ostream &os, const StructBox &box) {
    os << "length: " << box.length << " width: " << box.width << " height: " << box.height << " weight: " << box.weight
       << " value: " << box.value;
    return os;
}

//оператор ввода
std::istream &operator>>(std::istream &is, StructBox box) {
    is >> box.length >> box.width >> box.height >> box.weight >> box.value;
    return is;
}
//оператор сравнения
bool  StructBox:: operator==(const StructBox &other) const  {
    return length == other.length && width == other.width && height == other.height &&
           weight == other.weight && value == other.value;
}

