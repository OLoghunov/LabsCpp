#pragma once
#include "Stack.h"
#include <string>


template <class T>
Stack<T>::Stack()
{
	size = 0;
	head = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
	Clear();
}

template <class T>
void Stack<T>::Push(T data)
{
	head = new Node(data, head);
	size++;
}

template<class T>
T Stack<T>::GetTop()
{
	T temp = head->data;
	return temp;
}

template<class T>
void Stack<T>::PopFront()
{
	if (this->size)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

template<class T>
void Stack<T>::Clear()
{
	while (size)
		PopFront();
}