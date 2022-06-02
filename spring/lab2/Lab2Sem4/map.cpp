#include "map.h"

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
	if (size == 0) {
		head = new Node(key, symb, head, nullptr);
		size++;
	}
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