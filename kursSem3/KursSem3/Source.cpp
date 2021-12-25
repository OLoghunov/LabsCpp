#include "Stack.cpp"
#include "Operators.h"

using namespace std;

bool IsOperator(string inp)
{
	string variations[] = { "-","+","*","/","^","sin","cos","tg","ln","ctg","sqrt","log","max","min" };
	for (int i = 0; i < 14; i++)
		if (inp == variations[i])
			return true;
	return false;
}

bool IsNumber(char letter)
{
	if ((letter >= '0' && letter <= '9') || letter == '.')
		return true;
	else return false;
}

bool IsNumber(string letter)
{
	if ((letter >= "0" && letter <= "9") || letter == "." || letter == "pi" || letter == "e")
		return true;
	else return false;
}

int Precedence(string letter)
{
	if (letter == "^" || letter == "sin" || letter == "cos" || letter == "tg" || letter == "ln" || letter == "ctg" 
		|| letter == "sqrt" || letter == "log" || letter == "max" || letter == "min")
		return 3;
	else if (letter == "*" || letter == "/")
		return 2;
	else if (letter == "+" || letter == "-")
		return 1;
	else return -1;
}

string InfToPost(string infix)
{
	Stack<string> kStack;
	string postfix, temp;
	unsigned u = 0;
	bool flag = 0;

	for (unsigned i = 0; i < infix.length(); i++)
	{
		if (infix[i] == ' ')
			continue;
		u = 0; 
		temp = "";
		flag = 0;
		while (u < 2)
		{
			temp += infix[i + u];
			if (IsNumber(temp))
			{
				flag = 1;
				break;
			}
			u++;
		}

		if (flag)
		{ 
			if (temp != "pi" && temp != "e") {
				do
				{
					postfix += infix[i];
					i++;
				} while ((IsNumber(infix[i])) && i < infix.length());
				postfix += ' ';
				i--;
			}
			else {
				postfix += temp;
				postfix += ' ';
				i += u;
			}
		}

		else if (infix[i] == '(')
			kStack.Push(string(1, infix[i]));

		else if (infix[i] == ')')
		{
			while (kStack.GetTop() != "(" && (kStack.GetSize()))
			{
				postfix += kStack.GetTop();
				postfix += ' ';
				kStack.PopFront();
			}
			kStack.PopFront();
		}	

		else
		{
			u = 0;
			temp = "";
			flag = 0;
			while (u < 4) {
				temp += infix[i + u];
				if (IsOperator(temp))
				{
					flag = 1;
					break;
				}
				u++;
			}
			if (flag)
			{
				if (temp ==  "-")
				{
					unsigned y;
					for (y = i + 1; y < infix.length(); y++)
						if (infix[y] != ' ')
							break;
					if (y == infix.length())
						throw exception("Invalid infix expression");
				}
				if (!kStack.GetSize())
					kStack.Push(temp);
				else
				{
					if (Precedence(temp) > Precedence(kStack.GetTop()))
						kStack.Push(temp);
					else if ((Precedence(temp) == Precedence(kStack.GetTop())) && (temp == "^" || temp == "sin" ||
						temp == "cos" || temp == "tg" || temp == "ln" || temp == "ctg" || temp == "sqrt" || temp == "log" ||
						temp == "max" || temp == "min"))
						kStack.Push(temp);
					else
					{
						while ((kStack.GetSize()) && (Precedence(temp)) <= Precedence(kStack.GetTop()))
						{
							postfix += kStack.GetTop();
							postfix += ' ';
							kStack.PopFront();
						}
						kStack.Push(temp);
					}
				}
				flag = 0;
				i += u;
			}
			else throw exception("Invalid infix expression", i);
		}
	}
	while (kStack.GetSize())
	{
		postfix += kStack.GetTop();
		postfix += ' ';
		kStack.PopFront();
	}
	return postfix;
}

double CalculatePostfix(string postfix)
{
	bool flag = 0;
	Stack<double> kStack;
	string temp = "";
	for (unsigned i = 0; i < postfix.length(); i++)
	{
		temp = "";
		flag = 0;
		while (postfix[i] != ' ')
		{
			temp += postfix[i];
			if (IsNumber(temp))
				flag = 1;
			i++;
		}

		if (flag)
		{
			if (temp != "pi" && temp != "e")
				kStack.Push(atof(temp.c_str()));
			else if (temp == "pi")
				kStack.Push(3.14159);
			else if (temp == "e")
				kStack.Push(2.71828);
			flag = 0;
			temp = "";
		}

		else if(IsOperator(temp))
		{
			if (temp == "+")
				OperatorPlus(kStack);
			else if (temp == "-")
				OperatorMinus(kStack);
			else if (temp == "*")
				OperatorMultiplication(kStack);
			else if (temp == "/")
				OperatorDivision(kStack);
			else if (temp == "^")
				OperatorExponentiation(kStack);
			else if (temp == "log")
				OperatorLog(kStack);
			else if (temp == "max")
				OperatorMax(kStack);
			else if (temp == "min")
				OperatorMin(kStack);
			else if (temp == "sin")
				OperatorSin(kStack);
			else if (temp == "cos")
				OperatorCos(kStack);
			else if (temp == "tg")
				OperatorTg(kStack);
			else if (temp == "ctg")
				OperatorCtg(kStack);
			else if (temp == "ln")
				OperatorLn(kStack);
			else if (temp == "sqrt")
				OperatorSqrt(kStack);
		}
	}
	double solution = kStack.GetTop();
	kStack.PopFront();
	return solution;
}

int main()
{
	try {
		string infix, postfix;

		cout << "Enter an infix expression:" << endl;
		getline(cin, infix);

		int check = 0;
		for (unsigned i = 0; i < infix.length(); i++)
		{
			if (infix[i] == '(')
				check++;
			if (infix[i] == ')')
				check--;
			if (check < 0)
				throw exception("Invalid infix expression");
		}

		if (check)
			throw exception("Invalid infix expression");

		postfix = InfToPost(infix);

		if (postfix != "")
			cout << endl << "Postfix expression: " << endl << postfix;
		else throw exception("Invalid infix expression");

		double solution = CalculatePostfix(postfix);
		cout << endl << endl << "Solution = " << solution << endl;
	}
	catch (exception ex) { cout << endl << endl << ex.what() << endl; }
}