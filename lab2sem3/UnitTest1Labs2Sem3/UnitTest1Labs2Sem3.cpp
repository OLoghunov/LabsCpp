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
			int A[10];
			for (unsigned i = 0; i < 10; i++)
				A[i] = rand() % 100 + 20;
			BogoSort(A, 10);
			Assert::IsTrue(IsCorrect(A, 10));
		}

		TEST_METHOD(TestBinarySearch)
		{
			int A[100];
			for (unsigned i = 0; i < 100; i++)
				A[i] = i;
			Assert::IsTrue(BinarySearch(A, 100, 50) == 50);

			Assert::IsTrue(BinarySearch(A, 100, 0) == 0);

			Assert::IsTrue(BinarySearch(A, 100, 99) == 99);

			Assert::IsTrue(BinarySearch(A, 100, 101) == -1);

			int B[10000];
			for (unsigned i = 0; i < 10000; i++)
				A[i] = i;

			Assert::IsTrue(BinarySearch(A, 10000, 50) == 50);

			Assert::IsTrue(BinarySearch(A, 10000, 0) == 0);

			Assert::IsTrue(BinarySearch(A, 10000, 99) == 99);

			Assert::IsTrue(BinarySearch(A, 10000, 10000) == 10000);

			Assert::IsTrue(BinarySearch(A, 10000, 101) == 101);

			Assert::IsTrue(BinarySearch(A, 10000, 100000) == -1);
		}

		TEST_METHOD(TestQuickSort)
		{
			int A[100];
			for (unsigned i = 0; i < 100; i++)
				A[i] = rand() % 100 + 20;
			QuickSort(A, 100);
			Assert::IsTrue(IsCorrect(A, 100));

			int B[1000];
			for (unsigned i = 0; i < 1000; i++)
				B[i] = rand() % 100 + 20;
			QuickSort(B, 1000);
			Assert::IsTrue(IsCorrect(B, 1000));

			int C[10000];
			for (unsigned i = 0; i < 10000; i++)
				C[i] = rand() % 100 + 20;
			QuickSort(C, 10000);
			Assert::IsTrue(IsCorrect(C, 10000));

			int D[100000];
			for (unsigned i = 0; i < 100000; i++)
				D[i] = rand() % 100 + 20;
			QuickSort(D, 100000);
			Assert::IsTrue(IsCorrect(D, 100000));
		}

		TEST_METHOD(TestInsertionSort)
		{
			int A[100];
			for (unsigned i = 0; i < 100; i++)
				A[i] = rand() % 100 + 20;
			InsertionSort(A, 100);
			Assert::IsTrue(IsCorrect(A, 100));

			int B[1000];
			for (unsigned i = 0; i < 1000; i++)
				B[i] = rand() % 100 + 20;
			InsertionSort(B, 1000);
			Assert::IsTrue(IsCorrect(B, 1000));

			int C[10000];
			for (unsigned i = 0; i < 10000; i++)
				C[i] = rand() % 100 + 20;
			InsertionSort(C, 10000);
			Assert::IsTrue(IsCorrect(C, 10000));

			int D[100000];
			for (unsigned i = 0; i < 100000; i++)
				D[i] = rand() % 100 + 20;
			InsertionSort(D, 100000);
			Assert::IsTrue(IsCorrect(D, 100000));
		}

		TEST_METHOD(TestCountingSort)
		{
			char A[100];
			for (unsigned i = 0; i < 100; i++)
				A[i] = rand() % 100 + 20;
			CountingSort(A, 100);
			Assert::IsTrue(IsCorrect(A, 100));

			char B[1000];
			for (unsigned i = 0; i < 1000; i++)
				B[i] = rand() % 100 + 20;
			CountingSort(B, 1000);
			Assert::IsTrue(IsCorrect(B, 1000));

			char C[10000];
			for (unsigned i = 0; i < 10000; i++)
				C[i] = rand() % 100 + 20;
			CountingSort(C, 10000);
			Assert::IsTrue(IsCorrect(C, 10000));

			char D[100000];
			for (unsigned i = 0; i < 100000; i++)
				D[i] = rand() % 100 + 20;
			CountingSort(D, 100000);
			Assert::IsTrue(IsCorrect(D, 100000));
		}
	};
}
