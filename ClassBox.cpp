#include <iostream>
#include <vector>
using namespace std;
//task10
class Box {
private:
    int length;
    int width;
    int height;
    double weight;
    int value;
public:
    Box(int l, int wdth, int h, double wght, int v){
        if (l>0 && wdth>0 && h>0 && wght>0 && v>=0){
            length = l;
            width = wdth;
            height = h;
            weight = wght;
            value = v;
        }
        else{
            cout<<"Ошибка: Некорректно введены значения"<<endl;
            exit(-1);
        }
    }
    int getLength() const {
        return length;
    }

    void setLength(int length) {
        Box::length = length;
    }

    int getWidth() const {
        return width;
    }

    void setWidth(int width) {
        Box::width = width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Box::height = height;
    }

    double getWeight() const {
        return weight;
    }

    void setWeight(double weight) {
        Box::weight = weight;
    }

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        Box::value = value;
    }
    void fatal(int i) {
        cout<<"Ошибка: некорректные данные"<<endl;
        exit(i);

    }



    int totalValue(vector<Box> boxes) {
        if (boxes.empty()) {
            fatal(1);
            exit(-1);
        }
        int totalValue = 0;
        for (auto &box: boxes) {
            totalValue += box.getValue();
        }
        return totalValue;
    }

    bool checkSum(vector<Box> boxes, int maxSum) {
        if (boxes.empty()) fatal(-1);
        int sum = 0;
        for (auto box: boxes) {
            sum += box.getLength() + box.getWidth() + box.getHeight();
        }
        return sum <= maxSum;
    }

    double maxWeight(vector<Box> boxes, double maxV) {
        if (boxes.empty()) fatal(-1);
        double maxWeight = 0;
        for (auto box: boxes) {
            if (box.getLength() * box.getWidth() * box.getHeight() <= maxV) {
                maxWeight = max(maxWeight, box.getWeight());
            }
        }
        return maxWeight;
    }

    bool canBeStacked(vector<Box> boxes) {
        if (boxes.empty()) fatal(-1);
        if (boxes.empty()) {
            return true;
        }

        // Найдем самую маленькую коробку
        Box smallestBox = boxes[0];
        for (auto box: boxes) {
            if (box.getLength() < smallestBox.getLength() || box.getWidth() < smallestBox.getWidth() ||
                box.getHeight() < smallestBox.getHeight()) {
                smallestBox = box;
            }
        }

        for (auto box: boxes) {
            if (!(box.getLength() > smallestBox.getLength() && box.getWidth() > smallestBox.getWidth() &&
                  box.getHeight() > smallestBox.getHeight())) {
                return false;
            }
        }

        return true;
    }

    bool equal(Box b1, Box b2) {
        return b1.getLength() == b2.getLength() && b1.getWidth() == b2.getWidth() && b1.getHeight() == b2.getHeight() &&
               b2.getWeight() == b2.getWeight() && b1.getValue() == b2.getValue();
    }
};