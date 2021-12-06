#pragma once
#include "Stack.h"
#include "Queue.h"

class BST
{
public:
	BST()
	{
		root = nullptr;
	}
	~BST()
	{
		while (root != nullptr)
			Remove(root->data);
	}
	bool Contains(int data);
	void Insert(int data);
	void Remove(int data);
	
	intNode* root;

	class Iterator
	{
	public:
		Iterator(intNode* start)
		{
			current = start;
			if (start != nullptr)
				kQueue.PushBack(start);
		}

		bool hasNext();
		bool hasNextB();
		int next();
		int nextB();
		int GetCurrentData() { return current->data; };
	private:
		intNode* current;
		Stack kStack;
		Queue kQueue;
	};

	Iterator* CreateDftIterator()
	{
		cout << root->data << ' ';
		return new Iterator(root);
	}
	Iterator* CreateBftIterator()
	{
		return new Iterator(root);
	}
};