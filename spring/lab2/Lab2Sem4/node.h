#pragma once
#include "bitcode.h"

class Node
{
public:
	Node(double key = 0, char symbol = ' ', Node* pNext = nullptr, Node* pParent = nullptr, Bitcode* bitcode = new Bitcode)
	{
		this->key = key;
		this->symbol = symbol;
		this->pNext = pNext;
		this->pParent = pParent;
		this->bitcode = bitcode;
	}
	double key;
	char symbol;
	Node* pNext;
	Node* pParent;
	Bitcode* bitcode;
};
