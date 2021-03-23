#include "CppUnitTest.h"
#include "../Projekt2/CarData.h"
#include "../Projekt2/CarData.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testCarData
{
	TEST_CLASS(testCarData)
	{
	public:

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
			Chart c{ { "Toyota	Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} } };
			out << c;
			std::string c_str = "Toyota	Aygo	34900	4	5	6	7	8	9	12	2	3	6	8	9\n";
			Assert::AreEqual(out.str(), c_str);
		}

		TEST_METHOD(test_Abbrev)
		{
			CarData cd = { "Toyota	Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} };
			std::string abbrev = "TOAY";
			Assert::AreEqual(abbrev, Abbrev(cd));
		}


		TEST_METHOD(test_deflection)
		{
			Chart c{ { "Toyota  Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} },
					 {"Opel	Adam", 43300, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 } },
					 {"Fiat	500", 41900, {1, 2, 3, 4, 5, 6, 3, 2, 4, 23, 2, 23}} };
			Assert::AreEqual(-5133, deflection(c, 0));
		}

		TEST_METHOD(test_averagePrice)
		{
			Chart c{ { "Toyota  Aygo", 34900, {4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9} },
					 {"Opel	Adam", 43300, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 } },
					 {"Fiat	500", 41900, {1, 2, 3, 4, 5, 6, 3, 2, 4, 23, 2, 23}} };
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
