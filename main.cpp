#include "expressionEvaluation.hpp"

int main()
{
	// Create an expression stack object
	ExpressionStack expressionStack;

	// Display a title to the console
	std::cout << "Expression Evaluation" << std::endl;
	
	// Calculate different expressions
	std::cout << "10 + 2 * 6 = " << expressionStack.EvaluateTokens("10 + 2 * 6") << std::endl;
	std::cout << "10 + 2 x 6 = " << expressionStack.EvaluateTokens("10 + 2 x 6") << std::endl;
	std::cout << "l0 + 2 * 6 = " << expressionStack.EvaluateTokens("l0 + 2 * 6") << std::endl;
	std::cout << "100 * 2 + 12 = " << expressionStack.EvaluateTokens("100 * 2 + 12") << std::endl;
	std::cout << "100 * (2 + 12) = " << expressionStack.EvaluateTokens("100 * (2 + 12)") << std::endl;
	std::cout << "100 * ((2 + 12) = " << expressionStack.EvaluateTokens("100 * ((2 + 12)") << std::endl;
	std::cout << "100 * (2 + 12) / 14 = " << expressionStack.EvaluateTokens("100 * (2 + 12) / 14") << std::endl;

	return 0;
}

/* TO-DO
* - Add support for multiple sets of parenthesis.
* - Handle float inputs.
*/