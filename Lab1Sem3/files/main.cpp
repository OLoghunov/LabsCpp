#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	try {
		List S;
		for (unsigned i = 1; i < 6; i++)
			S.PushBack(i);
		List N;
		for (unsigned i = 7; i < 8; i++)
			N.PushBack(i);

		S.Clear();
		N.Clear();
		cout << S.FindFirst(N);
		S.Insert(12, -5);
	}
	catch (int ex)  { cout << "\nErroneous index " << ex; }
}
