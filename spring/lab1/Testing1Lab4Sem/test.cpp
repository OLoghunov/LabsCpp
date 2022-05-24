#include "pch.h"
#include "..\Labs1Sem4\RBTree.h"

TEST(TestInsertion, sis) {
	RBTree<int> T;
	RBTree<int>::Iterator* J = T.CreateIterator();

	T.insert(2, 0);
	T.insert(1, 1);
	T.insert(5, 3);
	T.insert(4, 10);
	T.insert(10, 10);
	T.insert(3, 22);
	T.insert(9, 11);
	T.insert(34, 77);
	T.insert(20, 15);
  
	EXPECT_TRUE(J->checkTree());
}

TEST(TestRemoval, sis) {
	RBTree<int> T;
	RBTree<int>::Iterator* J = T.CreateIterator();

	T.insert(1, 0);
	T.insert(5, 0);
	T.insert(2, 0);
	T.insert(4, 0);
	T.insert(6, 0);
	T.insert(3, 0);
	T.insert(7, 0);
	T.insert(13, 0);
	T.insert(12, 0);
	T.insert(14, 0);

	J = T.CreateIterator();
	T.remove(5);
	EXPECT_TRUE(J->checkTree());

	J = T.CreateIterator();
	T.remove(2);
	EXPECT_TRUE(J->checkTree());

	J = T.CreateIterator();
	T.remove(4);
	EXPECT_TRUE(J->checkTree());
	
	J = T.CreateIterator();
	T.remove(3);
	EXPECT_TRUE(J->checkTree());
	
	J = T.CreateIterator();
	T.remove(1);
	EXPECT_TRUE(J->checkTree());
	
	J = T.CreateIterator();
	T.remove(6);
	EXPECT_TRUE(J->checkTree());

	bool exceptionThrown = false;

	try
	{
		T.remove(33);
	}
	catch (int)
	{
		exceptionThrown = true;
	}
	catch (...)
	{
		exceptionThrown = true;
	}

	assert(exceptionThrown);
} 

TEST(TestClear, sis) {
	RBTree<int> T;
	RBTree<int>::Iterator* J = T.CreateIterator();

	T.insert(1, 0);
	T.insert(5, 0);
	T.insert(2, 0);
	T.insert(4, 0);
	T.insert(6, 0);
	T.insert(3, 0);
	T.insert(7, 0);
	T.insert(13, 0);
	T.insert(12, 0);
	T.insert(14, 0);

	T.clear();

	EXPECT_TRUE(T.getKeys().getSize() == 0);
}

TEST(TestFind, sis) {
	RBTree<int> T;
	RBTree<int>::Iterator* J = T.CreateIterator();

	T.insert(1, 0);
	T.insert(5, 0);
	T.insert(2, 0);
	T.insert(4, 0);
	T.insert(6, 0);
	T.insert(3, 0);
	T.insert(7, 0);
	T.insert(13, 0);
	T.insert(12, 0);
	T.insert(14, 0);

	EXPECT_TRUE(T.find(4)->getKey() == 4 && T.find(4)->getData() == 0);
	EXPECT_TRUE(T.find(5)->getKey() == 5 && T.find(5)->getData() == 0);

	bool exceptionThrown = false;

	try
	{
		T.find(33);
	}
	catch (int)
	{
		exceptionThrown = true;
	}
	catch (...)
	{
		exceptionThrown = true;
	}

	assert(exceptionThrown);
}

TEST(TestGetKeysGetValues, sis) {
	RBTree<int> T;

	List<int> keys = T.getKeys();
	List<int> data = T.getValues();

	int sizeKeys = keys.getSize();
	int sizeData = data.getSize();

	EXPECT_TRUE(sizeKeys == 0 && sizeData == 0);

	T.insert(1, 0);
	T.insert(5, 0);
	T.insert(2, 0);
	T.insert(4, 0);

	keys = T.getKeys();
	data = T.getValues();

	sizeKeys = keys.getSize();
	sizeData = data.getSize();
	int headKeys = keys.getHead()->getData();
	int headData = data.getHead()->getData();

	EXPECT_TRUE(sizeKeys == 4 && sizeData == 4);
	EXPECT_TRUE(headKeys == 2);
	EXPECT_TRUE(headData == 0);
}