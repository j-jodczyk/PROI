#pragma once

#include <iostream>
#include <string>

struct CarData
{
	std::string brandVersion; // dwa slowa zaczynajace sie duza litera
	int price; // przedzial 1...100 0000
	int soldMonth[13]; // przedzial 1...100
};

// typedef CarData Chart[20];


int averagePrice(CarData& c);


std::istream& operator>> (std::istream& is, const CarData& c);

std::ostream& operator<< (std::ostream& os, const CarData& c);

