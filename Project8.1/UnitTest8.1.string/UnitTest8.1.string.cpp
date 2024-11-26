#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../Project8.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81string
{
	TEST_CLASS(UnitTest81string)
	{
	public:

		TEST_METHOD(CheckPairTests)
		{
			Assert::IsTrue(CheckPair("no way"), L"Failed: 'no' should return true.");

			Assert::IsTrue(CheckPair("on the way"), L"Failed: 'on' should return true.");

			Assert::IsTrue(CheckPair("nonon"), L"Failed: 'no' and 'on' in one string should return true.");

			Assert::IsFalse(CheckPair("hello world"), L"Failed: No 'no' or 'on' should return false.");

			Assert::IsFalse(CheckPair(""), L"Failed: Empty string should return false.");

			Assert::IsFalse(CheckPair("n o"), L"Failed: Letters 'n' and 'o' not adjacent should return false.");
		}

		TEST_METHOD(ChangeTests)
		{
			std::string test1 = "no way";
			Assert::AreEqual(std::string("*** way"), Change(test1), L"Failed: 'no' was not replaced correctly.");

			std::string test2 = "on the way";
			Assert::AreEqual(std::string("*** the way"), Change(test2), L"Failed: 'on' was not replaced correctly.");

			std::string test3 = "nonono";
			Assert::AreEqual(std::string("*********"), Change(test3), L"Failed: Multiple 'no' were not replaced correctly.");

			std::string test4 = "nonono on";
			Assert::AreEqual(std::string("********* ***"), Change(test4), L"Failed: 'no' and 'on' were not replaced correctly.");

			std::string test5 = "hello world";
			Assert::AreEqual(std::string("hello world"), Change(test5), L"Failed: String without 'no' or 'on' should remain unchanged.");

			std::string test6 = "";
			Assert::AreEqual(std::string(""), Change(test6), L"Failed: Empty string should remain unchanged.");
		}
	};
}
