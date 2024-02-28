#pragma once

#include <string>
#include <ostream>
#include "ClassBox.h"

#ifndef C_CONTAINER_H
#endif //C_CONTAINER_H
using namespace std;
namespace MyNameSpace {
    class Container {
    private:

        vector <Box> boxes;
        double length;
        double width;
        double height;
        double maxWeight;
    public:
        Container(vector <Box> boxes, double length, double width, int height, double maxWeight);


        const vector <Box> &getBoxes() const;

        void setBoxes(const vector <Box> &boxes);

        double getLength() const;

        void setLength(double length);

        double getWidth() const;

        void setWidth(double width);

        double getHeight() const;

        void setHeight(double height);

        double getMaxWeight() const;

        void setMaxWeight(double maxWeight);

        int GetQuantityOfBox();

        double getTotalWeight();

        double getTotalValue();

        Box getExactBoxIndex(int index);

        int addNewBox(Box boxToAdd);

        void removeBox(int index);

        Box getBoxIndex(int index) const;

        void changeBox(int index, Box boxToChange) const;

    };

    class ContainerException {
        string message;

        string getMessage() const;

    public:
        ContainerException(const char string[53]);
    };

    string getMessage();


    ostream &operator<<(ostream &os, const MyNameSpace::Container &container);

    istream &operator>>(istream &is, Container &container);
}