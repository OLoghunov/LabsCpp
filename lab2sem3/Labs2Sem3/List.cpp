#include "List.h"

List::List()
{
	size = 0;
	head = nullptr;
}

List::~List()
{
	Clear();
}

void List::PushBack(int data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* cur = this->head;
		while (cur->pNext != nullptr)
			cur = cur->pNext;
		cur->pNext = new Node(data);
	}
	size++;
}

void List::PushFront(int data)
{
	head = new Node(data, head);
	size++;
}

void List::PopBack()
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
		unsigned i = 1;
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

void List::PopFront()
{
	if (this->size)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

void List::Insert(int data, int index)
{
	if (index <= this->size)
	{
		if (index == 0)
			PushFront(data);
		else
		{
			Node* current = head;
			unsigned count = 0;
			while (count != index - 1)
			{
				count++;
				current = current->pNext;
			}
			Node* temp = current->pNext;
			current->pNext = new Node(data, temp);
			size++;
		}
	}
	else { std::cout << "\nThe method Insert has an erroneous index "; };
}

int List::At(int index)
{
	if (index <= this->size)
	{
		unsigned count = 0;
		Node* current = head;
		while (count != index)
		{
			count++;
			current = current->pNext;
		}
		return current->data;
	}
	else { std::cout << "\nThe method At has an erroneous index "; return index; };
}

void List::Remove(int index)
{
	if (index <= this->size)
	{
		if (index == 0)
			PopFront();
		else
		{
			unsigned count = 0;
			Node* current = head;
			while (count != index - 1)
			{
				count++;
				current = current->pNext;
			}
			Node* temp = current->pNext;
			current->pNext = temp->pNext;
			delete temp;
			size--;
		}
	}
}

void List::Clear()
{
	while (size)
		PopFront();
}

void List::Set(int data, int index)
{
	if (index <= this->size)
	{
		unsigned count = 0;
		Node* current = head;
		while (count != index)
		{
			count++;
			current = current->pNext;
		}
		current->data = data;
	}
	else { std::cout << "\nThe method Set has an erroneous index "; };
}

bool List::IsEmpty()
{
	if (size)
		return false;
	else
		return true;
}

void List::Swap(int index1, int index2)
{
	if ((index1 < this->size) && (index2 < this->size))
	{
		unsigned count = 0;
		Node* temp = head;
		Node* temp1 = head;
		int tempData = 0;
		while (count < this->GetSize())
		{
			if (count == index1)
			{
				temp1 = temp;
				tempData = temp->data;
				break;
			}
			count++;
			temp = temp->pNext;
		}

		count = 0;
		temp = head;
		while (count < this->GetSize())
		{
			if (count == index2)
			{
				temp1->data = temp->data;
				temp->data = tempData;
				break;
			}
			count++;
			temp = temp->pNext;
		}
	}
}

bool List::IsCorrect()
{
	unsigned count = 0;
	Node* temp = this->head;
	while (count < this->GetSize() - 1)
	{
		if (temp->pNext->data < temp->data)
			return false;
		count++;
		temp = temp->pNext;
	}
	return true;
}



int List::FindFirst(List& newList)
{
	if (newList.GetSize() > this->GetSize())
		return -1;
	else
	{
		unsigned count = 1, countForNewList = 1;
		Node* currentBase = this->head;
		Node* currentNew = newList.head;
		while (count <= this->GetSize())
		{
			if (currentBase->data == currentNew->data)
			{
				if (countForNewList == newList.GetSize())
					break;
				countForNewList++;
				count++;
				currentBase = currentBase->pNext;
				currentNew = currentNew->pNext;
			}
			else
			{
				countForNewList = 1;
				count++;
				currentNew = newList.head;
				currentBase = currentBase->pNext;
			}
		}
		if ((countForNewList == newList.GetSize()) && (count <= this->GetSize()))
			return count - countForNewList;
		else return -1;
	}
}

int& List::operator[](const int index)
{
	int count = 0;
	Node* current = this->head;
	while (current != nullptr) {
		if (count == index)
			return current->data;
		current = current->pNext;
		count++;
	}
}