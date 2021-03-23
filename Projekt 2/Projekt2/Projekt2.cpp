// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "CarData.h"


std::string newFileName(std::string filename);


int main(int argc, char *argv[])
{
    std::string filename = newFileName(argv[1]);
    Chart s;
    std::ifstream file(argv[1]);
    file >> s;
    std::cout << s;
    drawChart(s);
    writeDeflection(filename, s);

    return 0;
}


std::string newFileName(std::string filename)
{
    int pos = 0;
    for (int i = 0; i < filename.length(); ++i)
    {
        if (filename[i] == '.')
            break;
        pos++;
    }
    filename.insert(pos, 1, 'o');
    return filename;
}
