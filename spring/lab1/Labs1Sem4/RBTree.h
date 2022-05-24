#pragma once
#include "TreeNode.h"
#include "List.h"
#include "Stack.h"
#include <iostream>

using namespace std;
template <typename T>
class RBTree {
	TreeNode<T>* root = nullptr;

	bool Contains(int key)
	{
		TreeNode<T>* current = root;
		while (current != nullptr)
		{
			if (key > current->getKey())
			{
				current = current->pRight;
				continue;
			}
			if (key < current->getKey())
			{
				current = current->pLeft;
				continue;
			}
			if (key == current->getKey())
				return true;
		}
		return false;
	}

	void leftRotate(TreeNode<T>* x) {
		TreeNode<T>* y = x->pRight;
		x->pRight = y->pLeft;
		if (y->pLeft != nullptr) {
			y->pLeft->pParent = x;
		}
		y->pParent = x->pParent;
		if (x->pParent == nullptr) {
			this->root = y;
		}
		else if (x == x->pParent->pLeft) {
			x->pParent->pLeft = y;
		}
		else {
			x->pParent->pRight = y;
		}
		y->pLeft = x;
		x->pParent = y;
	}

	void rightRotate(TreeNode<T>* x) {
		TreeNode<T>* y = x->pLeft;
		x->pLeft = y->pRight;
		if (y->pRight != nullptr) {
			y->pRight->pParent = x;
		}
		y->pParent = x->pParent;
		if (x->pParent == nullptr) {
			this->root = y;
		}
		else if (x == x->pParent->pRight) {
			x->pParent->pRight = y;
		}
		else {
			x->pParent->pLeft = y;
		}
		y->pRight = x;
		x->pParent = y;
	}

	void treeRecoveryAfterInsertion(TreeNode<T>* node) {
		TreeNode<T>* sib;
		while (node->pParent != nullptr && node->pParent->getColor() == Colors::RED) {
			if (node->pParent == node->pParent->pParent->pRight) {
				sib = node->pParent->pParent->pLeft;
				if (sib != nullptr && sib->getColor() == Colors::RED) {
					sib->setColor(Colors::BLACK);
					node->pParent->setColor(Colors::BLACK);
					node->pParent->pParent->setColor(Colors::RED);
					node = node->pParent->pParent;
				}
				else {
					if (node == node->pParent->pLeft) {
						node = node->pParent;
						rightRotate(node);
					}
					node->pParent->setColor(Colors::BLACK);
					node->pParent->pParent->setColor(Colors::RED);
					leftRotate(node->pParent->pParent);
				}
			}
			else {
				sib = node->pParent->pParent->pRight;

				if (sib != nullptr && sib->getColor() == Colors::RED) {
					sib->setColor(Colors::BLACK);
					node->pParent->setColor(Colors::BLACK);
					node->pParent->pParent->setColor(Colors::RED);
					node = node->pParent->pParent;
				}
				else {
					if (node == node->pParent->pRight) {
						node = node->pParent;
						leftRotate(node);
					}
					node->pParent->setColor(Colors::BLACK);
					node->pParent->pParent->setColor(Colors::RED);
					rightRotate(node->pParent->pParent);
				}
			}
			if (node == root) {
				break;
			}
		}
		root->setColor(Colors::BLACK);
	}

