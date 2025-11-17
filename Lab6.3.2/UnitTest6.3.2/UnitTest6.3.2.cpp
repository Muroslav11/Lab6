#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.3.2/Lab6.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest632
{
	TEST_CLASS(UnitTest632)
	{
	public:
		
        TEST_METHOD(TestMinIntRecursive)
        {
            int a[5] = { 4, -2, 7, 1, 0 };
            int result = Min(a, 5, 0, a[0]);
            Assert::AreEqual(-2, result);
        }

        TEST_METHOD(TestMinTemplateInt)
        {
            int a[5] = { 10, 3, -5, 7, 9 };
            int result = Min<int>(a, 5, 0, a[0]);
            Assert::AreEqual(-5, result);
        }

        TEST_METHOD(TestMinTemplateDouble)
        {
            double a[5] = { 2.5, -1.3, 9.0, 0.0, 1.1 };
            double result = Min<double>(a, 5, 0, a[0]);
            Assert::AreEqual(-1.3, result, 0.0001);
        }

        TEST_METHOD(TestMinTemplateString)
        {
            // Порівняння за алфавітом → "1" найменша
            std::string a[5] = { "5", "1", "7", "3", "9" };
            std::string result = Min<std::string>(a, 5, 0, a[0]);
            Assert::AreEqual(std::string("1"), result);
        }
	};
}
