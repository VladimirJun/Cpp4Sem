#include <iostream>
#include "Lab0.h"
#include "Container.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << endl;
    Box b1 = Box(10, 10, 10, 10, 2000);
    Box b2 = Box(10, 10, 10, 10, 2000);
    Box b3 = Box(10, 10, 10, 10, 2003);
    bool flag = equal(b1, b2);
    bool flag1 = equal(b1, b3);
    vector<Box> boxes;
    boxes.push_back(b1);
    boxes.push_back(b2);
    boxes.push_back(b3);
    for(Box box:boxes){
        cout<<box<<endl;
    }
    Container give_me_a_name(boxes,1,1,1,1000);
    cout << flag << endl;
    cout << flag1 << endl;
}