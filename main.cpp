#include <iostream>
#include <cassert>
#include <vector>
#include "DynamicArray.h"
using namespace std;
int main() {


    DynamicIntArray arr1;
    arr1 = DynamicIntArray(5,10);
    cout<<"Arr1: "<<arr1<<endl;
    DynamicIntArray arr2 = DynamicIntArray(7);
    cout<<"Arr2: "<<arr2<<endl;
    DynamicIntArray arr3 = DynamicIntArray(7,8);
    DynamicIntArray twoArr = arr1+arr3;
    cout<<"First arr: "<<arr1<<" Second arr: "<<arr3<<" Concate Arrs: "<<twoArr<<endl;
    arr2.pushBack(5);
    cout<<"arr2 after push back: "<<arr2<<endl;
    DynamicIntArray arrPrev = DynamicIntArray(5,10);
    DynamicIntArray arrMoved = DynamicIntArray(std::move(arrPrev));
    cout<<"Array after Move: "<<arrMoved<<endl;
    DynamicIntArray arrEmpty = DynamicIntArray();
    cout<<"empty array: "<<arrEmpty<<endl;
    arrEmpty.pushBack(15);
    arrEmpty.pushBack(38);
    arrEmpty.pushBack(45);
    cout<<"empty array after pushback: "<<arrEmpty<<endl;
    arrEmpty.popBack();
    arrEmpty.popBack();
    cout<<"empty array after popback: "<<arrEmpty<<endl;
    DynamicIntArray arrForComp = DynamicIntArray(4,9);
    DynamicIntArray arrForComp2 = DynamicIntArray(5,9);
    arrForComp2.popBack();
    arrForComp2.pushBack(INT_MIN	);
    bool flag = arrForComp<arrForComp2;
    cout<<"FLAG: "<<flag<<endl;
    bool flag2 = "aaa"<"bb";
    cout<<flag2<<endl;
    DynamicIntArray arrLen2 = DynamicIntArray(2,99);
    cout<<"Size: "<<arrLen2.getSize()<<" Capacity: "<<arrLen2.getCapacity()<<endl;
    arrLen2.pushBack(100);
    cout<<arrLen2<<endl;
    cout<<"Size: "<<arrLen2.getSize()<<" Capacity: "<<arrLen2.getCapacity()<<endl;
    arrLen2.pushBack(101);
    cout<<arrLen2<<endl;
    cout<<"Size: "<<arrLen2.getSize()<<" Capacity: "<<arrLen2.getCapacity()<<endl;
    arrLen2.pushBack(102);
    cout<<arrLen2<<endl;
    cout<<"Size: "<<arrLen2.getSize()<<" Capacity: "<<arrLen2.getCapacity()<<endl;
    arrLen2.pushBack(103);
    cout<<arrLen2<<endl;
    cout<<"Size: "<<arrLen2.getSize()<<" Capacity: "<<arrLen2.getCapacity()<<endl;
    arrLen2.pushBack(104);
    cout<<arrLen2<<endl;
    cout<<"Size: "<<arrLen2.getSize()<<" Capacity: "<<arrLen2.getCapacity()<<endl;
    arrLen2.pushBack(106);
    cout<<arrLen2<<endl;
    cout<<"Size: "<<arrLen2.getSize()<<" Capacity: "<<arrLen2.getCapacity()<<endl;
    arrLen2.resize(20);
    cout<<arrLen2<<endl;
    return 0;
}