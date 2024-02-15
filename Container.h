#include "Lab0.h"
#ifndef C_CONTAINER_H
using namespace std;
#endif C___CONTAINER_H
class Container {
private:
    vector<Box> boxes;
    double length;
    double width;
    double height;
    double maxWeight;
public:
    Container(vector<Box> boxes, double length, double width, int height, double maxWeight);
    explicit Container(double maxWeight);
};
vector<Box> getBoxes();
void setBoxes(const vector<Box> &boxes);
double getLength();
void setLength(double length);
double getWidth();
void setWidth(double width);
double getHeight();
void setHeight(int height);
double getMaxWeight();
void setMaxWeight(double maxWeight);
int GetQuantityOfBox();
double getTotalWeight();
double getTotalValue();
Box getExactBoxIndex(int index);
class ContainerException {
    string message;
};
string getMessage();
int addNewBox(Box boxToAdd);
void removeBox(int index);
ostream &operator<<(ostream &os, Container container);
istream &operator>>(istream &is, Container &container);
Box getBoxIndex(int index);
void changeBox(int index,Box boxToChange);
