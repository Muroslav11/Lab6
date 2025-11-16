#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.2.1/Lab6.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest621
{
	TEST_CLASS(UnitTest621)
	{
	public:
			TEST_METHOD(AvgEvenIndex)
			{
				const int n = 10;
				int a[n] = { 10, -3, 4, 7, 6, 8, -2, 5, 12, 9 };
				
				// (10 + 4 + 6 - 2 + 12) / 5 = 6.0
				double expected = 6.0;
				double result = AverageEvenIndex(a, n);
				
				Assert::AreEqual(expected, result, 0.0001);
			}
	};
}
