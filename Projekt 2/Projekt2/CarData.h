#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct CarData
{
	std::string brandVersion;
	int price;			
	int soldMonth[12];
	CarData();
	CarData(std::string& bv, int& p, int sm[12]);
};

typedef CarData Chart[20];

std::istream& operator>> (std::istream& is, Chart& c);

std::ostream& operator<< (std::ostream& os, const Chart& c);

std::string Abbrev(CarData cd);

int averagePrice(Chart c);

int deflection(Chart c, int index);

void writeDeflection(std::string filename, Chart c);

void drawChart(Chart c);

int biggestInV(std::vector<int> v);


