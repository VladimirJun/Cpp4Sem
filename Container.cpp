#include <iostream>
#include <vector>
#include "Lab0.h"


using namespace std;
//task11
class Container {


private:
    vector<Box> boxes;
    double length;
    double width;
    double height;
    double maxWeight;
public:
    Container(vector<Box> boxes, double length, double width, int height, double maxWeight) : boxes(boxes),
                                                                                               length(length),
                                                                                               width(width),
                                                                                               height(height),
                                                                                               maxWeight(
                                                                                                       maxWeight) {}

//конструктор по максимальному весу
    explicit Container(double maxWeight) : maxWeight(maxWeight) {}

//геттеры и сеттеры
    vector<Box> getBoxes() const {
        return boxes;
    }

    void setBoxes(const vector<Box> &boxes) {
        Container::boxes = boxes;
    }

    double getLength() const{
        return length;
    }

    void setLength(double length) {
        Container::length = length;
    }

    double getWidth() const {
        return width;
    }

    void setWidth(double width) {
        Container::width = width;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Container::height = height;
    }

    double getMaxWeight() const {
        return maxWeight;
    }

    void setMaxWeight(double maxWeight) {
        Container::maxWeight = maxWeight;
    }

//получить количество коробок
    int GetQuantityOfBox() {
        return boxes.size();
    }

//получить общий вес контейнера
    double getTotalWeight() {
        double count = 0;
        for (Box box: boxes)
            count += box.weight;

        return count;
    }

//получить общую стоимость контейнера
    double getTotalValue() {
        double count = 0;
        for (Box box: boxes)
            count += box.value;

        return count;
    }

//получение коробки по индексу
    Box getExactBoxIndex(int index) {
        if (boxes.size() <= index || index < 0) cout << "Некорретно введён индекс" << endl;
        return boxes.at(index);
    }

//собственный класс исключений
    class ContainerException {

    private:
        string message;
    public:
        ContainerException(string message) : message{message} {}

        string getMessage() const { return message; }

    };

//добавить коробку в контейнер
    int addNewBox(Box boxToAdd) {
        double totalWeight = 0;
        for (Box box: boxes) {
            totalWeight += box.value;
        }
        if (totalWeight + boxToAdd.weight > maxWeight) {
            throw ContainerException("Невозможно добавить коробку");
        } else {
            boxes.push_back(boxToAdd);
            return boxes.size() + 1;
        }
    }

//удаление коробки по индексу
    void removeBox(int index) {
        boxes.erase(boxes.cbegin() + index);
    }

    //task12
    friend ostream &operator<<(ostream &os, Container container) {
        os << "Length: " << container.getLength() << ", Width: " << container.getWidth() << ", Height: "
           << container.getHeight() << ", Max Weight: " << container.getMaxWeight() << std::endl;
        for (Box &box: container.getBoxes()) {
            os << "Box: " << box.length << "x" << box.width << "x" << box.height << ", Max Weight: " << box.weight
               << endl;
        }
        return os;
    }

    friend istream &operator>>(istream &is, Container &container) {
        double length, width, height, maxWeight;
        is >> length >> width >> height >> maxWeight;
        container.setLength(length);
        container.setWidth(width);
        container.setHeight(height);
        container.setMaxWeight(maxWeight);
        return is;
    }
     Box getBoxIndex(int index) const {
        if (index < 0 || index >= boxes.size()) {
            throw ContainerException("Index out of range");
        }
        return boxes.at(index);
    }
    void changeBox(int index,Box boxToChange) const {
        if (index < 0 || index >= boxes.size()) {
            throw ContainerException("Index out of range");
        }
//        boxes[index] = boxtoChange;
    }

};

