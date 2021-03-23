#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct CarData
{
	std::string brandVersion; // dwa slowa zaczynajace sie duza litera
	int price; // przedzial 1...100 0000
	int soldMonth[12]; // przedzial 1...100
};

typedef CarData Chart[20];

std::istream& operator>> (std::istream& is, Chart& c);

std::ostream& operator<< (std::ostream& os, const Chart& c);

std::string Abbrev(CarData cd);

int averagePrice(Chart c);

void writeDeflection(std::string filename, Chart c);

void drawChart(Chart c);

int biggestInV(std::vector<int> v);


