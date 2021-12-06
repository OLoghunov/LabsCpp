#include "BinarySearchTree.h"

using namespace std;

bool BST::Contains(int data)
{
	intNode* current = root;
	while (1)
	{
		if (current == nullptr)
			return false;
		else {
			if (data > current->data)
			{
				current = current->pRight;
				continue;
			}
			if (data < current->data)
			{
				current = current->pLeft;
				continue;
			}
			if (data == current->data)
				return true;
		}
	}
}

void BST::Insert(int data)
{
	cout << "Insertion of " << data << endl;
	intNode* current = root;
	if (current == nullptr)
		root = new intNode(nullptr, data);
	else
	{
		while ((current->pLeft != nullptr) || (current->pRight != nullptr))
		{
			if ((data > current->data) && (current->pRight != nullptr))
				current = current->pRight;
			else if ((data > current->data) && (current->pRight == nullptr)) break;

			if ((data <= current->data) && (current->pLeft != nullptr))
				current = current->pLeft;
			else if ((data <= current->data) && (current->pLeft == nullptr)) break;
		}

		if (data > current->data)
			current->pRight = new intNode(current, data);

		else
			current->pLeft = new intNode(current, data);
	}
}

void BST::Remove(int data)
{
	if (!Contains(data))
		throw 1;
	intNode* current = root;
	while (data != current->data)
	{
		if (data < current->data)
			current = current->pLeft;

		else
			current = current->pRight;
	}
	if (current != nullptr)
	{
		if ((current->pLeft == nullptr) && (current->pRight == nullptr))
		{
			intNode* temp = current;
			if (current == root)
				root = nullptr;
			else
			{
				if (current->data > current->pPrev->data)
					current->pPrev->pRight = nullptr;
				else current->pPrev->pLeft = nullptr;
			}
			delete temp; 
		}
		
		else if ((current->pLeft != nullptr) ^ (current->pRight != nullptr))
		{
			intNode* temp = current;
			if (current == root)
				if (current->pLeft != nullptr)
					root = root->pLeft;
				else root = root->pRight;
			else
			{
				if (current->data > current->pPrev->data)
					if (current->pLeft != nullptr)
						current->pPrev->pRight = current->pLeft;
					else current->pPrev->pRight = current->pRight;
				else
					if (current->pLeft != nullptr)
						current->pPrev->pLeft = current->pLeft;
					else current->pPrev->pLeft = current->pRight;
			}
			delete temp;
		}

		else if ((current->pLeft != nullptr) && (current->pRight != nullptr))
		{
			intNode* temp = current;
			current = current->pRight;
			while (current->pLeft != nullptr)
				current = current->pLeft;
			if (temp == root)
				root->data = current->data;
			temp->data = current->data;
			intNode* temp1 = temp;
			temp = current;
			if (current->pPrev == temp1)
				current->pPrev->pRight = nullptr;
			else current->pPrev->pLeft = nullptr;
			delete temp;
		}
	}
}

bool BST::Iterator::hasNext()
{
	if ((kStack.GetSize() != 0) || (current->pLeft != nullptr) || (current->pRight != nullptr))
		return true;
	else return false;
}

bool BST::Iterator::hasNextB()
{
	if (kQueue.GetSize())
		return true;
	else return false;
}

int BST::Iterator::next()
{
	if (current->pRight != nullptr)
	{
		kStack.Push(current->pRight->data);
	}
	if (current->pLeft != nullptr)
		current = current->pLeft;
	else
	{
		if (kStack.GetSize())
		{
			int temp = kStack.GetTop();
			do
				current = current->pPrev;
			while ((current->pRight == nullptr) || (current->pRight->data != temp));
			current = current->pRight;
		}
	}
	return current->data;
}

int BST::Iterator::nextB()
{
	intNode* tempNode = kQueue.GetTop();
	if (tempNode->pLeft != nullptr)
		kQueue.PushBack(tempNode->pLeft);
	if (tempNode->pRight != nullptr)
		kQueue.PushBack(tempNode->pRight);
	return tempNode->data;
}