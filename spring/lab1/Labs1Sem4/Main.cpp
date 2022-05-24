#include "RBTree.h"

using namespace std;
int main() {
	try {
		RBTree<int> T;
		RBTree<int>::Iterator* J = T.CreateIterator();
		cout << "//insertion" << endl << endl;

		T.insert(1, 0);
		T.insert(5, 0);
		T.insert(2, 0);
		T.insert(4, 0);
		T.insert(6, 0);
		T.insert(7, 0);

		T.insert(7, 1);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";

		T.insert(13, 10);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";

		T.insert(12, 10);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";

		T.insert(14, 1);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct"<< endl;
		else cout << "incorrect";

		T.insert(15, 10);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct"<< endl;
		else cout << "incorrect";

		T.insert(11, 10);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";

		T.insert(25, 0);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";

		cout << endl << "//removal" << endl << endl;

		T.remove(5);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";
		T.remove(2);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";
		T.remove(4);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";
		T.remove(7);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";
		T.remove(1);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";
		T.remove(11);
		T.print();
		J = T.CreateIterator();
		if (J->checkTree()) cout << "correct" << endl;
		else cout << "incorrect";

		//T.remove(33);

		T.getKeys();
		T.getValues();

		T.clear();

	}
	catch (exception ex) {
		cout << endl << ex.what();
	}
}