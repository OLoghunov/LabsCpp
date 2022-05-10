#include "pch.h"
#include "CppUnitTest.h"
#include "..\KursSem3\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestKursSem3
{
	TEST_CLASS(UnitTestKursSem3)
	{
	public:
		
		TEST_METHOD(TestMethodIsOperator)
		{
			string str = "+";
			Assert::IsTrue(IsOperator(str));
			str = "-";
			Assert::IsTrue(IsOperator(str));
			str = "*";
			Assert::IsTrue(IsOperator(str));
			str = "/";
			Assert::IsTrue(IsOperator(str));
			str = "^";
			Assert::IsTrue(IsOperator(str));
			str = "sin";
			Assert::IsTrue(IsOperator(str));
			str = "cos";
			Assert::IsTrue(IsOperator(str));
			str = "tg";
			Assert::IsTrue(IsOperator(str));
			str = "ctg";
			Assert::IsTrue(IsOperator(str));
			str = "log";
			Assert::IsTrue(IsOperator(str));
			str = "ln";
			Assert::IsTrue(IsOperator(str));
			str = "min";
			Assert::IsTrue(IsOperator(str));
			str = "max";
			Assert::IsTrue(IsOperator(str));
			str = "sqrt";
			Assert::IsTrue(IsOperator(str));
			str = "ss";
			Assert::IsTrue(!IsOperator(str));
			str = "";
			Assert::IsTrue(!IsOperator(str));
		}

		TEST_METHOD(TestMethodIsNumber)
		{
			string str = "2";
			Assert::IsTrue(IsNumber(str));
			str = "2.22";
			Assert::IsTrue(IsNumber(str));
			str = "0.22";
			Assert::IsTrue(IsNumber(str));
			str = "pi";
			Assert::IsTrue(IsNumber(str));
			str = "e";
			Assert::IsTrue(IsNumber(str));
			str = "sin";
			Assert::IsTrue(!IsNumber(str));
		}

		TEST_METHOD(TestOperatorPlus)
		{
			Stack<double> kStack;
			kStack.Push(22);
			Assert::IsTrue(OperatorPlus(kStack) == 22);
			kStack.Push(22);
			Assert::IsTrue(OperatorPlus(kStack) == 44);
		}

		TEST_METHOD(TestOperatorMinus)
		{
			Stack<double> kStack;
			kStack.Push(22);
			Assert::IsTrue(OperatorMinus(kStack) == -22);
			kStack.Push(22);
			Assert::IsTrue(OperatorMinus(kStack) == -44);
		}

		TEST_METHOD(TestOperatorMultiplication)
		{
			Stack<double> kStack;
			kStack.Push(22);
			try {
				OperatorMultiplication(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(2);
			Assert::IsTrue(OperatorMultiplication(kStack) == 44);
		}

		TEST_METHOD(TestOperatorDivision)
		{
			Stack<double> kStack;
			kStack.Push(22);
			kStack.Push(2);
			Assert::IsTrue(OperatorDivision(kStack) == 11);
			try {
				OperatorDivision(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(0);
			try {
				OperatorDivision(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
		}

		TEST_METHOD(TestOperatorExponentiation)
		{
			Stack<double> kStack;
			kStack.Push(2);
			try {
				OperatorExponentiation(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(2);
			Assert::IsTrue(OperatorExponentiation(kStack) == 4);
		}

		TEST_METHOD(TestOperatorLog)
		{
			Stack<double> kStack;
			kStack.Push(2);
			try {
				OperatorLog(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(8);
			Assert::IsTrue(OperatorLog(kStack) == 3);
		}

		TEST_METHOD(TestOperatorMax)
		{
			Stack<double> kStack;
			kStack.Push(2);
			try {
				OperatorMax(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(8);
			Assert::IsTrue(OperatorMax(kStack) == 8);
		}

		TEST_METHOD(TestOperatorMin)
		{
			Stack<double> kStack;
			kStack.Push(2);
			try {
				OperatorMin(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(8);
			Assert::IsTrue(OperatorMin(kStack) == 2);
		}

		TEST_METHOD(TestOperatorSin)
		{
			Stack<double> kStack;
			try {
				OperatorSin(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(0);
			Assert::IsTrue(OperatorSin(kStack) == 0);
		}

		TEST_METHOD(TestOperatorCos)
		{
			Stack<double> kStack;
			try {
				OperatorCos(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(0);
			Assert::IsTrue(OperatorCos(kStack) == 1);
		}

		TEST_METHOD(TestOperatorTg)
		{
			Stack<double> kStack;
			try {
				OperatorTg(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(0);
			Assert::IsTrue(OperatorTg(kStack) == 0);
		}

		TEST_METHOD(TestOperatorCtg)
		{
			Stack<double> kStack;
			try {
				OperatorCtg(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			try {
				kStack.Push(0);
				OperatorCtg(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
		}

		TEST_METHOD(TestOperatorLn)
		{
			Stack<double> kStack;
			try {
				OperatorLn(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			kStack.Push(1);
			Assert::IsTrue(OperatorLn(kStack) == 0);
		}

		TEST_METHOD(TestOperatorSqrt)
		{
			Stack<double> kStack;
			kStack.Push(4);
			Assert::IsTrue(OperatorSqrt(kStack) == 2);
			kStack.PopFront();
			try {
				OperatorSqrt(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			try {
				kStack.Push(-2);
				OperatorSqrt(kStack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
		}

		TEST_METHOD(TestMethodPrecedence)
		{
			string str = "+";
			Assert::IsTrue(Precedence(str) == 1);
			str = "-";
			Assert::IsTrue(Precedence(str) == 1);
			str = "*";
			Assert::IsTrue(Precedence(str) == 2);
			str = "/";
			Assert::IsTrue(Precedence(str) == 2);
			str = "sin";
			Assert::IsTrue(Precedence(str) == 3);
			str = "cos";
			Assert::IsTrue(Precedence(str) == 3);
			str = "tg";
			Assert::IsTrue(Precedence(str) == 3);
			str = "ctg";
			Assert::IsTrue(Precedence(str) == 3);
			str = "^";
			Assert::IsTrue(Precedence(str) == 3);
			str = "log";
			Assert::IsTrue(Precedence(str) == 3);
			str = "sqrt";
			Assert::IsTrue(Precedence(str) == 3);
			str = "ln";
			Assert::IsTrue(Precedence(str) == 3);
			str = "min";
			Assert::IsTrue(Precedence(str) == 3);
			str = "max";
			Assert::IsTrue(Precedence(str) == 3);
		}

		TEST_METHOD(TestMethodInfToPost)
		{
			string str = "2+2";
			Assert::IsTrue(InfToPost(str) == "2 2 + ");
			str = "(3+pi)/3";
			Assert::IsTrue(InfToPost(str) == "3 pi + 3 / ");
			str = "(3*pi-e)/((pi^e-11)*5)";
			Assert::IsTrue(InfToPost(str) == "3 pi * e - pi e ^ 11 - 5 * / ");
			str = "-sin(-cos(25))/((2 + 2)^(4 / 2) * (pi - e)^(e - pi))";
			Assert::IsTrue(InfToPost(str) == "25 cos - sin 2 2 + 4 2 / ^ pi e - e pi - ^ * / - ");
			try {
				str = "5-";
				InfToPost(str);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			try {
				str = "()";
				InfToPost(str);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
			try {
				str = "(-";
				InfToPost(str);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
		}

		TEST_METHOD(TestMethodCalculatePostfix)
		{
			string str = "2 2 + ";
			Assert::IsTrue(CalculatePostfix(str) == 4);
			str = "3 5 - 4 / ";
			Assert::IsTrue(CalculatePostfix(str) == -0.5);
			str = "9 2 ^ sqrt 9 - 3 + 3 5 min - ";
			Assert::IsTrue(CalculatePostfix(str) == 0);
		}
	};
}