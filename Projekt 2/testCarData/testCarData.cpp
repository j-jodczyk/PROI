#include "CppUnitTest.h"
#include "../Projekt2/CarData.h"
#include "../Projekt2/CarData.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testCarData
{
	TEST_CLASS(testCarData)
	{
	public:

		TEST_METHOD(test_no_data_constructor)
		{
			CarData c;
			std::string n = "";
			Assert::AreEqual(n, c.brandVersion);
			Assert::AreEqual(0, c.price);
			Assert::AreEqual(0, c.soldMonth[0]);
		}


		TEST_METHOD(test_bad_data_constructor)
		{
			std::string name { "Toyota	Aygo"};
			int t1[12] = { 400, 5, 6, 7, -8, 9, 12, 2, 3, 6, 8, 9 };
			int p = 150000;
			CarData cd(name, p, t1);
			Assert::AreEqual(100000, cd.price);
			Assert::AreEqual(100, cd.soldMonth[0]);
			Assert::AreEqual(0, cd.soldMonth[4]);
		}

		TEST_METHOD(test_input)
		{
			Chart c;
			std::string c_str = "Toyota	Aygo	34900	4	5	6	7	8	9	12	2	3	6	8	9\n";
			std::istringstream in(c_str);
			in >> c;
			Assert::AreEqual(c->price, 34900);
			std::string brandV = "Toyota	Aygo";
			Assert::AreEqual(c->brandVersion, brandV);
		}

		TEST_METHOD(test_output)
		{
			std::ostringstream out;
			CarData cd;
			cd.brandVersion = "Toyota	Aygo";
			cd.price = 34900;
			int table[12] = { 4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9 };
			for (int i = 0; i < 12; ++i) 
				cd.soldMonth[i] = table[i];
			Chart c = {cd};
			out << c;
			std::string c_str = "Toyota	Aygo	34900	4	5	6	7	8	9	12	2	3	6	8	9\n";
			Assert::AreEqual(out.str(), c_str);
		}

		TEST_METHOD(test_Abbrev)
		{
			CarData cd;
			cd.brandVersion = "Toyota	Aygo";
			cd.price = 34900;
			int table[12] = { 4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9 };
			for (int i = 0; i < 12; ++i)
				cd.soldMonth[i] = table[i];
			std::string abbrev = "TOAY";
			Assert::AreEqual(abbrev, Abbrev(cd));
		}


		TEST_METHOD(test_deflection)
		{
			std::string name[3] = { "Toyota	Aygo", "Opel	Adam", "Fiat	500"};
			int t1[12] = { 4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9 };
			int t2[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
			int t3[12] = { 1, 2, 3, 4, 5, 6, 3, 2, 4, 23, 2, 23 };
 			int price[3] = { 34900, 43300, 41900 };
			Chart c{ CarData(name[0], price[0], t1), 
					 CarData(name[1], price[1], t2), 
					 CarData(name[2], price[2], t3)};
			Assert::AreEqual(-5133, deflection(c, 0));
		}

		TEST_METHOD(test_averagePrice)
		{
			std::string name[3] = { "Toyota Aygo", "Opel Adam", "Fiat 500" };
			int t1[12] = { 4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9 };
			int t2[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
			int t3[12] = { 1, 2, 3, 4, 5, 6, 3, 2, 4, 23, 2, 23 };
			int price[3] = { 34900, 43300, 41900 };
			Chart c{ CarData(name[0], price[0], t1),
					 CarData(name[1], price[1], t2),
					 CarData(name[2], price[2], t3) };
			int average = 40033;
			Assert::AreEqual(average, averagePrice(c));
		}

		TEST_METHOD(test_biggestInV)
		{
			std::vector<int> v = { 2, 43, 29, 379, 432, 34, 56 };
			Assert::AreEqual(432, biggestInV(v));
		}
	};
}
