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


		BST::Iterator* I = T.CreateDftIterator();
		while (I->hasNext())
			I->next();


		BST::Iterator* J = T.CreateBftIterator();
		while (J->hasNextB())
			J->nextB();
	}
	catch (exception ex) { cout << endl << ex.what(); }
}