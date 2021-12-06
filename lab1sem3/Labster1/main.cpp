#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List S;
	for (unsigned i = 1; i < 4; i++)
		S.PushBack(i);
	try {
		List S;
		for (unsigned i = 1; i < 6; i++)
			S.PushBack(i);
		List N;
		for (unsigned i = 2; i < 5; i++)
			N.PushBack(i);
		cout << "S: " << S << endl << "N: " << N << endl;

		cout << "Index of the first occurrence of list N in list S: " << S.FindFirst(N) << endl << endl;
		S.Clear();
		N.Clear();
		for (unsigned i = 1; i < 6; i++)
			S.PushBack(i);
		for (unsigned i = 4; i < 5; i++)
			N.PushBack(i);
		cout << "S: " << S << endl << "N: " << N << endl;

		cout << "Index of the first occurrence of list N in list S: " << S.FindFirst(N) << endl << endl;
		S.Clear();
		N.Clear();
		for (unsigned i = 1; i < 6; i++)
			S.PushBack(i);
		for (unsigned i = 8; i > 5; i--)
			N.PushBack(i);
		cout << "S: " << S << endl << "N: " << N << endl;

		cout << "Index of the first occurrence of list N in list S: " << S.FindFirst(N) << endl << endl;
		S.Clear();
		N.Clear();
		cout << "S: " << S << endl << "N: " << N << endl;

		cout << "Index of the first occurrence of list N in list S: " << S.FindFirst(N) << endl << endl;
	}
	catch (int ex)  { cout << "\nErroneous index " << ex; }
}