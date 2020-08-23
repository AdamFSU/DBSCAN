//
// Created by adam on 8/22/20.
//

#ifndef DBSCAN_DBSCAN_H
#define DBSCAN_DBSCAN_H

#include <vector>
#include <map>
#include "point.h"


class Dbscan {
public:
    Dbscan();
    std::map<int, std::vector<Point*>> runAlgorithm(std::vector<Point*> points, int eps);
    std::vector<Point*> rangeQuery(std::vector<Point*> points, Point* Q, int eps);
    bool isGrouped(Point* point);
    double distFunc(Point* p, Point* q);
    void printGroups(std::map<int, std::vector<Point*>> groups);

private:
    std::map<int, std::vector<Point*>> groups;
};


#endif //DBSCAN_DBSCAN_H
