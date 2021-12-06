#include "List.h"
#include <ctime>

using namespace std;
bool IsCorrect(int A[], int size)
{
	for (unsigned i = 0; i < size - 1; i++)
		if (A[i + 1] < A[i])
			return false;
	return true;
}

int BinarySearch(int A[], int size, int x)
{
	if (!IsCorrect(A, size))
		throw 2;
	unsigned currentCenter = size / 2;
	unsigned currentSize = size;
	while (currentSize > 0)
	{
		if (x == A[currentCenter])
			return currentCenter;
		else
			if (x < A[currentCenter])
			{
				currentSize = currentSize / 2;
				if (currentSize != 1)
					currentCenter -= currentSize / 2 + 1;
				else currentCenter -= 1;
			}
			else
				if (x > A[currentCenter])
				{
					currentSize = currentSize / 2;
					if (currentSize != 1)
						if ((currentSize % 2) == 0)
							currentCenter += currentSize / 2;
						else
							currentCenter += currentSize / 2 + 1;
					else currentCenter += 1; 
				}
	}
	return -1;
}

void Swap(int A[], int size, int index1, int index2)
{
	if (size < 0 || index1 < 0 || index1 >= size || index2 < 0 || index2 >= size)
		throw 1;
	int temp = 0;
	temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;
}

void Shuffle(int A[], int size)
{
	if (size < 0)
		throw 1;
	for (unsigned i = 0; i < size; i++)
		Swap(A, size, i, rand() % size);
}

bool IsCorrect(char A[], int size)
{
	if (size < 0)
		throw 1;
	for (unsigned i = 0; i < size - 1; i++)
		if (A[i + 1] < A[i])
			return false;
	return true;
}

void BogoSort(int A[], int size)
{
	if (size < 0)
		throw 1;
	if (size)
		while (!IsCorrect(A, size))
			Shuffle(A, size);
}

void QuickSort(int A[], int size)
{
	if (size < 0)
		throw 1;
	int i, j, left, right, center = size / 2, valueOfCenter;
	List tipaStack;
	tipaStack.PushFront(0);
	tipaStack.PushFront(size - 1);
	do
	{
		right = tipaStack[0];
		tipaStack.PopFront();
		left = tipaStack[0];
		tipaStack.PopFront();

		i = left; j = right;
		center = (i + j) / 2;
		valueOfCenter = A[center];

		do
		{
			while (A[i] < valueOfCenter)
				i++;
			while (A[j] > valueOfCenter)
				j--;
			if (i <= j)
			{
				Swap(A, size, i, j);
				i++;
				j--;
			}
		} while (i <= j);

		if (left < j)
		{
			tipaStack.PushFront(left);
			tipaStack.PushFront(j);
		}
		if (i < right)
		{
			tipaStack.PushFront(i);
			tipaStack.PushFront(right);
		}
	} while (tipaStack.GetSize());
}

void InsertionSort(int A[], int size)
{
	if (size < 0)
		throw 1;
	int i, j, key;
	for (i = 1; i < size; i++)
	{
		key = A[i];
		j = i - 1;
		while ((j >= 0) && (A[j] > key))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

void CountingSort(char A[], int size)
{
	if (size < 0)
		throw 1;
	unsigned c[255];
	unsigned j = 0;
	for (unsigned i = 0; i < 255; i++)
		c[i] = 0;

	for (unsigned i = 0; i < size; i++)
		c[A[i]] += 1;

	for (unsigned i = 0; i < size; i++)
		A[i] = 0;

	for (unsigned i = 0; i < 255; i++)
		while (c[i] != 0)
		{
			A[j] += i;
			j++;
			c[i]--;
		}
}

int main()
{
	try {
		int A[10];
		for (unsigned i = 0; i < 10; i++)
			A[i] = rand() % 20 + 1;
		time_t start = clock();

		InsertionSort(A, 10);

		time_t end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (10 values)" << endl;

		int B[100];
		for (unsigned i = 0; i < 100; i++)
			B[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(B, 100);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (100 values)" << endl;

		int C[1000];
		for (unsigned i = 0; i < 1000; i++)
			C[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(C, 1000);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (1000 values)" << endl;

		int D[10000];
		for (unsigned i = 0; i < 10000; i++)
			D[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(D, 10000);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (10000 values)" << endl;

		int E[100000];
		for (unsigned i = 0; i < 100000; i++)
			E[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(E, 100000);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (100000 values)" << endl;

		cout << endl;

		for (unsigned i = 0; i < 10; i++)
			A[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(A, 10);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (10 values)" << endl;

		for (unsigned i = 0; i < 100; i++)
			B[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(B, 100);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (100 values)" << endl;

		for (unsigned i = 0; i < 1000; i++)
			C[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(C, 1000);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (1000 values)" << endl;

		for (unsigned i = 0; i < 10000; i++)
			D[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(D, 10000);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (10000 values)" << endl;

		for (unsigned i = 0; i < 100000; i++)
			E[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(E, 100000);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (100000 values)" << endl;

		cout << endl;

		char F[10];
		for (unsigned i = 0; i < 10; i++)
			F[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(F, 10);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (10 values)" << endl;

		char G[100];
		for (unsigned i = 0; i < 100; i++)
			G[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(G, 100);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (100 values)" << endl;

		char H[1000];
		for (unsigned i = 0; i < 1000; i++)
			H[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(H, 1000);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (1000 values)" << endl;

		char I[10000];
		for (unsigned i = 0; i < 10000; i++)
			I[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(I, 10000);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (10000 values)" << endl;

		char J[100000];
		for (unsigned i = 0; i < 100000; i++)
			J[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(J, 100000);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (100000 values)" << endl;

		cout << endl;

		for (unsigned i = 0; i < 10; i++)
			A[i] = i;
		start = clock();

		BinarySearch(A, 10, 7);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (10 values)" << endl;

		for (unsigned i = 0; i < 100; i++)
			B[i] = i;
		start = clock();

		BinarySearch(B, 100, 55);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (100 values)" << endl;

		for (unsigned i = 0; i < 1000; i++)
			C[i] = i;
		start = clock();

		BinarySearch(C, 1000, 555);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (1000 values)" << endl;

		for (unsigned i = 0; i < 10000; i++)
			D[i] = i;
		start = clock();

		BinarySearch(D, 10000, 5555);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (10000 values)" << endl;

		for (unsigned i = 0; i < 100000; i++)
			E[i] = i;
		start = clock();

		BinarySearch(E, 100000, 55555);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (100000 values)" << endl;

		for (unsigned i = 0; i < 10; i++)
			A[i] = rand() % 20 + 1;
		start = clock();

		BogoSort(A, 10);
		end = clock();

		cout << endl;

		cout << "BogoSorting time: " << double(end - start) << " ms (10 values)" << endl;
	}
	catch (int ex) {
		if (ex == 1)
			cout << "\nErroneous index/size!\n";
		if (ex == 2)
			cout << "\nThe array is not ordered!\n";
	}
}