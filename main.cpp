#include <iostream>
#include "dbscan.h"
#include "point.h"

int main() {
    std::vector<Point*> points;
    Point * a = new Point(1, 2, "Point1");
    Point * b = new Point(2, 3, "Point2");
    Point * c = new Point( 5, 6, "Point3");
    Point * d = new Point( 6, 7, "Point4");
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
    Dbscan dbscan;
    std::map<int, std::vector<Point*>> groups = dbscan.runAlgorithm(points, 2);
    dbscan.printGroups(groups);
    return 0;
}
