#include "pch.h"
#include "../Lab3Sem4/bellman_ford.h"

TEST(ford_bellman, should_work_fine)
{
	int size = 4;
	string* names = new string[size]{ "Moscow", "Saint-Petersburg", "Novosibirsk", "Samara"};
	double** values = new double* [size] {
		new double[size] {0, 20, 40, INF},
		new double[size] {10, 0, 14, 20},
		new double[size] {35, INF, 0, 8},
		new double[size] {20, INF, 13, 0}
	};
	Matrix matx1 = Matrix(size, names, values);
	

	double** values2 = new double* [size] {
		new double[size] {0, 20, 34, 40},
		new double[size] {10, 0, 14, 20},
		new double[size] {28, 48, 0, 8},
		new double[size] {20, 40, 13, 0}
	};

	Matrix matx2 = Matrix(size, names, values2);

	EXPECT_TRUE(matx1.bellman_ford() == matx2);
}

TEST(ford_bellman, exception_on_empty_matrix)
{
	Matrix mtx;
	bool exceptionThrown = false;
	try
	{
		mtx.bellman_ford();
	}
	catch (int)
	{
		exceptionThrown = true;
	}
	catch (...)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
}

TEST(ford_bellman, exception_on_negative_cicle)
{
	int size = 2;
	string* names = new string[size]{ "Moscow", "Saint-Petersburg"};
	double** values = new double* [size] {
		new double[size] {-1, -1},
		new double[size] {-1, -1},
	};
	Matrix mtx = Matrix(size, names, values);
	bool exceptionThrown = false;
	try
	{
		mtx.bellman_ford();
	}
	catch (int)
	{
		exceptionThrown = true;
	}
	catch (...)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
}