	void treeRecoveryAfterRemoval(TreeNode<T>* newNode, TreeNode<T>* parent, TreeNode<T>* brother) {
		while (newNode != root && (newNode == nullptr || newNode->getColor() == Colors::BLACK)) {
			if (newNode == parent->pLeft) {
				if (brother->getColor() == Colors::RED) {
					brother->setColor(Colors::BLACK);
					parent->setColor(Colors::RED);
					leftRotate(parent);
					brother = parent->pRight;
				}

				if ((brother->pLeft == nullptr || brother->pLeft->getColor() == Colors::BLACK) && 
					(brother->pRight == nullptr || brother->pRight->getColor() == Colors::BLACK)) {
					brother->setColor(Colors::RED);
					newNode = parent;
					parent = newNode->pParent;
					if (parent == nullptr)
						brother = nullptr;
					else {
						if (newNode == parent->pLeft)
							brother = parent->pRight;
						else brother = parent->pLeft;
					}
				}
				else {
					if (brother->pRight == nullptr || brother->pRight->getColor() == Colors::BLACK) {
						if (brother->pLeft != nullptr)
							brother->pLeft->setColor(Colors::BLACK);
						brother->setColor(Colors::RED);
						rightRotate(brother);
						brother = parent->pRight;
					}

					brother->setColor(parent->getColor());
					parent->setColor(Colors::BLACK);
					if (brother->pRight != nullptr)
						brother->pRight->setColor(Colors::BLACK);
					leftRotate(parent);
					newNode = root;
					brother = nullptr;
					parent = nullptr;
				}
			}
			else {
				if (brother != nullptr && brother->getColor() == Colors::RED) {
					brother->setColor(Colors::BLACK);
					parent->setColor(Colors::RED);
					rightRotate(parent);
					brother = parent->pLeft;
				}

				if ((brother->pLeft == nullptr || brother->pLeft->getColor() == Colors::BLACK) &&
					(brother->pRight == nullptr || brother->pRight->getColor() == Colors::BLACK)) {
					brother->setColor(Colors::RED);
					newNode = parent;
					parent = newNode->pParent;
					if (parent == nullptr)
						brother = nullptr;
					else {
						if (newNode == parent->pLeft)
							brother = parent->pRight;
						else brother = parent->pLeft;
					}
				}
				else {
					if (brother->pLeft == nullptr || brother->pLeft->getColor() == Colors::BLACK) {
						if (brother->pRight != nullptr)
							brother->pRight->setColor(Colors::BLACK);
						brother->setColor(Colors::RED);
						leftRotate(brother);
						brother = parent->pLeft;
					}

					brother->setColor(parent->getColor());
					parent->setColor(Colors::BLACK);
					if (brother->pLeft != nullptr)
						brother->pLeft->setColor(Colors::BLACK);
					rightRotate(parent);
					newNode = root;
					brother = nullptr;
					parent = nullptr;
				}
			}
		}
		newNode->setColor(Colors::BLACK);
	}

	void removeHelper(TreeNode<T>* del, TreeNode<T>* replace)
	{
		T data = del->getData();
		int key = del->getKey();
		remove(del->getKey());
		replace->setData(data);
		replace->setKey(key);
	}

public:
	void insert(int key, T data) {
		TreeNode<T>* current = root;
		if (root == nullptr) {
			root = new TreeNode<T>(key, data, Colors::RED, nullptr);
			treeRecoveryAfterInsertion(root);
		}
		else {
			while (current != nullptr)
				if (key >= current->getKey()) {
					if (current->pRight == nullptr) {
						current->pRight = new TreeNode<T>(key, data, Colors::RED, current);
						treeRecoveryAfterInsertion(current->pRight);
						break;
					}
					current = current->pRight;
				}
				else {
					if (current->pLeft == nullptr) {
						current->pLeft = new TreeNode<T>(key, data, Colors::RED, current);
						treeRecoveryAfterInsertion(current->pLeft);
						break;
					}
					current = current->pLeft;
				}
		}

	}

	void remove(int key) {
		if (!Contains(key))
			throw exception("You cannot remove a non-existent element!");
		TreeNode<T>* current = root;
		while (key != current->getKey())
		{
			if (key < current->getKey())
				current = current->pLeft;
			else current = current->pRight;
		}
		bool flag = 0;
		TreeNode<T>* parent = nullptr;
		TreeNode<T>* brother = nullptr;
		if ((current->pLeft == nullptr) && (current->pRight == nullptr))
		{
			if (current->getColor() == Colors::BLACK) flag = 1;
			if (current->pParent != nullptr)
			{
				parent = current->pParent;
				if (current == current->pParent->pLeft)
					brother = current->pParent->pRight;
				else brother = current->pParent->pLeft;
			}
			TreeNode<T>* temp = current;
			if (current == root) {
				root = nullptr;
				return;
			}
			else
			{
				if (current->getKey() >= current->pParent->getKey())
					current->pParent->pRight = nullptr;
				else current->pParent->pLeft = nullptr;
			}
			delete temp;

			if (parent == nullptr)
				flag = 0;
			if (flag) treeRecoveryAfterRemoval(nullptr, parent, brother);
		}

		else if ((current->pLeft != nullptr) ^ (current->pRight != nullptr))
		{
			TreeNode<T>* temp = current;

			if (current->pLeft != nullptr)
			{
				if ((current->getColor() == Colors::BLACK) && (current->pLeft->getColor() == Colors::RED))
					current->pLeft->setColor(Colors::BLACK);
				else if ((current->getColor() == Colors::BLACK) && (current->pLeft->getColor() == Colors::BLACK))
					flag = 1;
			}
			else
			{
				if ((current->getColor() == Colors::BLACK) && (current->pRight->getColor() == Colors::RED))
					current->pRight->setColor(Colors::BLACK);
				else if ((current->getColor() == Colors::BLACK) && (current->pRight->getColor() == Colors::BLACK))
					flag = 1;
			}

			if (current == root)
			{
				if (current->pLeft != nullptr)
					root = root->pLeft;
				else root = root->pRight;
				current = root;
			}
			else
			{
				if (current == current->pParent->pRight)
				{
					if (current->pLeft != nullptr) {
						current->pParent->pRight = current->pLeft;
						current->pLeft->pParent = current->pParent;
						current = current->pLeft;
						parent = current->pParent;
						brother = current->pParent->pLeft;
					}
					else {
						current->pParent->pRight = current->pRight;
						current->pRight->pParent = current->pParent;
						current = current->pRight;
						parent = current->pParent;
						brother = current->pParent->pLeft;
					}
				}
				else
				{
					if (current->pLeft != nullptr) {
						current->pParent->pLeft = current->pLeft;
						current->pLeft->pParent = current->pParent;
						current = current->pLeft;
						parent = current->pParent;
						brother = current->pParent->pRight;
					}
					else {
						current->pParent->pLeft = current->pRight;
						current->pRight->pParent = current->pParent;
						current = current->pRight;
						parent = current->pParent;
						brother = current->pParent->pRight;
					}
				}
			}
			delete temp;
			if (flag) treeRecoveryAfterRemoval(current, parent, brother);
		}

		else if ((current->pLeft != nullptr) && (current->pRight != nullptr))
		{
			TreeNode<T>* temp = current;
			current = current->pRight;
			while (current->pLeft != nullptr)
				current = current->pLeft;
			removeHelper(current, temp);
		}
	}

