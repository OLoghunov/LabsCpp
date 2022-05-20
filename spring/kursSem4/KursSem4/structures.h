#pragma once
#include <iostream>
#include "structures.h"
#include <fstream>
#include <iomanip>

#define INF numeric_limits<double>::max()

using namespace std;
const string NA = "N/A";

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
		ListNode<T>* current = list.head;
		stream << "[";
		while (current != nullptr)
		{
			stream << this->names[current->data];
			if (current->pNext != nullptr) stream << " ";
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
		head = new ListNode<T>(data, head);
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

	T PeekBack()
	{
		if (!size)
			throw exception("List is empty!");
		else {
			ListNode<T>* cur = head;
			while (cur->pNext != nullptr)
				cur = cur->pNext;
			return cur->data;
		}
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
	Queue() : size(0), head(nullptr) {}

	~Queue() { Clear(); }

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

	T GetTop()
	{
		if (!size)
			throw exception("Cannot get a non existest element!");
		T temp = head->data;
		PopFront();
		return temp;
	}

	void PopFront()
	{
		if (this->size)
		{
			ListNode<T>* temp = head;
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
class Stack
{
	int size;
	ListNode<T>* head;
public:
	Stack() : size(0), head(nullptr) {}

	~Stack() { Clear(); }

	void PushFront(T data)
	{
		head = new ListNode(data, head);
		size++;
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
		if (!size)
			throw exception("Cannot get a non existest element!");
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

class Matrix
{
	void drawThickLine(ostream& str, Matrix& matrix, int maxwidth)
	{
		str << "==";
		for (int i = 0; i < maxwidth; i++) str << '=';
		str << "====";
		for (int i = 0; i < matrix.size; i++)
		{
			const size_t len = matrix.names[i].length();
			for (int j = 0; j < len; j++)
				str << '=';
			str << "==" << (i == matrix.size - 1 ? '\n' : '=');
		}
	}

public:
	int size, source, sink;
	string* names;
	double** values;
	bool* visit;
	bool flag = false;
	Queue<int> q;
	List<int> parentsList;

	Matrix(int size = 0, string* names = nullptr, double** values = nullptr)
	{
		this->values = values;
		this->names = names;
		this->size = size;
	}

	~Matrix()
	{
		if (values != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] values[i];
			}
			delete[] values;
		}
	}

	friend ifstream& operator>>(ifstream& str, Matrix& matrix)
	{
		string from, to;
		double value;
		List<string> tempNames;
		while (!str.eof())
		{
			string temp;
			str >> from >> to >> value;
			if (tempNames.Find(from) < 0) tempNames.PushBack(from);
			if (tempNames.Find(to) < 0) tempNames.PushBack(to);
			if (value == 0)
			{
				str.clear();
				str >> temp;
				if (temp != "0") throw invalid_argument("Wrong input");
			}
		}
		matrix.size = tempNames.GetSize();
		matrix.names = new string[matrix.size];
		matrix.values = new double* [matrix.size];
		matrix.visit = new bool[matrix.size];
		for (int i = 0; i < matrix.size; i++)
		{
			matrix.visit[i] = false;
			matrix.names[i] = tempNames.GetData();
			if (tempNames.GetData() == "S")
				matrix.source = i;
			if (tempNames.GetData() == "T")
				matrix.sink = i;
			tempNames.PopFront();
			matrix.values[i] = new double[matrix.size];
			matrix.visit[i] = false;
			for (int j = 0; j < matrix.size; j++)
				matrix.values[i][j] = 0;
		}
		str.seekg(ios::beg);
		while (!str.eof())
		{
			string temp;
			str >> from >> to >> value;
			int i = 0, j = 0, k;
			for (k = 0; k < matrix.size; k++)
			{
				if (matrix.names[k] == from) i = k;
				if (matrix.names[k] == to) j = k;
			}
			matrix.values[i][j] = value;
		}
		return str;
	}

	friend ostream& operator<<(ostream& str, Matrix& matrix)
	{
		int maxwidth = 1;
		/*for (int i = 0; i < matrix.size; i++)
			if (matrix.names[i].length() > maxwidth) maxwidth = matrix.names[i].length();*/
		str << "  ";
		for (int i = 0; i < maxwidth; i++)
			str << ' ';
		str << " || ";
		for (int i = 0; i < matrix.size; i++)
			str << setw(matrix.names[i].length()) << left << matrix.names[i] << "   ";
		str << "\n";
		matrix.drawThickLine(str, matrix, maxwidth);
		for (int i = 0; i < matrix.size; i++)
		{
			str << "  " << setw(maxwidth) << right << matrix.names[i] << " || ";
			for (int j = 0; j < matrix.size; j++)
			{
				str << setw(matrix.names[j].length()) << left;
				str << matrix.values[i][j] << "   ";
			}
			str << "\n";
		}
		return str;
	}

	friend bool operator==(Matrix& mtx1, Matrix& mtx2)
	{
		if (mtx1.size != mtx2.size) return false;
		for (size_t i = 0; i < mtx1.size; i++) if (mtx1.names[i] != mtx2.names[i]) return false;
		for (size_t i = 0; i < mtx1.size; i++)
			for (size_t j = 0; j < mtx1.size; j++)
				if (mtx1.values[i][j] != mtx2.values[i][j])
					return false;
		return true;
	}

	int getFirstNeighbor(int v)
	{
		for (int i = 0; i < this->size; i++)
			if ((values[v][i]) != 0)
				return i;
		return -1;
	}

	int getNextNeighbor(int v, int w)
	{
		for (int i = w + 1; i < this->size; i++)
			if ((values[v][i]) != 0)
				return i;
		return -1;
	}

	void bfs(int i)
	{
		int* parent = new int[size];
		for (int p = 0; p < size; p++)
			parent[p] = -2;
		int v = -1;
		parentsList.Clear();
		q.PushBack(i);
		while (q.GetSize()) {
			i = q.GetTop();
			if (!visit[i]) {
				visit[i] = true;
			}
			v = getFirstNeighbor(i);
			if (v == sink) {
				parentsList.PushFront(v);
				parentsList.PushFront(i);
				break;
			}
			while (v != -1)
			{
				if (!visit[v]) {
					q.PushBack(v);
					visit[v] = true;
					parent[v] = i;
				}
				v = getNextNeighbor(i, v);
				if (v == sink) {
					parentsList.PushFront(v);
					parentsList.PushFront(i);
					break;
				}
			}
			if (v == sink) break;
		}
		
		if (v == sink) {
			while (i != source)
			{
				parentsList.PushFront(parent[i]);
				i = parent[i];
			}
		}
		for (int j = 0; j < size; j++)
			visit[j] = false;
		q.Clear();
		return;
	}
};