#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.2.2/Lab6.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest622
{
	TEST_CLASS(UnitTest622)
	{
	public:
		
        TEST_METHOD(Test_SumEvenIndex)
        {
            const int n = 10;
            int a[n] = { 10, -3, 4, 7, 6, 8, -2, 5, 12, 9 };

            // 10 + 4 + 6 + (-2) + 12 = 30
            int expected = 30;
            int result = SumEvenIndex(a, n, 0);

            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(Test_CountEvenIndex)
        {
            const int n = 10;
            int a[n] = { 10, -3, 4, 7, 6, 8, -2, 5, 12, 9 };

            // індекси 0,2,4,6,8 → 5 елементів
            int expected = 5;
            int result = CountEvenIndex(a, n, 0);

            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(Test_AverageEvenIndex)
        {
            const int n = 10;
            int a[n] = { 10, -3, 4, 7, 6, 8, -2, 5, 12, 9 };

            //  average = 6.0
            double expected = 6.0;
            double result = AverageEvenIndex(a, n);

            Assert::AreEqual(expected, result, 0.0001);
        }
	};
}
