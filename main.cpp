#include <iostream>
#include <cmath>

using namespace std;

// Struct childs by default are public;
// If we wanted to use a class we put the funciton in the pubic block
class Point
{
private:
    double x;
    double y;

public:
    // Function for comparing the distance of two points
    double distanceTo(const Point &other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;

        return std::sqrt((dx * dx) + (dy * dy));
    };
};

// Length derivation with caching
class Line
{
private:
    Point start;
    Point end;
    bool hasChanged;
    double length;

public:
    void setStart(Point start)
    {
        this->start = start;
        this->hasChanged = true;
    }

    void setEnd(Point end)
    {
        this->end = end;
        this->hasChanged = true;

    }

    Point getStart()
    {
        return this->start;
    }

    Point getEnd()
    {
        return this->end;
    }

    double getLength() {
        if (this->hasChanged) {
            this->length = start.distanceTo(end);
            this->hasChanged = false;
        }

        return this->length;
    }
};