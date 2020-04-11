#pragma once
#ifndef G2USE_H
#define G2USE_H
#include "g2.h"

std::string getPath();

void processData(std::ifstream& fi, std::ofstream& fo);

std::vector<Point> inData(std::ifstream& fi);

void outData(std::vector<Point>& data, bool result, std::ofstream& fo);

double getC(std::ifstream& fi);

bool isDeltoid(std::vector<Point>& d);

#endif // !G2USE_H