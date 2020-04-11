#pragma once
#ifndef G2_H
#define G2_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>

class Point
{
public:
	Point();
	Point(double x, double y);
	double getX();
	double getY();
	bool operator == (const Point& p);
	bool operator != (const Point& p);

private:
	double x, y;
};
#endif