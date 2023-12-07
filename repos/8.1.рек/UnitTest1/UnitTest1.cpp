#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../8.1.рек/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(CountFunction_ShouldReturnCorrectCount)
        {
            char str[] = "aa bb crs aa bb aa";
            int count = Count(str, 1);
            Assert::AreEqual(5, count);
        }

        TEST_METHOD(ChangeFunction_ShouldModifyStringCorrectly)
        {
            char str[] = "aa db cc ff rs";
            char dest[151];
            dest[0] = '\0';
            char* modifiedStr = Change(dest, str, dest, 0);

            Assert::AreEqual("*** db *** ff rs", modifiedStr);
        }
    };
}