#include "g2.h"

Point::Point() : x(0), y(0) {}
Point::Point(double a, double b) : x(a), y(b) {}

double Point::getX() { return x; }
double Point::getY() { return y; }

bool Point::operator == (const Point& p)
{
	return ((x == p.x) && (y == p.y));
}
bool Point::operator != (const Point& p)
{
	return !((x == p.x) && (y == p.y));
}