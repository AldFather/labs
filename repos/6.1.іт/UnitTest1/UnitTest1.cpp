#include "pch.h"
#include "CppUnitTest.h"
#include "../6.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int a[n] = { 2, 4, 6, 8, 10 };
			int expS = 0;
			int k = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] > 0 && a[i] % 2 != 0) {
					expS += a[i];
					k++;
				}
			}
			int s = Sum(a, n, k);
			Assert::AreEqual(s, expS);
		}
	};
}