#pragma once
#include "node.h"
#include <iostream>

using namespace std;
class Map
{
	Node *head;
	int size;
	
public:

	Node* getHead() { return this->head; }

	Map()
	{
		head = nullptr;
		size = 0;
	}

	Map(Map& d)
	{
		head = new Node();
		if ((d.getHead()) != nullptr)
			*head = *(d.getHead());
		else head = nullptr;
		this->size = d.getSize();
	}

	void increase(char symb)
	{
		Node* cur = head;
		while (cur != nullptr)
		{
			if (cur->symbol == symb) {
				cur->key++;
				return;
			}
			else cur = cur->pNext;
		}
		throw exception("err");
	}

	void normalize(double c)
	{
		Node* cur = head;
		while (cur != nullptr) {
			cur->key = cur->key / c;
			cur = cur->pNext;
		}
	}

	void algorithm()
	{
		Node* cur = head;
		if (cur == nullptr)
			throw exception("String is empty!");

		if (cur->pNext == nullptr) {
			cur->bitcode->push(0);
			return;
		}

		if (cur->pNext->pNext == nullptr) {
			cur->bitcode->push(0);
			cur->pNext->bitcode->push(1);
			return;
		}

		double lSum = cur->key;
		double rSum = 1 - lSum;
		cur = cur->pNext;

		while (rSum > lSum && cur != nullptr)
		{
			if (abs(lSum - rSum) >= abs(lSum + cur->key - 1 + lSum + cur->key)) {
				lSum += cur->key;
				rSum = 1 - lSum;
				cur = cur->pNext;
			}
			else break;
		}
			Node* temp = cur->pParent;
			Node* lRightBorder = temp;
			Node* rLeftBorder = cur;

		do {
			cur->bitcode->push(1);
			cur = cur->pNext;
		} while ((cur != nullptr) && (cur->pNext != nullptr));
		if (cur != nullptr) cur->bitcode->push(1);
		
		do {
			temp->bitcode->push(0);
			temp = temp->pParent;
		} while ((temp != nullptr) && (temp->pParent != nullptr));
		if (temp != nullptr) temp->bitcode->push(0);

		if (temp != lRightBorder && temp != nullptr)
			algorithm(temp, lRightBorder, lSum);
		else if (lSum != lRightBorder->key && temp != nullptr) temp->bitcode->push(0);

		if (rLeftBorder != cur && cur != nullptr)
			algorithm(rLeftBorder, cur, rSum);
		else if (rSum != rLeftBorder->key && cur != nullptr) cur->bitcode->push(1);
	}

	void algorithm(Node* left, Node* right, double sum)
	{
		Node* cur = left;
		if (cur->pNext == right) {
			cur->bitcode->push(0);
			right->bitcode->push(1);
			return;
		}
		else
		{
			double lSum = cur->key;
			double rSum = sum - lSum;
			cur = cur->pNext;

			while (rSum > lSum && cur != nullptr)
			{
				if (abs(lSum - rSum) >= abs(lSum + cur->key - sum + lSum + cur->key)) {
					lSum += cur->key;
					rSum = sum - lSum;
					cur = cur->pNext;
				}
				else break;
			}

			Node* temp = cur->pParent;
			Node* lRightBorder = temp;
			Node* rLeftBorder = cur;

			do {
				cur->bitcode->push(1);
				if (cur == right)
					break;
				cur = cur->pNext;
			} while (cur != nullptr);
			if (cur != nullptr && cur != right) cur->bitcode->push(1);

			do {
				temp->bitcode->push(0);
				if (temp == left)
					break;
				temp = temp->pParent;
			} while (temp != nullptr);
			if (temp != nullptr && temp != left) temp->bitcode->push(0);

			if (temp != lRightBorder)
				algorithm(temp, lRightBorder, lSum);
			else if (lSum != lRightBorder->key) temp->bitcode->push(0);
			
			if (rLeftBorder != cur)
				algorithm(rLeftBorder, cur, rSum);
			else if (rSum != rLeftBorder->key) cur->bitcode->push(1);
		}
	}

	void mapFiller(string str)
	{
		Map newMap;
		for (char& c : str) {
			try { newMap.increase(c); }
			catch (exception x) { newMap.pushFront(1, c); }
		}
		insert(newMap);
		normalize(double(str.length()));
	}

	void pushBack(double key, char symb);
	void pushFront(double key, char symb);
	void popBack();
	void popFront();
	void insert(double key, char symb);
	void insert(Map &newMap);
	int getSize() { return size; };
	void clear();
	bool isEmpty();

	friend std::ostream& operator<<(std::ostream& s, Map& list)
	{
		int count = 1;
		Node* current = list.head;
		while (count <= list.size) {
			s << current->key << ' ' << current->symbol << endl;
			current = current->pNext;
			count++;
		}
		return s;
	}
};
