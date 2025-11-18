#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4.1/Lab6.4.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest641
{
    TEST_CLASS(UnitTest641)
    {
    public:
        TEST_METHOD(TestMinAbs)
        {
            int a[8] = { -10, 5, -2, 7, 3, -1, 9, 4 };
            // Мінімальний за модулем = |-1| = 1
            int expected = 1;

            int result = MinAbs(a, 8);

            Assert::AreEqual(expected, result);
        }

        
        TEST_METHOD(TestSumAfterZero)
        {
            int a[10] = { 4, -3, 0, -5, 2, -1, 7, 0, 9, -4 };
            // Після першого 0: |-5| + |2| + |-1| + |7| + |0| + |9| + |-4|
            int expected = 5 + 2 + 1 + 7 + 0 + 9 + 4; // = 28

            int result = SumAfterZero(a, 10);

            Assert::AreEqual(expected, result);
        }

        
        TEST_METHOD(TestTransform)
        {
            int a[8] = { 10, 11, 12, 13, 14, 15, 16, 17 };

            // Очікуваний результат:
            // Парні індекси: 10, 12, 14, 16  → перша половина
            // Непарні індекси: 11, 13, 15, 17 → друга половина
            int expected[8] = { 10, 12, 14, 16, 11, 13, 15, 17 };

            Transform(a, 8);

            for (int i = 0; i < 8; i++)
                Assert::AreEqual(expected[i], a[i]);
        }


    };
}
