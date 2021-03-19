// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "CarData.h"


std::string Abbrev(CarData cd);

int averagePrice(Chart c);


int main()
{
    
    Chart c{ { "Toyota  Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} }, {"Toyota  Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} } };
    
    std::cout << Abbrev(c[0]) << std::endl;

    std::cout << averagePrice(c);

    return 0;
}


std::string Abbrev(CarData cd)
{
    std::string abbrev;
    abbrev += cd.brandVersion.substr(0, 2);
    for (int i = 0; i < cd.brandVersion.length(); ++i)
    {
        if (cd.brandVersion[i] == ' ')
        {
            abbrev += cd.brandVersion.substr(i + 2, 2);
            break;
        }
    }

    for (int i = 0; i < abbrev.length(); ++i)
    {
        abbrev[i] = toupper(abbrev[i]);
    }
    return abbrev;
}

int averagePrice(Chart c)
{
    int avarage{ 0 };
    int sum{ 0 };
    int count{ 0 };

    for (int i = 0; i < 20; ++i)
    {
        if (c[i].brandVersion != "\0")
        {
            sum += c[i].price;
            count++;
        }
    }
    avarage = sum / count;
    return avarage;
}
