//
// Created by adam on 8/22/20.
//

#ifndef DBSCAN_POINT_H
#define DBSCAN_POINT_H
#include <string>

// Notes: Point should be initialized as a pointer, to reconcile the issue
//        of duplicate points


class Point {
public:
    Point(int x, int y, std::string name);
    int getX();
    int getY();
    std::string getName();

private:
    int xValue;
    int yValue;
    std::string mName;
};


#endif //DBSCAN_POINT_H
