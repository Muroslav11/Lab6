#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.1.2/Lab6.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest612
{
	TEST_CLASS(UnitTest612)
	{
	public:
		
		
		TEST_METHOD(Test_Criterion)
		{
			Assert::IsTrue(Criterion(17, 1));   // непарне, індекс не кратний 13
			Assert::IsFalse(Criterion(20, 1));  // парне
			Assert::IsFalse(Criterion(17, 13)); // індекс кратний 13
		}

		TEST_METHOD(Test_CountSelected)
		{
			int c[6] = { 17, 20, 33, 14, 19, 55 };
			// Індекси:    0   1   2   3   4   5
			// Підходять:  33(2), 19(4), 55(5) → 3 елементи

			int result = CountSelected(c, 6, 0);

			Assert::AreEqual(3, result);
		}

		TEST_METHOD(Test_SumSelected)
		{
			int c[6] = { 17, 20, 33, 14, 19, 55 };
			// Сума тих самих: 33 + 19 + 55 = 107

			int result = SumSelected(c, 6, 0);

			Assert::AreEqual(107, result);
		}

	};
}
