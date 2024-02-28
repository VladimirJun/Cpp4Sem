#include <iostream>
#include <vector>
#include <cassert>
#include "Container.h"
#include "ClassBox.h"
//task11
namespace MyNameSpace {

    Container::Container(vector<Box> b,
                         double l,
                         double wdth,
                         int h,
                         double mW) {
        assert(l > 0);
        assert(wdth > 0);
        assert(h > 0);
        assert(mW > 0);
        length = l;
        width = wdth;
        height = h;
        maxWeight = mW;
        boxes = b;

    }


//геттеры и сеттеры
    const vector<Box> &Container::getBoxes() const {
        return boxes;
    }

    void Container::setBoxes(const vector<Box> &boxes) {
        assert(boxes.size() >= 0);
        Container::boxes = boxes;
    }

    double Container::getLength() const {
        return length;
    }

    void Container::setLength(double length) {
        assert(length > 0);
        Container::length = length;
    }

    double Container::getWidth() const {
        return width;
    }

    void Container::setWidth(double width) {
        assert(width > 0);
        Container::width = width;
    }

    double Container::getHeight() const {
        return height;
    }

    void Container::setHeight(double height) {
        assert(height > 0);
        Container::height = height;
    }

    double Container::getMaxWeight() const {
        return maxWeight;
    }

    void Container::setMaxWeight(double maxWeight) {
        assert(maxWeight > 0);
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
        assert (boxes.size() >= index || index > 0);
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
        assert (boxes.size() >= index || index >= 0);

        boxes.erase(boxes.cbegin() + index);
    }


    ostream &operator<<(ostream &os, const MyNameSpace::Container &container) {
        os << " length: " << container.getLength() << " width: " << container.getWidth()
           << " height: " << container.getHeight() << " maxWeight: " << container.getMaxWeight();
        for (Box box: container.getBoxes()) {
            os << "\nBOX\n" << "Length: " << box.getLength() << " Width: " << box.getWidth() << " Height: " << box.getHeight()
               << " Weight: " << box.getWeight() << " Value: " << box.getValue();
        }

        return os;
    }


    istream &operator>>(istream &is, Container &container) {
        vector<Box> b;
        int l;
        int wdth;
        int h;
        int mW;
        is >> l >> wdth >> h >> mW;
        for (Box box: container.getBoxes()) {
            box.setWidth(l);
            box.setWidth(wdth);
            box.setWidth(h);
            box.setWidth(mW);
        }
        return is;
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
    }
}