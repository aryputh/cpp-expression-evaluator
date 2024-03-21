#include <string>
#include <iostream>

class ExpressionStack
{
public:
	int GetPrecedence(char operatorSymbol);
	int ApplyOperation(int num1, int num2, char operatorSymbol);
	int EvaluateTokens(std::string tokens);
};