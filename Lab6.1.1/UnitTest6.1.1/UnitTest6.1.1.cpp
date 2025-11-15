#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.1.1/Lab6.1.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest611
{
	TEST_CLASS(UnitTest611)
	{
	public:
		
        TEST_METHOD(Test_Criterion)
        {
            // value непарне, index не кратний 13 → TRUE
            Assert::IsTrue(Criterion(17, 5));

            // value парне → FALSE
            Assert::IsFalse(Criterion(20, 5));

            // index кратний 13 → FALSE
            Assert::IsFalse(Criterion(15, 13));

            // value парне і index кратний 13 → FALSE
            Assert::IsFalse(Criterion(84, 26));
        }

        TEST_METHOD(Test_CountSelected)
        {
            int c[5] = { 15, 17, 12, 19, 21 };

            int result = countSelected(c, 5);
            Assert::AreEqual(3, result);
        }

        TEST_METHOD(Test_SumSelected)
        {
            int c[5] = { 18, 20, 15, 21, 19 };
            // сума = 15 + 21 + 19 = 55

            int result = sumSelected(c, 5);
            Assert::AreEqual(55, result);
        }

	};
}
