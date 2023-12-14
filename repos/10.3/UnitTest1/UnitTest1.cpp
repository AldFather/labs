#include "pch.h"
#include "CppUnitTest.h"
#include "../10.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string testFileName = "test_addMarshrut.txt";
			Marshrut testMarshrut = { "TestStart", "TestFinish", 10.5 };

			addMarshrut(testFileName, testMarshrut);

			ifstream file(testFileName);
			string line;
			bool found = false;
			while (getline(file, line)) {
				if (line.find("TestStart") != string::npos) {
					found = true;
					break;
				}
			}
			Assert::IsTrue(found);
			file.close();
		}
	};
}
