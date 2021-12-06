#include "pch.h"
#include "CppUnitTest.h"
#include "..\Labs3Sem3\BinarySearchTree.h"
#include "..\Labs3Sem3\BinarySearchTree.cpp"
#include "..\Labs3Sem3\intNode.h"
#include "..\Labs3Sem3\Node.h"
#include "..\Labs3Sem3\Queue.h"
#include "..\Labs3Sem3\Queue.cpp"
#include "..\Labs3Sem3\Stack.h"
#include "..\Labs3Sem3\Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3
{
	TEST_CLASS(UnitTestLab3)
	{
	public:

		TEST_METHOD(TestMethodContains)
		{
			BST T;
			for (unsigned i = 20; i > 0; i -= 2)
				T.Insert(i);
			for (unsigned i = 19; i > 1; i -= 2)
				T.Insert(i);

			for (unsigned i = 20; i > 1; i--)
				Assert::IsTrue(T.Contains(i));

			for (unsigned i = 30; i > 20; i--)
				Assert::IsTrue(!T.Contains(i));
		}

		TEST_METHOD(TestMethodInsert)
		{
			BST T;
			T.Insert(7);
			T.Insert(3);
			T.Insert(10);
			T.Insert(2);
			T.Insert(5);

			Assert::IsTrue(T.Contains(7));
			Assert::IsTrue(T.Contains(3));
			Assert::IsTrue(T.Contains(10));
			Assert::IsTrue(T.Contains(2));
			Assert::IsTrue(T.Contains(5));

			Assert::IsTrue(!T.Contains(11));
		}

		TEST_METHOD(TestMethodRemove)
		{
			BST T;
			T.Insert(7);
			T.Insert(3);
			T.Insert(10);
			T.Insert(2);
			T.Insert(5);

			Assert::IsTrue(T.Contains(7));
			Assert::IsTrue(T.Contains(3));
			Assert::IsTrue(T.Contains(10));
			Assert::IsTrue(T.Contains(2));
			Assert::IsTrue(T.Contains(5));

			T.Remove(5);
			T.Remove(3);
			T.Remove(7);

			Assert::IsTrue(!T.Contains(7));
			Assert::IsTrue(!T.Contains(3));
			Assert::IsTrue(T.Contains(10));
			Assert::IsTrue(T.Contains(2));
			Assert::IsTrue(!T.Contains(5));
		}

		TEST_METHOD(TestDftIterator)
		{
			BST T;
			T.Insert(7);
			T.Insert(3);
			T.Insert(10);
			T.Insert(2);
			T.Insert(5);
			T.Insert(10);
			T.Insert(100);

			BST::Iterator* I = T.CreateDftIterator();

			Assert::IsTrue(I->GetCurrentData() == 7);
			Assert::IsTrue(I->next() == 3);
			Assert::IsTrue(I->next() == 2);
			Assert::IsTrue(I->next() == 5);
			Assert::IsTrue(I->next() == 10);
			Assert::IsTrue(I->next() == 10);
			Assert::IsTrue(I->next() == 100);
		}

		TEST_METHOD(TestBftIterator)
		{
			BST T;
			T.Insert(7);
			T.Insert(3);
			T.Insert(10);
			T.Insert(2);
			T.Insert(5);
			T.Insert(10);
			T.Insert(100);

			BST::Iterator* I = T.CreateBftIterator();

			Assert::IsTrue(I->nextB() == 7);
			Assert::IsTrue(I->nextB() == 3);
			Assert::IsTrue(I->nextB() == 10);
			Assert::IsTrue(I->nextB() == 2);
			Assert::IsTrue(I->nextB() == 5);
			Assert::IsTrue(I->nextB() == 10);
			Assert::IsTrue(I->nextB() == 100);
		}
	};
}
