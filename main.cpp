#include <iostream>
#include "ClassBox.h"
#include "Container.h"
#include "Lab0.h"

#include <ostream>

using namespace std;
using namespace MyNameSpace;

int main() {
    std::cout << "Hello, World!" << endl;
    StructBox box1 = StructBox(10, 10, 10, 10, 10);
    StructBox box2 = StructBox(9, 9, 9, 9, 9);
    StructBox box3 = StructBox(8, 8, 8, 8, 8);
    cout << "Weight of the box1 is " << box1.weight << endl;
    cout << "Weight of the box2 is " << box2.weight << endl;
    cout << "Weight of the box3 is " << box3.weight << endl;

    MyNameSpace::Box b1 = Box(10, 10, 10, 10, 2000);
    Box b2 = Box(10, 10, 10, 10, 2000);
    Box b3 = Box(10, 10, 10, 10, 2003);
    vector<Box> boxes;
    boxes.push_back(b1);
    boxes.push_back(b2);
    boxes.push_back(b3);
    MyNameSpace::Container container = Container(boxes, 10, 10, 10, 12345);
    cout << box1.operator==(box2) << endl;
    MyNameSpace::operator<<(cout, container);
}