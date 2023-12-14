#include "pch.h"
#include "CppUnitTest.h"
#include "../9.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Marshrut testArray[4];
			testArray[0] = { "Start1", "FinishC", 3 };
			testArray[1] = { "Start2", "FinishA", 1 };
			testArray[2] = { "Start3", "FinishD", 6 };
			testArray[3] = { "Start4", "FinishB", 2 };

			SortByMarshrutNomer(testArray, 4);

			Assert::AreEqual(1, testArray[0].nomer);
			Assert::AreEqual(2, testArray[1].nomer);
			Assert::AreEqual(3, testArray[2].nomer);
			Assert::AreEqual(6, testArray[3].nomer);
		}
	};
}
