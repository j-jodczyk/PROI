#include "CarData.h"

int averagePrice(CarData& c) 
{
	
	return 0;
}


std::istream& operator>> (std::istream& is, const CarData& c)
{
	/*Chart new_c;
	*if (is >> std::ws && std::getline(is, new_c->brandVersion) && is >> new_c->price >> new_c->soldMonth)
	*{
	*	c = new_c;
	*}*/
	return is;
}

std::ostream& operator<< (std::ostream& os, const CarData& c)
{
	os << c.brandVersion << "	" << c.price;
	for (int i = 0; i < 12; i++)
	{
		os << "	" << c.soldMonth[i];
	}
	return os;
}