	List<int> getKeys()
	{
		List<int> list;
		Iterator* J = CreateIterator();
		if (J->getCurrent() != nullptr)
			list.pushBack(J->getCurrent()->getKey());
		while (J->hasNext()) {
			list.pushBack(J->next()->getKey());
		}
		return list;
	}

	List<T> getValues()
	{
		List<T> list;
		Iterator* J = CreateIterator();
		if (J->getCurrent() != nullptr)
			list.pushBack(J->getCurrent()->getData());
		while (J->hasNext()) {
			list.pushBack(J->next()->getData());
		}
		return list;
	}

	TreeNode<T>* find(int key) {
		TreeNode<T>* current = root;
		while ((current != nullptr) && (current->getKey() != key))
		{
			if (key >= current->getKey())
				current = current->pRight;
			else current = current->pLeft;
		}
		if (current == nullptr)
			throw exception("Element is not found!");
		else return current;
	}

	void clear() {
		while (root != nullptr)
			remove(root->getKey());
	}


	void print() {
		RBTree<int>::Iterator* J = CreateIterator();
		cout << J->getCurrent()->getKey() << ' ';
		while (J->hasNext()) {
			cout << J->next()->getKey() << ' ';
		}
		cout << endl;
	}

	class Iterator
	{
	public:
		Iterator(TreeNode<T>* start)
		{
			current = start;
		}

		bool hasNext()
		{
			if (current != nullptr && ( (kStack.GetSize() != 0) || (current->pLeft != nullptr) || (current->pRight != nullptr)))
				return true;
			else return false;
		}

		TreeNode<T>* next()
		{
			if (current->pRight != nullptr)
			{
				kStack.Push(current->pRight);
			}
			if (current->pLeft != nullptr)
				current = current->pLeft;
			else
			{
				if (kStack.GetSize())
				{
					TreeNode<T>* temp = kStack.GetTop();
					while ((current->pRight == nullptr) || (current->pRight->getKey() != temp->getKey()))
						current = current->pParent;
					current = current->pRight;
				}
			}
			return current;
		}

		bool checkTree()
		{
			int count = 1, fcount = 0;
			while (hasNext())
			{
				if (current->pRight != nullptr)
				{
					kStack.Push(current->pRight);
				}
				if (current->pLeft != nullptr)
				{
					if (current->pLeft->getColor() == Colors::BLACK)
						count++;
					current = current->pLeft;
				}
				else
				{
					if (fcount == 0)
						fcount = count;
					if (count != fcount)
						return false;
					if (kStack.GetSize())
					{
						TreeNode<T>* temp = kStack.GetTop();
						while ((current->pRight == nullptr) || (current->pRight->getKey() != temp->getKey()))
						{
							if (current->getColor() == Colors::BLACK)
								count--;
							current = current->pParent;
						}
						if (current->pRight->getColor() == Colors::BLACK)
							count++;
						current = current->pRight;
					}
				}
			}
			return true;
		}

		TreeNode<T>* getCurrent() { return current; }
		void setCurrent(TreeNode<T>* current)
		{
			this->current = current;
		}
		Stack<T> getStack() { return this->kStack; }
	private:
		TreeNode<T>* current;
		Stack<T> kStack;
	};

	Iterator* CreateIterator()
	{
		return new Iterator(root);
	}
};
