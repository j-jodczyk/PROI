#include "CarData.h"


std::istream& operator>> (std::istream& is, Chart& c)
{
    std::string data;
    
    
    for (int i = 0; i < 20; i++)
    {
        std::vector<std::string> dataVector;
        std::getline(is, data);
        if (data == "\0")
            break;
        size_t start = 0;
        size_t end = 0;

        while ((start = data.find_first_not_of('\t', end)) != std::string::npos)
        {
            end = data.find('\t', start);
            dataVector.push_back(data.substr(start, end - start));
        }

        if (dataVector.size() != 15)
            throw "Invalid input";

        CarData cd;
        cd.brandVersion = dataVector[0] + "\t" + dataVector[1];
        cd.price = std::stoi(dataVector[2]);
        for (int i = 3; i < 15; ++i)
        {
            try 
            {
                cd.soldMonth[i - 3] = std::stoi(dataVector[i]);
            }
            catch (...)
            {
                throw "Invalid input";
            }
        }
        c[i] = cd;
    }
        
	return is;
}

std::ostream& operator<< (std::ostream& os, const Chart& c)
{
	for (CarData cd : c)
	{
        if (cd.brandVersion == "\0")
            break;
		os << cd.brandVersion << "\t" << cd.price;
		for (int i = 0; i < 12; ++i)
		{
			os << "\t" << cd.soldMonth[i];
		}
        os << std::endl;
	}
	return os;
}


std::string Abbrev(CarData cd)
{
    std::string abbrev;
    abbrev += cd.brandVersion.substr(0, 2);
    for (int i = 0; i < cd.brandVersion.length(); ++i)
    {
        if (cd.brandVersion[i] == '\t')
        {
            abbrev += cd.brandVersion.substr(i + 1, 2);
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


