#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int imin;
			int j;
			imin = 10;
			j = 12;
			if (imin < j)
				imin = imin;
			else
				imin = j;
			Assert::AreEqual(imin, 10);
		}
	};
}
