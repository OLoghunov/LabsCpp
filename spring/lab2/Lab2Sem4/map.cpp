#include "map.h"

void Map::pushBack(double key, char symb)
{
	if (head == nullptr)
		head = new Node(key, symb, nullptr, nullptr);
	else
	{
		Node* cur = this->head;
		while (cur->pNext != nullptr)
			cur = cur->pNext;
		cur->pNext = new Node(key, symb, nullptr, cur);
	}
	size++;
}

void Map::pushFront(double key, char symb)
{
	head = new Node(key, symb, head, nullptr);
	size++;
}

void Map::popBack()
{
	if (size == 1)
	{
		Node* temp = head;
		head = nullptr;
		delete temp;
		size--;
	}
	if (size > 1)
	{
		Node* cur = this->head;
		int i = 1;
		while (i < size - 1) {
			cur = cur->pNext;
			i++;
		}
		Node* temp = cur->pNext;
		cur->pNext = nullptr;
		delete temp;
		size--;
	}
}

void Map::popFront()
{
	if (this->size)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

void Map::insert(Map &origMap)
{
	Node* cur = origMap.getHead();
	while (cur != nullptr) {
		this->insert(cur->key, cur->symbol);
		cur = cur->pNext;
	}
}

void Map::insert(double key, char symb)
{
	if (size == 0)
		pushFront(key, symb);
	else
	{
		Node* current = head;
		while (current->key >= key && current->pNext != nullptr)
			current = current->pNext;
		if (current->key < key)
			if (current != head) {
				Node* temp = current->pParent;
				current->pParent->pNext = new Node(key, symb, current, current->pParent);
				current->pParent = temp->pNext;
			}
			else {
				head = new Node(key, symb, current, nullptr);
				current->pParent = head;
			}
		else current->pNext = new Node(key, symb, nullptr, current);

		size++;
	}
}

void Map::clear()
{
	while (size)
		popFront();
}

bool Map::isEmpty()
{
	if (size)
		return false;
	else
		return true;
}