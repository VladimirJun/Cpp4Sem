#include <iostream>
#include "DynamicArray.cpp"

int main() {
    DynamicIntArray arr1(5);
    arr1.reserve(8);
    for (int i = 0; i < arr1.getSize(); ++i) {
        arr1.getArr()[i] = i + 1;
    }
    arr1.pushBack(6);
    std::cout << "Array arr1: ";
    for (int i = 0; i < arr1.getSize(); ++i) {
        std::cout << arr1.getArr()[i] << " ";
    }
    std::cout << std::endl;

    DynamicIntArray arr(8);
    arr1.reserve(8);
    for (int i = 0; i < arr.getReservedMemory(); ++i) {
        arr.getArr()[i] = i*2;
    }
    arr.pushBack(6);
    std::cout << "Array arr1: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.getArr()[i] << " ";
    }
    std::cout << std::endl;

}