#include "structures.h"
#include <fstream>
#include <iomanip>

#define INF numeric_limits<int>::max()

using namespace std;
const string NA = "N/A";

class Matrix
{
	int size;
	string* names;
	double** values;

	void drawThickLine(ostream& str, Matrix& matrix, int maxwidth)
	{
		str << "==";
		for (int i = 0; i < maxwidth; i++) str << '=';
		str << "====";
		for (int i = 0; i < matrix.size; i++)
		{
			const size_t len = matrix.names[i].length();
			for (int j = 0; j < len; j++)
				str << '=';
			str << "==" << (i == matrix.size - 1 ? '\n' : '=');
		}
	}

public:
	Matrix(int size = 0, string* names = nullptr, double** values = nullptr)
	{
		this->values = values;
		this->names = names;
		this->size = size;
	}

	~Matrix()
	{
		if (values != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] values[i];
			}
			delete[] values;
		}
	}

	Matrix& bellman_ford()
	{
		if (size == 0) throw exception("Empty matrix!");
		Matrix* newMatrix = new Matrix();
		newMatrix->size = size;
		newMatrix->names = names;
		newMatrix->values = new double* [size];

		for (int v = 0; v < size; v++)
		{
			double* d = new double[size];
			for (int i = 0; i < size; i++)
				d[i] = (i == v ? 0 : INF);

			for (int step = 0; step < size; step++)
				for (int i = 0; i < size; i++)
					for (int j = 0; j < size; j++)
						if (i != j && values[i][j] < INF && d[i] + values[i][j] < d[j])
							if (step == size - 1) throw exception("Graph has negative cycles");
							else d[j] = d[i] + values[i][j];

			newMatrix->values[v] = d;
		}
		return *newMatrix;
	}

	friend ifstream& operator>>(ifstream& str, Matrix& matrix)
	{
		string city1, city2;
		double value1, value2;
		List<string> tempNames;
		while (!str.eof())
		{
			string temp;
			str >> city1 >> city2 >> value1 >> value2;
			if (tempNames.Find(city1) < 0) tempNames.PushBack(city1);
			if (tempNames.Find(city2) < 0) tempNames.PushBack(city2);
			if (value1 == 0)
			{
				str.clear();
				str >> temp >> value2;
			}
			if (value2 == 0)
			{
				str.clear();
				if (temp == NA) throw invalid_argument("Wrong input");
				str >> temp;
			}
		}
		matrix.size = tempNames.GetSize();
		matrix.names = new string[matrix.size];
		matrix.values = new double* [matrix.size];
		for (int i = 0; i < matrix.size; i++)
		{
			matrix.names[i] = tempNames.GetData();
			tempNames.PopFront();
			matrix.values[i] = new double[matrix.size];
			for (int j = 0; j < matrix.size; j++)
				matrix.values[i][j] = (i == j ? 0 : INF);
		}

		str.seekg(ios::beg);
		while (!str.eof())
		{
			string temp;
			str >> city1 >> city2 >> value1 >> value2;
			if (value1 == 0)
			{
				str.clear();
				str >> temp >> value2;
				value1 = INF;
			}
			if (value2 == 0)
			{
				str.clear();
				str >> temp;
				value2 = INF;
			}

			int i = 0, j = 0, k;
			for (k = 0; k < matrix.size; k++)
			{
				if (matrix.names[k] == city1) i = k;
				if (matrix.names[k] == city2) j = k;
			}
			matrix.values[i][j] = value1;
			matrix.values[j][i] = value2;
		}
		return str;
	}

	friend ostream& operator<<(ostream& str, Matrix& matrix)
	{
		int maxwidth = 0;
		for (int i = 0; i < matrix.size; i++)
			if (matrix.names[i].length() > maxwidth) maxwidth = matrix.names[i].length();
		str << "  ";
		for (int i = 0; i < maxwidth; i++)
			str << ' ';
		str << " || ";
		for (int i = 0; i < matrix.size; i++)
			str << setw(matrix.names[i].length()) << left << matrix.names[i] << "   ";
		str << "\n";
		matrix.drawThickLine(str, matrix, maxwidth);
		for (int i = 0; i < matrix.size; i++)
		{
			str << "  " << setw(maxwidth) << right << matrix.names[i] << " || ";
			for (int j = 0; j < matrix.size; j++)
			{
				str << setw(matrix.names[j].length()) << left;
				if (matrix.values[i][j] != INF) str << matrix.values[i][j] << "   ";
				else str << "inf" << "   ";
			}
			str << "\n";
		}
		return str;
	}

	friend bool operator==(Matrix& mtx1, Matrix& mtx2)
	{
		if (mtx1.size != mtx2.size) return false;
		for (size_t i = 0; i < mtx1.size; i++) if (mtx1.names[i] != mtx2.names[i]) return false;
		for (size_t i = 0; i < mtx1.size; i++)
			for (size_t j = 0; j < mtx1.size; j++)
				if (mtx1.values[i][j] != mtx2.values[i][j]) 
					return false;
		return true;
	}
};
