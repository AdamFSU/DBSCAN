//
// Created by adam on 8/22/20.
//

#include "point.h"

Point::Point(int x, int y, std::string name) {
    xValue = x;
    yValue = y;
    mName = name;
}

int Point::getX() {
    return xValue;
}

int Point::getY() {
    return yValue;
}

std::string Point::getName() {
    return mName;
}