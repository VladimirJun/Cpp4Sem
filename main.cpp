#include <iostream>
#include "ClassBox.h"
#include "Container.h"
#include <ostream>

using namespace std;
using namespace MyNameSpace;

int main() {
    std::cout << "Hello, World!" << endl;
    MyNameSpace:: Box b1 = Box(10, 10, 10, 10, 2000);
    Box b2 = Box(10, 10, 10, 10, 2000);
    Box b3 = Box(10, 10, 10, 10, 2003);
    bool flag = MyNameSpace::Box::equal(b1,b2);
    bool flag1 = MyNameSpace::Box::equal(b1, b3);
    vector<Box> boxes;
    boxes.push_back(b1);
    boxes.push_back(b2);
    boxes.push_back(b3);
    Container container = Container(boxes,10,10,10,12345);
    cout<<container.getMaxWeight()<<endl;
    cout<<container.getWidth()<<endl;
    cout << flag << endl;
    cout << flag1 << endl;
}