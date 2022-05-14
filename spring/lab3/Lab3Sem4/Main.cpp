#include "bellman_ford.h"

int main()
{
    Matrix matx;
    ifstream f;
    cout << "////Bellman_Ford algorith////" << endl << endl;
    f.open("cities_list.txt");

    f >> matx;

    cout << "Matrix initialization..." << endl << matx << endl;
    try {
        cout << "Applying Bellman-Ford algorithm..." << endl << matx.bellman_ford() << endl;
    }
    catch (exception ex) { cout << endl << ex.what() << endl; }

    f.close();
}