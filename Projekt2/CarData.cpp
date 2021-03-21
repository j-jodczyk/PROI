#include "CarData.h"

int averagePrice(CarData& c) 
{
	
	return 0;
}


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

        CarData cd;
        cd.brandVersion = dataVector[0] + "  " + dataVector[1];
        cd.price = std::stoi(dataVector[2]);
        std::vector<int> soldMonthV;
        for (int i = 3; i < 15; ++i)
        {
            soldMonthV.push_back(std::stoi(dataVector[i]));
        }
        std::copy(soldMonthV.begin(), soldMonthV.end(), cd.soldMonth);
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
		for (int i = 0; i < 12; i++)
		{
			os << "  " << cd.soldMonth[i];
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
