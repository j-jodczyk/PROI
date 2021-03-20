#pragma once

#include <iostream>
#include <string>
#include <vector>

struct CarData
{
	std::string brandVersion; // dwa slowa zaczynajace sie duza litera
	int price; // przedzial 1...100 0000
	int soldMonth[12]; // przedzial 1...100
};

typedef CarData Chart[20];


int averagePrice(CarData& c);


std::istream& operator>> (std::istream& is, const Chart& c);

std::ostream& operator<< (std::ostream& os, const Chart& c);

std::string Abbrev(CarData cd);

int averagePrice(Chart c);


