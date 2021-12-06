#pragma once
struct intNode
{
	intNode* pLeft;
	intNode* pRight;
	intNode* pPrev;
	int data;
	intNode(intNode* pPrev = nullptr, int data = int(), intNode* pLeft = nullptr, intNode* pRight = nullptr)
	{
		this->pPrev = pPrev;
		this->data = data;
		this->pLeft = pLeft;
		this->pRight = pRight;
	}
};
