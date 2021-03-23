// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "CarData.h"




int main(int argc, char *argv[])
{
    std::string filename = argv[1];
    int pos = filename.length() - 4;
    filename.insert(pos, 1, 'o');
    Chart s;
    std::ifstream file(argv[1]);
    file >> s;
    std::cout << s;
    drawChart(s);
    writeDeflection(filename, s);

    return 0;
}
