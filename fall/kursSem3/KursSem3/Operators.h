#pragma once
double OperatorPlus(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(temp1 + temp2);
		return temp1 + temp2;
	}
	else if (kStack.GetSize()) return kStack.GetTop();
	else throw exception("Invalid infix expression");
}

double OperatorMinus(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(temp2 - temp1);
		return temp2 - temp1;
	}
	else if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(-temp1);
		return kStack.GetTop();
	}
	else throw exception("Invalid infix expression");
}

double OperatorMultiplication(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(temp2 * temp1);
		return temp2 * temp1;
	}
	else throw exception("Invalid infix expression");
}

double OperatorDivision(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 == 0) throw exception("You can't divide by zero!");
		else {
			kStack.Push(temp2 / temp1);
			return temp2 / temp1;
		}
	}
	else throw exception("Invalid infix expression");
}

double OperatorExponentiation(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(pow(temp2, temp1));
		return pow(temp2, temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorLog(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 < 0 || temp2 < 0)
			throw exception("Logarithm's argument and base must be positive!");
		if (temp2 == 1)
			throw exception("Logarithm's base can't be equal to one!");
		kStack.Push(log(temp1) / log(temp2));
		return log(temp1) / log(temp2);
	}
	else throw exception("Invalid infix expression");
}

double OperatorMax(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 >= temp2) {
			kStack.Push(temp1);
			return temp1;
		}
		else {
			kStack.Push(temp2);
			return temp2;
		}
	}
	else throw exception("Invalid infix expression");
}

double OperatorMin(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 <= temp2) {
			kStack.Push(temp1);
			return temp1;
		}
		else {
			kStack.Push(temp2);
			return temp2;
		}
	}
	else throw exception("Invalid infix expression");
}

double OperatorSin(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 3.14159 || temp1 == 3.14159 * 2)
		{
			kStack.PopFront();
			kStack.Push(0);
			return 0;
		}
		kStack.PopFront();
		kStack.Push(sin(temp1));
		return sin(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorCos(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 3.14159 / 2 || temp1 == 3.14159 / 2 + 3.14159)
		{
			kStack.PopFront();
			kStack.Push(0);
			return 0;
		}
		kStack.PopFront();
		kStack.Push(cos(temp1));
		return cos(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorTg(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 2 * 3.14159)
		{
			kStack.PopFront();
			kStack.Push(0);
			return 0;
		}
		if (temp1 == 3.14159 / 2)
			throw exception("tg(pi/2) doesn't exist!");
		kStack.PopFront();
		kStack.Push(tan(temp1));
		return tan(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorCtg(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 0)
			throw exception("You can't divide by zero!");
		kStack.PopFront();
		kStack.Push(1 / tan(temp1));
		return 1 / tan(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorLn(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 < 0)
			throw exception("Logarithm's argument must be positive!");
		kStack.PopFront();
		kStack.Push(log(temp1));
		return log(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorSqrt(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 < 0)
			throw exception("You cannot extract the square root of a negative number!");
		kStack.PopFront();
		kStack.Push(sqrt(temp1));
		return sqrt(temp1);
	}
	else throw exception("Invalid infix expression");
}