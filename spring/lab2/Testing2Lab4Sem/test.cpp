#include "pch.h"
#include "../Lab2Sem4/shannon_fano.h"

TEST(TestEncode, sis) {
	string str = "qw";
	Map map = encode(str);
	EXPECT_TRUE(map.getSize() == 2);
	EXPECT_TRUE(map.getHead()->bitcode->getSize() == 1);
	EXPECT_TRUE(map.getHead()->bitcode->getHead()->data == 0);
	EXPECT_TRUE(map.getHead()->pNext->bitcode->getSize() == 1);
	EXPECT_TRUE(map.getHead()->pNext->bitcode->getHead()->data == 1);
	Bitcode code;
	Node* cur = nullptr;
	for (char& c : str) {
		cur = map.getHead();
		while (cur->symbol != c)
			cur = cur->pNext;
		BitNode* temp = cur->bitcode->getHead();
		int maxCode = 0;
		if (cur->bitcode->getSize() > maxCode) {
			maxCode = cur->bitcode->getSize();
		}
		while (temp != nullptr) {
			code.push(temp->data);
			temp = temp->pNext;
		}
	}
	EXPECT_TRUE(code.getSize() == 2);
	EXPECT_TRUE(code.getHead()->data == 1);
	EXPECT_TRUE(code.getHead()->pNext->data == 0);

	str = "qww";
	map = encode(str);
	EXPECT_TRUE(map.getSize() == 2);
	EXPECT_TRUE(map.getHead()->bitcode->getSize() == 1);
	EXPECT_TRUE(map.getHead()->bitcode->getHead()->data == 1);
	EXPECT_TRUE(map.getHead()->pNext->bitcode->getSize() == 2);
	EXPECT_TRUE(map.getHead()->pNext->bitcode->getHead()->data == 0);
	cur = nullptr;
	for (char& c : str) {
		cur = map.getHead();
		while (cur->symbol != c)
			cur = cur->pNext;
		BitNode* temp = cur->bitcode->getHead();
		int maxCode = 0;
		if (cur->bitcode->getSize() > maxCode) {
			maxCode = cur->bitcode->getSize();
		}
		while (temp != nullptr) {
			code.push(temp->data);
			temp = temp->pNext;
		}
	}
	EXPECT_TRUE(code.getSize() == 3);
	EXPECT_TRUE(code.getHead()->data == 1);
	EXPECT_TRUE(code.getHead()->pNext->data == 0);
	EXPECT_TRUE(code.getHead()->pNext->pNext->data == 0);
}

TEST(TestDecode, sis) {
	Bitcode newCode;
	newCode.push(1);
	newCode.push(0);
	newCode.push(1);
	newCode.push(0);
	newCode.push(1);
	newCode.push(0);
	Map newMap;

	bool exceptionThrown = false;
	try
	{
		decode(newCode, newMap);
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