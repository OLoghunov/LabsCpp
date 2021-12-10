#include "pch.h"
#include "CppUnitTest.h"
#include "..\Labs2Sem3\List.h"
#include "..\Labs2Sem3\List.cpp"
#include "..\Labs2Sem3\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1Labs2Sem3
{
	TEST_CLASS(UnitTest1Labs2Sem3)
	{
	public:
		
		TEST_METHOD(TestBogoSort)
		{
			int Array[10];
			for (unsigned i = 0; i < 10; i++)
				Array[i] = rand() % 100 + 20;
			BogoSort(Array, 10);
			Assert::IsTrue(IsCorrect(Array, 10));

			try {
				BogoSort(Array, -2);
			}
			catch (out_of_range &ex) { Assert::IsTrue(&ex); }
		}

		TEST_METHOD(TestBinarySearch)
		{
			int Array[100];
			for (unsigned i = 0; i < 100; i++)
				Array[i] = i;
			Assert::IsTrue(BinarySearch(Array, 100, 50) == 50);

			Assert::IsTrue(BinarySearch(Array, 100, 0) == 0);

			Assert::IsTrue(BinarySearch(Array, 100, 99) == 99);

			Assert::IsTrue(BinarySearch(Array, 100, 101) == -1);

			for (unsigned i = 0; i < 100; i++)
				Array[i] = rand() % 10 + 1;
			try {
				BinarySearch(Array, -2, 1);
			}
			catch (out_of_range& ex) { Assert::IsTrue(&ex); }

			try {
				BinarySearch(Array, 100, 1);
			}
			catch (int ex) { Assert::IsTrue(ex); }


			int ArrayB[10000];
			for (unsigned i = 0; i < 10000; i++)
				ArrayB[i] = i;

			Assert::IsTrue(BinarySearch(ArrayB, 10000, 50) == 50);

			Assert::IsTrue(BinarySearch(ArrayB, 10000, 0) == 0);

			Assert::IsTrue(BinarySearch(ArrayB, 10000, 99) == 99);

			Assert::IsTrue(BinarySearch(ArrayB, 10000, 101) == 101);

			Assert::IsTrue(BinarySearch(ArrayB, 10000, 100000) == -1);
		}

		TEST_METHOD(TestQuickSort)
		{
			int Array[100];
			for (unsigned i = 0; i < 100; i++)
				Array[i] = rand() % 100 + 20;
			QuickSort(Array, 100);
			Assert::IsTrue(IsCorrect(Array, 100));

			try {
				QuickSort(Array, -2);
			}
			catch (out_of_range& ex) { Assert::IsTrue(&ex); }

			int ArrayB[1000];
			for (unsigned i = 0; i < 1000; i++)
				ArrayB[i] = rand() % 100 + 20;
			QuickSort(ArrayB, 1000);
			Assert::IsTrue(IsCorrect(ArrayB, 1000));

			int ArrayC[10000];
			for (unsigned i = 0; i < 10000; i++)
				ArrayC[i] = rand() % 100 + 20;
			QuickSort(ArrayC, 10000);
			Assert::IsTrue(IsCorrect(ArrayC, 10000));

			int ArrayD[100000];
			for (unsigned i = 0; i < 100000; i++)
				ArrayD[i] = rand() % 100 + 20;
			QuickSort(ArrayD, 100000);
			Assert::IsTrue(IsCorrect(ArrayD, 100000));
		}

		TEST_METHOD(TestInsertionSort)
		{
			int Array[100];
			for (unsigned i = 0; i < 100; i++)
				Array[i] = rand() % 100 + 20;
			InsertionSort(Array, 100);
			Assert::IsTrue(IsCorrect(Array, 100));

			try {
				InsertionSort(Array, -2);
			}
			catch (out_of_range& ex) { Assert::IsTrue(&ex); }

			int ArrayB[1000];
			for (unsigned i = 0; i < 1000; i++)
				ArrayB[i] = rand() % 100 + 20;
			InsertionSort(ArrayB, 1000);
			Assert::IsTrue(IsCorrect(ArrayB, 1000));

			int ArrayC[10000];
			for (unsigned i = 0; i < 10000; i++)
				ArrayC[i] = rand() % 100 + 20;
			InsertionSort(ArrayC, 10000);
			Assert::IsTrue(IsCorrect(ArrayC, 10000));

			int ArrayD[100000];
			for (unsigned i = 0; i < 100000; i++)
				ArrayD[i] = rand() % 100 + 20;
			InsertionSort(ArrayD, 100000);
			Assert::IsTrue(IsCorrect(ArrayD, 100000));
		}

		TEST_METHOD(TestCountingSort)
		{
			char Array[100];
			for (unsigned i = 0; i < 100; i++)
				Array[i] = rand() % 100 + 20;
			CountingSort(Array, 100);
			Assert::IsTrue(IsCorrect(Array, 100));

			try {
				CountingSort(Array, -2);
			}
			catch (out_of_range& ex) { Assert::IsTrue(&ex); }

			char ArrayB[1000];
			for (unsigned i = 0; i < 1000; i++)
				ArrayB[i] = rand() % 100 + 20;
			CountingSort(ArrayB, 1000);
			Assert::IsTrue(IsCorrect(ArrayB, 1000));

			char ArrayC[10000];
			for (unsigned i = 0; i < 10000; i++)
				ArrayC[i] = rand() % 100 + 20;
			CountingSort(ArrayC, 10000);
			Assert::IsTrue(IsCorrect(ArrayC, 10000));

			char ArrayD[100000];
			for (unsigned i = 0; i < 100000; i++)
				ArrayD[i] = rand() % 100 + 20;
			CountingSort(ArrayD, 100000);
			Assert::IsTrue(IsCorrect(ArrayD, 100000));
		}
	};
}
