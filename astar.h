#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <list>
#include <cstdlib>
using namespace std;
const int kCost1 = 10;
const int kCost2 = 14;

struct Point
{
    int x, y;
    int F, G, H;
    Point *parent;
    Point(int _x, int _y):x(_x), y(_y), F(0), G(0), H(0), parent(nullptr){}
};

class Astar
{
public:
    void InitAstar(std::vector<std::vector<int> > &_maze);
    std::list<Point*> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
private:
    Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
    std::vector<Point*> getSurrondPoints(const Point *point, bool isIgnoreCorner) const;
    bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const;
    Point *isInList(const std::list<Point *> &list, const Point *point) const;
    Point *getLeastFPoint();

    int calcG(Point *temp_start, Point *point);
    int calcH(Point *point, Point *end);
    int calcF(Point *point);
private:
    std::vector<std::vector<int> > maze;
    std::list<Point *> openList;
    std::list<Point *> closeList;
};
#endif // ASTAR_H
