//
// Created by adam on 8/22/20.
//

#include "dbscan.h"
#include <algorithm>
#include <iostream>
#include "math.h"

Dbscan::Dbscan() {

}

std::map<int, std::vector<Point*>> Dbscan::runAlgorithm(std::vector<Point*> points, int eps) {
    int clusters = 0;
    for(int i = 0; i < points.size(); i++)
    {
        // grab arbitrary point from points (first point)
        Point * p = points.at(i);
        // if point isn't grouped
        if(!isGrouped(p))
        {
            clusters++;
            // create a new group with point
            std::vector<Point*> group;
            group.push_back(p);
            // evaluate points neighbors to determine if there are
            // more points in the group
            std::vector<Point*> neighbors = rangeQuery(points, group, p, eps);
            // for each point in neighbors
            for(int j = 0; j < neighbors.size(); j++)
            {
                Point* q = neighbors.at(j);
                // if point isn't already grouped
                if(!isGrouped(q))
                {
                    // add to group
                    group.push_back(q);
                    // evaluate neighbors
                    std::vector<Point*>newNeighbors = rangeQuery(points, group, q, eps, neighbors);
                    // add new neighbors to previous neighbors group
                    neighbors.insert(neighbors.end(), newNeighbors.begin(), newNeighbors.end());
                }
            }
            // Once all neighbors have been evaluated, add group to groups
            groups.insert(std::pair<int, std::vector<Point*>>(clusters, group));
        }
    }
    return groups;
}

std::vector<Point*> Dbscan::rangeQuery(std::vector<Point*> points,
                                       std::vector<Point*> group, Point* Q, int eps) {
    // initialize empty vector of neighbors
    std::vector<Point*> newNeighbors;
    for(int i = 0; i < points.size(); i++)
    {
        // for point p in points
        Point* p = points.at(i);
        // if p isn't already grouped and is within eps distance
        if(p!=Q && !isGrouped(p) && distFunc(p, Q) <= eps &&
            !std::count(group.begin(), group.end(), p))
        {
            // add it to neighbors
            newNeighbors.push_back(p);
        }
    }
    return newNeighbors;
}

std::vector<Point*> Dbscan::rangeQuery(std::vector<Point*> points,
                                       std::vector<Point*> group, Point* Q, int eps,
                                       std::vector<Point*> oldNeighbors) {
    // initialize empty vector of neighbors
    std::vector<Point*> newNeighbors;
    for(int i = 0; i < points.size(); i++)
    {
        // for point p in points
        Point* p = points.at(i);
        // if p isn't already grouped, is within eps distance, and
        // isn't part of old neighbors
        if(p!=Q && !isGrouped(p) && distFunc(p, Q) <= eps &&
            !std::count(oldNeighbors.begin(), oldNeighbors.end(), p) &&
            !std::count(group.begin(), group.end(), p))
        {
            // add it to neighbors
            newNeighbors.push_back(p);
        }
    }
    return newNeighbors;
}

bool Dbscan::isGrouped(Point *point) {
    bool isGrouped = false;
    for(auto it = groups.begin(); it!=groups.end(); ++it)
    {
        std::vector<Point*> group = it->second;
        if(std::count(group.begin(), group.end(), point))
        {
            isGrouped = true;
        }
    }

    return isGrouped;
}

double Dbscan::distFunc(Point *p, Point *q) {
    std::cout << "Distance function result: " <<
                sqrt(pow(abs(p->getX() - q->getX()), 2) + pow(abs(p->getY() - q->getY()), 2)) << std::endl;
    return sqrt(pow(abs(p->getX() - q->getX()), 2) + pow(abs(p->getY() - q->getY()), 2));
}

void Dbscan::printGroups(std::map<int, std::vector<Point *>> groups) {
    for(const auto &group : groups)
    {
        std::cout << "group #" << group.first << ": [";
        std::vector<Point*> groupMembers = group.second;
        for(int i = 0; i < groupMembers.size(); i++)
        {
            Point * p = groupMembers.at(i);
            if(i != groupMembers.size() - 1)
            {
                std::cout << p->getName() << ", ";
            }
            else
            {
                std::cout << p->getName() << "]" << std::endl;
            }
        }
    }
}