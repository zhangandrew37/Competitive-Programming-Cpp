#include <iostream>
#include <memory>
#include <vector>

using namespace std;

double pointDistance(std::shared_ptr<Point> p2) {
    return sqrt(p2->x*p2->x + p2->y*p2->y);
}

double mydistance(double x, double y) {
    auto p = std::make_shared<Point>(x,y); // p | Reference count: 1
    double ret = pointDistance(p); // p | Reference count: 2 (during pointDistance)
    // As soon as pointDistance ends, p's reference count : 1
    ret += p->x;
    return ret; // After returning, p's reference count reduced to 0, Point is deleted
}

std::shared_ptr<Point> lastPoint;

double pointDistance(std::shared_ptr<Point> p2){
    // Call function: p2 | reference count : 1 (pass by value)
    double dx = p2->x - lastPoint->x,
           dy = p2->y - lastPoint->y; 
    double ret = sqrt(dx*dx + dy*dy);

    /* This assignment increases p2's reference count by 1, 
    but also decreases reference count of previous object pointed to by lastPoint.
    => If prev.refCount = 0 now, then prev.lastPoint also deleted
    */
    lastPoint = p2;
    return ret; // returning reduces lastPoint's ref count by 1, but increase from lastPoint (not in function scope) remains.
}

double mydistance(double x, double y){
    auto p = std::make_shared<Point>(x,y); // p | Reference count: 1

    // Calling pointDistance: p | reference count: 2 (copy; pass by value)
    // pointDistance: increases p | reference count: 3 (copy to lastPoint)
    double ret = pointDistance(p);
    // when pointDistance returned, p | reference count: 2 because p2 out of scope, lastPoint still remains
    return ret;
    // p | reference count: 1, so not deleted (lastPoint still remains)
}