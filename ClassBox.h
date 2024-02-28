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

        bool operator==(const Box &other) const;
    };

    std::istream &operator>>(std::istream &is, Box &box);

    std::ostream &operator<<(std::ostream &os, const Box &box);

}