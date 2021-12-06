#include "pch.h"
#include "CppUnitTest.h"
#include "..\Labster1\List.h"
#include "..\Labster1\List.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLabster1
{
	TEST_CLASS(UnitTestLabster1)
	{
	public:
		TEST_METHOD(TestMethodConstructor)
		{
			List S;
			Assert::IsTrue(!S.GetSize());
		}

		TEST_METHOD(TestMethodPushBack)
		{
			List S;
			S.PushBack(5);
			Assert::IsTrue((S.GetSize() == 1) && (S.At(S.GetSize() - 1) == 5));

			S.PushBack(2);
			Assert::IsTrue((S.GetSize() == 2) && (S.At(S.GetSize() - 2) == 5) && (S.At(S.GetSize() - 1) == 2));
		}

		TEST_METHOD(TestMethodPushFront)
		{
			List S;
			S.PushFront(5);
			Assert::IsTrue((S.GetSize() == 1) && (S.At(S.GetSize() - 1) == 5));

			S.PushFront(2);
			Assert::IsTrue((S.GetSize() == 2) && (S.At(S.GetSize() - 2) == 2) && (S.At(S.GetSize() - 1) == 5));
		}

		TEST_METHOD(TestMethodPopBack)
		{
			List S;
			S.PopBack();
			Assert::IsTrue(!S.GetSize());

			for (unsigned i = 1; i < 4; i++)
				S.PushBack(i);
			S.PopBack();
			Assert::IsTrue((S.GetSize() == 2) && (S.At(S.GetSize() - 1) == 2));
		}

		TEST_METHOD(TestMethodPopFront)
		{
			List S;
			S.PopFront();
			Assert::IsTrue(!S.GetSize());

			for (unsigned i = 1; i < 4; i++)
				S.PushBack(i);
			S.PopFront();
			Assert::IsTrue((S.GetSize() == 2) && (S.At(S.GetSize() - 2) == 2));
		}

		TEST_METHOD(TestMethodInsert)
		{
			List S;
			for (unsigned i = 1; i < 4; i++)
				S.PushBack(i);
			S.Insert(2, 1);
			Assert::IsTrue((S.GetSize() == 4) && (S.At(S.GetSize() - 3) == 2));
		}

		TEST_METHOD(TestMethodAt)
		{
			List S;
			for (unsigned i = 1; i < 4; i++)
				S.PushBack(i);
			Assert::IsTrue(S.At(0) == 1);
			Assert::IsTrue(S.At(1) == 2);
			Assert::IsTrue(S.At(2) == 3);
		}

		TEST_METHOD(TestMethodRemove)
		{
			List S;
			for (unsigned i = 1; i < 4; i++)
				S.PushBack(i);
			S.Remove(0);
			Assert::IsTrue((S.GetSize() == 2) && (S.At(S.GetSize() - 2) == 2));
		}

		TEST_METHOD(TestMethodGetSize)
		{
			List S;
			Assert::IsTrue(!S.GetSize());
			S.PushFront(1);
			Assert::IsTrue(S.GetSize() == 1);
		}

		TEST_METHOD(TestMethodClear)
		{
			List S;
			S.Clear();
			for (unsigned i = 1; i < 4; i++)
				S.PushBack(i);
			S.Clear();
			Assert::IsTrue(!S.GetSize());
		}

		TEST_METHOD(TestMethodSet)
		{
			List S;
			for (unsigned i = 1; i < 4; i++)
				S.PushBack(i);
			S.Set(3, 0);
			Assert::IsTrue(S.At(0) == 3);

			S.Set(3, 2);
			Assert::IsTrue(S.At(2) == 3);
		}

		TEST_METHOD(TestMethodIsEmpty)
		{
			List S;
			Assert::IsTrue(S.IsEmpty());
			
			S.PushBack(1);
			Assert::IsTrue(!S.IsEmpty());
		}

		TEST_METHOD(TestMethodFindFirst)
		{
			List S;
			for (unsigned i = 1; i < 6; i++)
				S.PushBack(i);
			List N;
			for (unsigned i = 1; i < 4; i++)
				N.PushBack(i);
			Assert::IsTrue(S.FindFirst(N) == 0);
			S.Clear();
			N.Clear();

			for (unsigned i = 1; i < 6; i++)
				S.PushBack(i);
			for (unsigned i = 2; i < 3; i++)
				N.PushBack(i);
			Assert::IsTrue(S.FindFirst(N) == 1);
			S.Clear();
			N.Clear();

			for (unsigned i = 1; i < 6; i++)
				S.PushBack(i);
			for (unsigned i = 0; i < 3; i++)
				N.PushBack(i);
			Assert::IsTrue(S.FindFirst(N) == -1);
			S.Clear();
			N.Clear();

			Assert::IsTrue(S.FindFirst(N) == -1);
		}
	};
}
