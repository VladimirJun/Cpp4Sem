#pragma once

#ifndef C_CLASSBOX_H
#define C_CLASSBOX_H

#endif //C_CLASSBOX_H
#include <iostream>
#include <vector>
namespace MyNameSpace {
    class Box {
    private:
        int length;
        int width;
        int height;
        double weight;
        int value;

    public:
        Box(int l, int wdth, int h, double wght, int v);

        int getLength() const;

        void setLength(int length);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        double getWeight() const;

        void setWeight(double weight);

        int getValue() const;

        void setValue(int value);

        void fatal(int i);

        int totalValue(std::vector<Box> boxes);

        bool checkSum(std::vector<Box> boxes, int maxSum);

        double maxWeight(std::vector<Box> boxes, double maxV);

        bool canBeStacked(std::vector<Box> boxes);

        static bool equal(Box b1, Box b2);
    };
}