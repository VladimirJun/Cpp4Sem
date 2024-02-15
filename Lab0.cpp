#include <iostream>
#include <vector>
using namespace std;
//task1
struct Box{
    int length;
    int width;
    int height;
    double weight;
    int value;


    Box(int l, int wdth, int h, double wght, int v){
        if (l>0 && wdth>0 && h>0 && wght>0 && v>=0){
            length = l;
            width = wdth;
            height = h;
            weight = wght;
            value = v;
        }
        else cout<<"Некорректно введены параметры объекта"<<endl;
        exit(-1);
    }


    friend ostream &operator<<(ostream &os, const Box &box);
};
void fatal(int i) {
    cout<<"Ошибка: некорректные данные"<<endl;
    exit(i);

}


//task2
int totalValue(vector<Box>& boxes) {
    if(boxes.empty()) fatal(-1);
    int totalValue = 0;
    for (auto& box : boxes) {
        totalValue += box.value;
    }
    return totalValue;
}
//task3
bool checkSum(vector<Box>& boxes, int maxSum) {
    int sum = 0;
    for (auto box : boxes) {
        sum += box.length + box.width + box.height;
    }
    return sum <= maxSum;
}
//task4
double maxWeight(vector<Box>& boxes, double maxV) {
    if(boxes.empty()) fatal(-1);
    double maxWeight = 0;
    for (auto box : boxes) {
        if (box.length  *  box.width  *  box.height <= maxV) {
            maxWeight = max(maxWeight, box.weight);
        }
    }
    return maxWeight;
}

//task5
bool canBeStacked(vector<Box> boxes) {
    if (boxes.empty()) {
        return true;
    }

    // Найдем самую маленькую коробку
    Box smallestBox = boxes[0];
    for (auto box : boxes) {
        if (box.length < smallestBox.length || box.width < smallestBox.width || box.height < smallestBox.height) {
            smallestBox = box;
        }
    }

    for (auto box : boxes) {
        if (!(box.length > smallestBox.length && box.width > smallestBox.width && box.height > smallestBox.height)) {
            return false;
        }
    }

    return true;
}
//task6
bool equal(Box b1, Box b2){
    return b1.length == b2.length && b1.width == b2.width && b1.height == b2.height && b2.weight == b2.weight && b1.value == b2.value;
}
//task7
ostream &operator<<(ostream &os, const Box &box) {
    os << "length: " << box.length << " width: " << box.width << " height: " << box.height << " weight: " << box.weight
       << " value: " << box.value;
    return os;
}

istream& operator>>(istream& is, Box box) {
    is >> box.length >> box.width >> box.height >> box.weight >> box.value;
    return is;
}

