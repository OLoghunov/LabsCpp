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
			List listS;
			Assert::IsTrue(!listS.GetSize());
		}

		TEST_METHOD(TestMethodPushBack)
		{
			List listS;
			listS.PushBack(5);
			Assert::IsTrue((listS.GetSize() == 1) && (listS.At(listS.GetSize() - 1) == 5));

			listS.PushBack(2);
			Assert::IsTrue((listS.GetSize() == 2) && (listS.At(listS.GetSize() - 2) == 5) && (listS.At(listS.GetSize() - 1) == 2));
		}

		TEST_METHOD(TestMethodPushFront)
		{
			List listS;
			listS.PushFront(5);
			Assert::IsTrue((listS.GetSize() == 1) && (listS.At(listS.GetSize() - 1) == 5));

			listS.PushFront(2);
			Assert::IsTrue((listS.GetSize() == 2) && (listS.At(listS.GetSize() - 2) == 2) && (listS.At(listS.GetSize() - 1) == 5));
		}

		TEST_METHOD(TestMethodPopBack)
		{
			List listS;
			listS.PopBack();
			Assert::IsTrue(!listS.GetSize());

			for (unsigned i = 1; i < 4; i++)
				listS.PushBack(i);
			listS.PopBack();
			Assert::IsTrue((listS.GetSize() == 2) && (listS.At(listS.GetSize() - 1) == 2));
		}

		TEST_METHOD(TestMethodPopFront)
		{
			List listS;
			listS.PopFront();
			Assert::IsTrue(!listS.GetSize());

			for (unsigned i = 1; i < 4; i++)
				listS.PushBack(i);
			listS.PopFront();
			Assert::IsTrue((listS.GetSize() == 2) && (listS.At(listS.GetSize() - 2) == 2));
		}

		TEST_METHOD(TestMethodInsert)
		{
			List listS;
			for (unsigned i = 1; i < 4; i++)
				listS.PushBack(i);
			listS.Insert(2, 1);
			Assert::IsTrue((listS.GetSize() == 4) && (listS.At(listS.GetSize() - 3) == 2));
			
			try { listS.Insert(34, 10); }
			catch (out_of_range& ex) { Assert::IsTrue(&ex); }
		}

		TEST_METHOD(TestMethodAt)
		{
			List listS;
			for (unsigned i = 1; i < 4; i++)
				listS.PushBack(i);
			Assert::IsTrue(listS.At(0) == 1);
			Assert::IsTrue(listS.At(1) == 2);
			Assert::IsTrue(listS.At(2) == 3);
			
			try { listS.At(34); }
			catch (out_of_range& ex) { Assert::IsTrue(&ex); }
		}

		TEST_METHOD(TestMethodRemove)
		{
			List listS;
			for (unsigned i = 1; i < 4; i++)
				listS.PushBack(i);
			listS.Remove(0);
			Assert::IsTrue((listS.GetSize() == 2) && (listS.At(listS.GetSize() - 2) == 2));

			try { listS.Remove(34); }
			catch (out_of_range &ex) { Assert::IsTrue(&ex); }
		}

		

		TEST_METHOD(TestMethodGetSize)
		{
			List listS;
			Assert::IsTrue(!listS.GetSize());
			listS.PushFront(1);
			Assert::IsTrue(listS.GetSize() == 1);
		}

		TEST_METHOD(TestMethodClear)
		{
			List listS;
			listS.Clear();
			for (unsigned i = 1; i < 4; i++)
				listS.PushBack(i);
			listS.Clear();
			Assert::IsTrue(!listS.GetSize());
		}

		TEST_METHOD(TestMethodSet)
		{
			List listS;
			for (unsigned i = 1; i < 4; i++)
				listS.PushBack(i);
			listS.Set(3, 0);
			Assert::IsTrue(listS.At(0) == 3);

			listS.Set(3, 2);
			Assert::IsTrue(listS.At(2) == 3);
			
			try { listS.Set(34, 10); }
			catch (out_of_range& ex) { Assert::IsTrue(&ex); }
		}

		TEST_METHOD(TestMethodIsEmpty)
		{
			List listS;
			Assert::IsTrue(listS.IsEmpty());
			
			listS.PushBack(1);
			Assert::IsTrue(!listS.IsEmpty());
		}

		TEST_METHOD(TestMethodFindFirst)
		{
			List listS;
			for (unsigned i = 1; i < 6; i++)
				listS.PushBack(i);
			List listN;
			for (unsigned i = 1; i < 4; i++)
				listN.PushBack(i);
			Assert::IsTrue(listS.FindFirst(listN) == 0);
			listS.Clear();
			listN.Clear();

			for (unsigned i = 1; i < 6; i++)
				listS.PushBack(i);
			for (unsigned i = 2; i < 3; i++)
				listN.PushBack(i);
			Assert::IsTrue(listS.FindFirst(listN) == 1);
			listS.Clear();
			listN.Clear();

			for (unsigned i = 1; i < 6; i++)
				listS.PushBack(i);
			for (unsigned i = 0; i < 3; i++)
				listN.PushBack(i);
			Assert::IsTrue(listS.FindFirst(listN) == -1);
			listS.Clear();
			listN.Clear();

			Assert::IsTrue(listS.FindFirst(listN) == -1);
		}
	};
}
