#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.3.1/Lab6.3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest631
{
	TEST_CLASS(UnitTest631)
	{
	public:
		
		TEST_METHOD(Test_Min_Int_Normal)
		{
			int a[5] = { 4, -2, 7, 1, 0 };

			Assert::AreEqual(-2, Min(a, 5));          // звичайна
			Assert::AreEqual(-2, Min<int>(a, 5));     // шаблон
		}

		TEST_METHOD(Test_Min_Double)
		{
			double a[6] = { 2.5, -1.1, 9.3, 0.0, -3.4, 5.5 };

			double result = Min<double>(a, 6);

			Assert::AreEqual(-3.4, result, 0.0001);
		}

		TEST_METHOD(Test_Min_String)
		{
			string s[5] = { "5", "2", "9", "1", "7" };

			string result = Min<string>(s, 5);

			Assert::AreEqual(string("1"), result);
		}
	};
}
