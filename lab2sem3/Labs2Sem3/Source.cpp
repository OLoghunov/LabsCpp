#include "List.h"
#include <ctime>

using namespace std;
bool IsCorrect(int Array[], int size)
{
	for (unsigned i = 0; i < size - 1; i++)
		if (Array[i + 1] < Array[i])
			return false;
	return true;
}

int BinarySearch(int Array[], int size, int x)
{
	if (size < 0)
		throw 1;
	if (!IsCorrect(Array, size))
		throw 2;
	unsigned currentCenter = size / 2;
	unsigned currentSize = size;
	while (currentSize > 0)
	{
		if (x == Array[currentCenter])
			return currentCenter;
		else
			if (x < Array[currentCenter])
			{
				currentSize = currentSize / 2;
				if (currentSize != 1)
					currentCenter -= currentSize / 2 + 1;
				else currentCenter -= 1;
			}
			else
				if (x > Array[currentCenter])
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

void Swap(int Array[], int size, int index1, int index2)
{
	if (size < 0 || index1 < 0 || index1 >= size || index2 < 0 || index2 >= size)
		throw 1;
	int temp = 0;
	temp = Array[index1];
	Array[index1] = Array[index2];
	Array[index2] = temp;
}

void Shuffle(int Array[], int size)
{
	if (size < 0)
		throw 1;
	for (unsigned i = 0; i < size; i++)
		Swap(Array, size, i, rand() % size);
}

bool IsCorrect(char Array[], int size)
{
	if (size < 0)
		throw 1;
	for (unsigned i = 0; i < size - 1; i++)
		if (Array[i + 1] < Array[i])
			return false;
	return true;
}

void BogoSort(int Array[], int size)
{
	if (size < 0)
		throw 1;
	if (size)
		while (!IsCorrect(Array, size))
			Shuffle(Array, size);
}

void QuickSort(int Array[], int size)
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
		valueOfCenter = Array[center];

		do
		{
			while (Array[i] < valueOfCenter)
				i++;
			while (Array[j] > valueOfCenter)
				j--;
			if (i <= j)
			{
				Swap(Array, size, i, j);
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

void InsertionSort(int Array[], int size)
{
	if (size < 0)
		throw 1;
	int i, j, key;
	for (i = 1; i < size; i++)
	{
		key = Array[i];
		j = i - 1;
		while ((j >= 0) && (Array[j] > key))
		{
			Array[j + 1] = Array[j];
			j--;
		}
		Array[j + 1] = key;
	}
}

void CountingSort(char Array[], int size)
{
	if (size < 0)
		throw 1;
	unsigned c[255];
	unsigned j = 0;
	for (unsigned i = 0; i < 255; i++)
		c[i] = 0;

	for (unsigned i = 0; i < size; i++)
		c[Array[i]] += 1;

	for (unsigned i = 0; i < size; i++)
		Array[i] = 0;

	for (unsigned i = 0; i < 255; i++)
		while (c[i] != 0)
		{
			Array[j] += i;
			j++;
			c[i]--;
		}
}

int main()
{
	try {
		int Array[10];
		for (unsigned i = 0; i < 10; i++)
			Array[i] = rand() % 20 + 1;
		time_t start = clock();

		InsertionSort(Array, 10);

		time_t end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (10 values)" << endl;

		int ArrayB[100];
		for (unsigned i = 0; i < 100; i++)
			ArrayB[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(ArrayB, 100);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (100 values)" << endl;

		int ArrayC[1000];
		for (unsigned i = 0; i < 1000; i++)
			ArrayC[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(ArrayC, 1000);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (1000 values)" << endl;

		int ArrayD[10000];
		for (unsigned i = 0; i < 10000; i++)
			ArrayD[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(ArrayD, 10000);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (10000 values)" << endl;

		int ArrayE[100000];
		for (unsigned i = 0; i < 100000; i++)
			ArrayE[i] = rand() % 20 + 1;
		start = clock();

		InsertionSort(ArrayE, 100000);

		end = clock();

		cout << "Insertion sorting time: " << double(end - start) << " ms (100000 values)" << endl;

		cout << endl;

		for (unsigned i = 0; i < 10; i++)
			Array[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(Array, 10);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (10 values)" << endl;

		for (unsigned i = 0; i < 100; i++)
			ArrayB[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(ArrayB, 100);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (100 values)" << endl;

		for (unsigned i = 0; i < 1000; i++)
			ArrayC[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(ArrayC, 1000);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (1000 values)" << endl;

		for (unsigned i = 0; i < 10000; i++)
			ArrayD[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(ArrayD, 10000);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (10000 values)" << endl;

		for (unsigned i = 0; i < 100000; i++)
			ArrayE[i] = rand() % 20 + 1;
		start = clock();

		QuickSort(ArrayE, 100000);

		end = clock();

		cout << "Quick sorting time: " << double(end - start) << " ms (100000 values)" << endl;

		cout << endl;

		char ArrayF[10];
		for (unsigned i = 0; i < 10; i++)
			ArrayF[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(ArrayF, 10);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (10 values)" << endl;

		char ArrayG[100];
		for (unsigned i = 0; i < 100; i++)
			ArrayG[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(ArrayG, 100);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (100 values)" << endl;

		char ArrayH[1000];
		for (unsigned i = 0; i < 1000; i++)
			ArrayH[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(ArrayH, 1000);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (1000 values)" << endl;

		char ArrayI[10000];
		for (unsigned i = 0; i < 10000; i++)
			ArrayI[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(ArrayI, 10000);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (10000 values)" << endl;

		char ArrayJ[100000];
		for (unsigned i = 0; i < 100000; i++)
			ArrayJ[i] = rand() % 20 + 1;
		start = clock();

		CountingSort(ArrayJ, 100000);

		end = clock();

		cout << "Counting sorting time: " << double(end - start) << " ms (100000 values)" << endl;

		cout << endl;

		for (unsigned i = 0; i < 10; i++)
			Array[i] = i;
		start = clock();

		BinarySearch(Array, 10, 7);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (10 values)" << endl;

		for (unsigned i = 0; i < 100; i++)
			ArrayB[i] = i;
		start = clock();

		BinarySearch(ArrayB, 100, 55);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (100 values)" << endl;

		for (unsigned i = 0; i < 1000; i++)
			ArrayC[i] = i;
		start = clock();

		BinarySearch(ArrayC, 1000, 555);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (1000 values)" << endl;

		for (unsigned i = 0; i < 10000; i++)
			ArrayD[i] = i;
		start = clock();

		BinarySearch(ArrayD, 10000, 5555);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (10000 values)" << endl;

		for (unsigned i = 0; i < 100000; i++)
			ArrayE[i] = i;
		start = clock();

		BinarySearch(ArrayE, 100000, 55555);

		end = clock();

		cout << "Binary search time: " << double(end - start) << " ms (100000 values)" << endl;

		for (unsigned i = 0; i < 10; i++)
			Array[i] = rand() % 20 + 1;
		start = clock();

		BogoSort(Array, 10);
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