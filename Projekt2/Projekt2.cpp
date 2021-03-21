// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "CarData.h"


void writeDeflection(std::string filename, Chart c);
void drawChart(Chart c);
int biggestInV(std::vector<int> v);

int main(int argc, char *argv[])
{
    std::string filename = argv[1];
    int pos = filename.length() - 4;
    filename.insert(pos, 1, 'o');
    
    Chart c{ { "Toyota  Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} }, 
        {"Opel  Adam", 43300, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }} };
    
    //std::cout << Abbrev(c[0]) << std::endl;
    writeDeflection(filename, c);
    //std::cout << averagePrice(c);
    
    drawChart(c);
    

    return 0;
}


void writeDeflection(std::string filename, Chart c)
{
    std::ofstream MyFile(filename);
    for (int i = 0; i < 20; ++i)
    {
        if (c[i].brandVersion == "\0")
            break;
        MyFile << Abbrev(c[i]) << " : " << c[i].price - averagePrice(c) << std::endl;
    }
    MyFile.close();
}


void drawChart(Chart c)
{
    std::vector<int> carsSold;
    for (int i = 0; i < 12; i++)
    {
        int monthlySold = 0;
        for (int j = 0; j < 20; j++)
        {
            if (c[j].brandVersion == "\0")
                break;
            monthlySold += c[j].soldMonth[i];
        }
        carsSold.push_back(monthlySold);
    }
 

    for (int i = 0; i < carsSold.size(); ++i)
        std::cout << carsSold[i] << ' ';
    std::cout << std::endl;
    int size = biggestInV(carsSold);
    std::vector<std::vector<char>> chart;
    for (int i = 0; i < size; ++i)
    {
        std::vector<char> line;
        for (int j = 0; j < 12; ++j)
        {   
            if (carsSold[j] != 0)
            {
                line.push_back('#');
                carsSold[j] -= 1;
            }
            else
                line.push_back(' ');
        }
        chart.push_back(line);
        //for (int z = 0; z < 12; ++z)
            //std::cout << arr[z] << ' ';
        //std::cout << std::endl;
    }

    for (int i = chart.size() - 1; i >= 0; --i)
    {
       for (int z = 0; z < 12; ++z)
            std::cout << chart[i][z] << ' ';
        std::cout << std::endl;
    }
    std::cout << "s l m k m c l s w p l g" << std::endl;
}


int biggestInV(std::vector<int> v)
{
    int biggest = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > biggest)
            biggest = v[i];
    }

    return biggest;
}
