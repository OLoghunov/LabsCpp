#include "BinarySearchTree.h"
#include <ctime>
using namespace std;

int main()
{
	try {
		BST T;
		T.Insert(7);
		T.Insert(3);
		T.Insert(10);
		T.Insert(2);
		T.Insert(5);
		T.Insert(10);
		T.Insert(100);
		/*for (unsigned i = 25; i > 1; i--)
			T.Insert(i);*/

		clock_t start = clock();

		cout << endl << "DFT starts..." << endl;

		BST::Iterator* I = T.CreateDftIterator();
		while (I->hasNext())
			cout << I->next() << ' ';
		clock_t end = clock();

		double msec = double(end - start);
		cout << endl << "Execution time: " << msec << " ms" << endl << endl;

		start = clock();

		cout << "BFT starts..." << endl;
		BST::Iterator* J = T.CreateBftIterator();
		while (J->hasNextB())
			cout << J->nextB() << ' ';
		end = clock();

		msec = double(end - start);
		cout << endl << "Execution time: " << msec << " ms" << endl;
	}
	catch (int ex) { cout << "\nYou cannot delete a non-existent element!\n"; }
}