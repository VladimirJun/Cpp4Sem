#include <iostream>
#include <vector>
#include "Container.h"
#include "ClassBox.h"
//task11
using namespace MyNameSpace;
Container::Container(vector<Box> boxes, double length, double width, int height, double maxWeight) : boxes(boxes),
                                                                                                           length(length),
                                                                                                           width(width),
                                                                                                           height(height),
                                                                                                           maxWeight(
                                                                                                             maxWeight) {}

//конструктор по максимальному весу
Container::Container(double maxWeight) {

}


//геттеры и сеттеры
const vector<Box> &Container::getBoxes() const {
    return boxes;
}

void Container::setBoxes(const vector<Box> &boxes) {
    Container::boxes = boxes;
}

double Container::getLength() const {
    return length;
}

void Container::setLength(double length) {
    Container::length = length;
}

double Container::getWidth() const {
    return width;
}

void Container::setWidth(double width) {
    Container::width = width;
}

double Container::getHeight() const {
    return height;
}

void Container::setHeight(double height) {
    Container::height = height;
}

double Container::getMaxWeight() const {
    return maxWeight;
}

void Container::setMaxWeight(double maxWeight) {
    Container::maxWeight = maxWeight;
}

//получить количество коробок
int Container::GetQuantityOfBox() {
    return boxes.size();
}

//получить общий вес контейнера
double Container::getTotalWeight() {
    double count = 0;
    for (Box box: boxes)
        count += box.getWeight();

    return count;
}

//получить общую стоимость контейнера
double Container::getTotalValue() {
    double count = 0;
    for (Box box: boxes)
        count += box.getValue();

    return count;
}

//получение коробки по индексу
Box Container::getExactBoxIndex(int index) {
    if (boxes.size() <= index || index < 0) cout << "Некорретно введён индекс" << endl;
    return boxes.at(index);
}

//собственный класс исключений


string ContainerException::getMessage() const { return message; }

ContainerException::ContainerException(const char *string) {

}


//добавить коробку в контейнер
int Container::addNewBox(Box boxToAdd) {
    double totalWeight = 0;
    for (Box box: boxes) {
        totalWeight += box.getWeight();
    }
    if (totalWeight + boxToAdd.getWeight() > maxWeight) {
        throw ContainerException("Невозможно добавить коробку");
    } else {
        boxes.push_back(boxToAdd);
        return boxes.size() + 1;
    }
}

//удаление коробки по индексу
void Container::removeBox(int index) {
    boxes.erase(boxes.cbegin() + index);
}


ostream &operator<<(ostream &os, const Container &container) {

    os << " length: " << container.getLength() << " width: " << container.getWidth()
       << " height: " << container.getHeight() << " maxWeight: " << container.getMaxWeight();
    return os;
}

Box Container::getBoxIndex(int index) const {
    if (index < 0 || index >= boxes.size()) {
        throw ContainerException("Index out of range");
    }
    return boxes.at(index);
}

void Container::changeBox(int index, Box boxToChange) const {
    if (index < 0 || index >= boxes.size()) {
        throw ContainerException("Index out of range");
    }
//        boxes[index] = boxtoChange;
}