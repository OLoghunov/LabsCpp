#pragma once
#include <iostream>
using namespace std;

template <class T>
class ListNode
{
public:
	ListNode(T& data, ListNode* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
	ListNode* pNext;
	T data;
};

template <class T>
class List
{
public:
	ListNode<T>* head;
	ListNode<T>* tail;
	int size;

	List() : head(nullptr), tail(nullptr), size(0) {}

	List(int size, T* arr)
	{
		this->head = nullptr;
		this->tail = nullptr;
		for (int i = 0; i < size; i++) this->PushBack(arr[i]);
	}

	List(List<T>& ref) : head(nullptr), tail(nullptr)
	{
		for (int i = 0; i < ref.GetSize(); i++)
		{
			T newNode = ref.GetData(i);
			this->PushBack(newNode);
		}
	}

	~List()
	{
		if (head != nullptr) Clear();
	}

	List<T>& operator+(List<T>& l)
	{
		List<T>* newList = new List<T>();
		for (int i = 0; i < GetSize(); i++) newList->PushBack(GetData(i));
		for (int i = 0; i < l.GetSize(); i++) newList->PushBack(l.GetData(i));
		return *newList;
	}

	void operator+=(List<T>& l)
	{
		*this = *this + l;
	}

	friend bool operator==(List<T>& list1, List<T>& list2)
	{
		ListNode* current1 = list1.head;
		ListNode* current2 = list2.head;
		while (current1 != nullptr)
		{
			if (current2 != nullptr)
			{
				if (current1->data != current2->data) return false;
			}
			else return false;
			current1 = current1->pNext;
			current2 = current2->pNext;
		}
		if (current2 != nullptr) return false;
		return true;
	}

	friend ostream& operator<<(ostream& stream, List<T>& list)
	{
		ListNode* current = list.head;
		stream << "[";
		while (current != nullptr)
		{
			stream << current->data;
			if (current->next != nullptr) stream << " ";
			current = current->pNext;
		}
		stream << "]";
		return stream;
	}

	void Clear() { while (size) PopFront(); }

	int GetSize() { return size; }

	int Find(T data)
	{
		ListNode<T>* current = head;
		int index = 0;
		while (current != nullptr)
		{
			if (current->data == data) return index;
			current = current->pNext;
			index++;
		}
		return -1;
	}

	void PushFront(T data)
	{
		head = new ListNode(data, head);
		size++;
	}

	void PushBack(T data)
	{
		if (head == nullptr)
			head = new ListNode<T>(data);
		else
		{
			ListNode<T>* cur = this->head;
			while (cur->pNext != nullptr)
				cur = cur->pNext;
			cur->pNext = new ListNode<T>(data);
		}
		size++;
	}

	void Insert(int index, T data)
	{
		if (index < 0 || index >= this->GetSize())
			throw out_of_range("check method List::Insert");
		if (index == 0)
			PushFront(data);
		else
		{
			ListNode* current = head;
			unsigned count = 0;
			while (count != index - 1)
			{
				count++;
				current = current->pNext;
			}
			ListNode* temp = current->pNext;
			current->pNext = new ListNode(data, temp);
			size++;
		}
	}

	void PopFront()
	{
		if (size)
		{
			ListNode<T>* temp = head;
			head = head->pNext;
			delete temp;
			size--;
		}
	}

	void PopBack()
	{
		if (size == 1)
		{
			ListNode* temp = head;
			head = nullptr;
			delete temp;
			size--;
		}
		if (size > 1)
		{
			ListNode* cur = this->head;
			unsigned i = 1;
			while (i < size - 1) {
				cur = cur->pNext;
				i++;
			}
			ListNode* temp = cur->pNext;
			cur->pNext = nullptr;
			delete temp;
			size--;
		}
	}

	void Remove(int index)
	{
		if (index < 0 || index >= this->GetSize())
			throw out_of_range("check method List::Remove");
		if (index == 0)
			PopFront();
		else
		{
			unsigned count = 0;
			ListNode* current = head;
			while (count != index - 1)
			{
				count++;
				current = current->pNext;
			}
			ListNode* temp = current->pNext;
			current->pNext = temp->pNext;
			delete temp;
			size--;
		}
	}

	T& GetData(int index = 0)
	{
		ListNode<T>* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (i == index) return current->data;
			i++;
			current = current->pNext;
		}
		throw out_of_range("Index is incorrect");
	}

	inline void PrintData() { cout << *this; }
};

template <typename T>
class Queue
{
	int size;
	ListNode<T>* head;

public:
	Queue()
	{
		size = 0;
		head = nullptr;
	}

	~Queue()
	{
		Clear();
	}

	void PushBack(T data)
	{
		if (head == nullptr)
			head = new ListNode(data);
		else
		{
			ListNode* cur = this->head;
			while (cur->pNext != nullptr)
				cur = cur->pNext;
			cur->pNext = new ListNode(data);
		}
		size++;
	}

	T GetTop()
	{
		T temp = head->data;
		PopFront();
		return temp;
	}

	void PopFront()
	{
		if (this->size)
		{
			ListNode* temp = head;
			head = head->pNext;
			delete temp;
			size--;
		}
	}

	int GetSize() { return size; };

	void Clear()
	{
		while (size)
			PopFront();
	}
};

template <class T>
class Stack : public List<T>
{
	int size;
	ListNode<T>* head;
public:
	Stack() : size(0), head(nullptr) {}

	~Stack() { Clear(); }

	void Push(T data)
	{
		head = new ListNode(data, head);
		size++;
	}

	T GetTop()
	{
		T temp = head->data;
		PopFront();
		return temp;
	}

	void PopFront()
	{
		if (this->size)
		{
			ListNode* temp = head;
			head = head->pNext;
			delete temp;
			size--;
		}
	}

	int GetSize() { return size; };
	void Clear() { while (size) PopFront(); }
};