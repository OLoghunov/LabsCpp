#include "edmonds_karp.h"

int main()
{
	ifstream f;
	f.open("graph.txt");
	Matrix matx;
	f >> matx;
	cout << "Matrix initialization..." << endl << matx << endl;
	cout << "Applying Edmonds-Karp algorythm..." << endl << endl;
	cout << "Maximum flow in this graph is : " << edmonds_karp(&matx) << endl;
}