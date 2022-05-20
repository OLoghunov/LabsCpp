#include "pch.h"
#include"../KursSem4/edmonds_karp.h"

TEST(edmonds_karp, should_work_fine1) {
	int size = 4;
	string* names = new string[size]{ "S", "A", "B", "T" };
	double** values = new double* [size] {
		new double[size] {0, 1, 1, 0},
			new double[size] {0, 0, 0, 1},
			new double[size] {0, 0, 0, 1},
			new double[size] {0, 0, 0, 0}
	};
	Matrix* mtx = new Matrix(size, names, values);
	mtx->visit = new bool[size];
	for (int i = 0; i < 4; i++)
		mtx->visit[i] = false;
	mtx->sink = 3;
	mtx->source = 0; 

	EXPECT_TRUE(edmonds_karp(mtx) == 2);
}

TEST(edmonds_karp, should_work_fine2) {
	int size = 7;
	string* names = new string[size]{ "S", "Q", "K", "P", "R", "T", "L" };
	double** values = new double* [size] {
		new double[size] {0, 1, 1, 1, 0, 0, 0},
			new double[size] {0, 0, 1, 0, 1, 0, 0},
			new double[size] {0, 0, 0, 0, 0, 1, 0},
			new double[size] {0, 0, 0, 0, 1, 0, 1},
			new double[size] {0, 0, 0, 0, 0, 1, 0},
			new double[size] {0, 0, 0, 0, 0, 0, 0},
			new double[size] {0, 0, 0, 0, 0, 1, 0}
	};
	Matrix* mtx = new Matrix(size, names, values);
	mtx->visit = new bool[size];
	for (int i = 0; i < 7; i++)
		mtx->visit[i] = false;
	mtx->sink = 5;
	mtx->source = 0;

	EXPECT_TRUE(edmonds_karp(mtx) == 3);
}

TEST(edmonds_karp, exception_on_empty_matrix)
{
	Matrix *mtx = new Matrix;
	bool exceptionThrown = false;
	try
	{
		edmonds_karp(mtx);
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