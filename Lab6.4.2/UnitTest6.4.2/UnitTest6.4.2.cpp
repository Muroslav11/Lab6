#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4.2/Lab6.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest642
{
	TEST_CLASS(UnitTest642)
	{
	public:
		
        TEST_METHOD(TestMinAbs)
        {
            int a[] = { -5, 10, -1, 7, 20 };
            int size = 5;

            int result = MinAbs(a, size, 0, a[0]);
            int expected = -1;  // мінімальний за модулем = -1

            Assert::AreEqual(expected, result);
        }

       
        TEST_METHOD(TestSumAfterZero)
        {
            int a[] = { 3, -2, 0, 5, -4, 1 };
            int size = 6;

            // |5|+|−4|+|1| = 5 + 4 + 1 = 10
            int expected = 10;
            int result = SumAfterZero(a, size, 0, false);

            Assert::AreEqual(expected, result);
        }

  
        TEST_METHOD(TestCountEvenIndexes)
        {
            int size = 7;
            // індекси 0,2,4,6 → 4 елементи

            int expected = 4;
            int result = CountEvenIndexes(size, 0);

            Assert::AreEqual(expected, result);
        }

       
        TEST_METHOD(TestTransform)
        {
            int a[] = { 10, 20, 30, 40, 50, 60 };
            int size = 6;

            // Парні індекси → 10, 30, 50
            // Непарні → 20, 40, 60
            // Новий масив = {10, 30, 50, 20, 40, 60}

            int expected[] = { 10, 30, 50, 20, 40, 60 };

            Transform(a, size);

            for (int i = 0; i < size; i++)
                Assert::AreEqual(expected[i], a[i]);
        }
	};
}
