#include <iostream>
#include "List.h"
#include <stdexcept>

using namespace std;

int main()
{
	try {
		List listS;
		for (unsigned i = 1; i < 6; i++)
			listS.PushBack(i);
		List listN;
		for (unsigned i = 2; i < 5; i++)
			listN.PushBack(i);
		cout << "listS: " << listS << endl << "listN: " << listN << endl;

		cout << "Index of the first occurrence of list listN in list listS: " << listS.FindFirst(listN) << endl << endl;
		listS.Clear();
		listN.Clear();
		for (unsigned i = 1; i < 6; i++)
			listS.PushBack(i);
		for (unsigned i = 4; i < 5; i++)
			listN.PushBack(i);
		cout << "listS: " << listS << endl << "listN: " << listN << endl;

		cout << "Index of the first occurrence of list listN in list listS: " << listS.FindFirst(listN) << endl << endl;
		listS.Clear();
		listN.Clear();
		for (unsigned i = 1; i < 6; i++)
			listS.PushBack(i);
		for (unsigned i = 8; i > 5; i--)
			listN.PushBack(i);
		cout << "listS: " << listS << endl << "listN: " << listN << endl;

		cout << "Index of the first occurrence of list listN in list listS: " << listS.FindFirst(listN) << endl << endl;
		listS.Clear();
		listN.Clear();
		cout << "listS: " << listS << endl << "listN: " << listN << endl;

		cout << "Index of the first occurrence of list listN in list listS: " << listS.FindFirst(listN) << endl << endl;
	}
	catch (const out_of_range& ex)  { cout << "\nErroneous index, " << ex.what(); }
}