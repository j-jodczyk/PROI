#include "CarData.h"

int averagePrice(CarData& c) 
{
	
	return 0;
}


std::istream& operator>> (std::istream& is, const CarData& c)
{
	char ch;
	std::string brand;
	std::string	version;
	while (is.get(ch) && ch != ' ')
		brand += ch;
	


	return is;
}

std::ostream& operator<< (std::ostream& os, const Chart& c)
{
	for (CarData cd : c)
	{
		os << cd.brandVersion << "  " << cd.price;
		for (int i = 0; i < 12; i++)
		{
			os << "  " << cd.soldMonth[i];
		}
	}
	return os;
}

