// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "CarData.h"


int main()
{
    /*std::ifstream infile;
    infile.open("Tekst.txt"); // figure out how to give this file as argument to program

    std::vector<Chart> v;

    if (infile.fail())
    {
        std::cout << "Failed to open file";
    }
    else {
        for (Chart c; infile >> c;)
        {
            v.push_back(c);
            infile.close();
        }
        for (auto const& c : v)
        {
            std::cout << c;
        }
    }
    */
    CarData c{ "Toyota	Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} };
    std::cout << c;

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
