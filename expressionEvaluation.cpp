#include "expressionEvaluation.hpp"
#include "Stack.hpp"

// Define the GetPrecedence for operators
int ExpressionStack::GetPrecedence(char operatorSymbol)
{
	// Give + and - a lower precedence
	if (operatorSymbol == '+' || operatorSymbol == '-')
	{
		return 1;
	}

	// Give * and / a higher precedence
	if (operatorSymbol == '*' || operatorSymbol == '/')
	{
		return 2;
	}

	// In case an unhandled symbol is provided
	return 0;
}

// Function to perform arithmetic operations
int ExpressionStack::ApplyOperation(int num1, int num2, char operatorSymbol)
{
	// Applies an operation on the numbers depending on the operator symbol
	switch (operatorSymbol)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case 'x':
		return num1 * num2;
	case '/':
		return num1 / num2;
	}

	return -1;
}

// Function that returns the value of the expression after evaluation
int ExpressionStack::EvaluateTokens(std::string tokens)
{
	// Stacks for values and operators
	Stack values, operators;

	// Ints of couting parenthesis
	int leftParenthesisCount = 0, rightParenthesisCount = 0;

	// Count number of each parenthesis type and check for valid numbers and operators
	for (int i = 0; i < tokens.size(); i++)
	{
		// Increases count of parenthesis accordingly
		if (tokens[i] == '(')
		{
			leftParenthesisCount++;
		}
		else if (tokens[i] == ')')
		{
			rightParenthesisCount++;
		}

		// Ensures only valid characters are supplied
		if (!(isdigit(tokens[i]) || tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*'
			|| tokens[i] == 'x' || tokens[i] == '/' || tokens[i] == ' ' || tokens[i] == '('
			|| tokens[i] == ')'))
		{
			return -1;
		}
	}

	// Check there are no unmatched parenthesis
	if (leftParenthesisCount != rightParenthesisCount)
	{
		return -1;
	}

	// Repeat for all tokens
	for (int i = 0; i < tokens.length(); i++)
	{
		// If the current token is a space, skip it.
		if (tokens[i] == ' ')
		{
			continue;
		}
		else if (tokens[i] == '(') // If the current token is an opening brace, Push it to operators stack
		{
			operators.Push(tokens[i]);
		}
		else if (isdigit(tokens[i])) // If the current token is a number, Push it to stack for numbers
		{
			int val = 0;

			// Account for more than one digit in number
			while (i < tokens.length() && isdigit(tokens[i]))
			{
				val = (val * 10) + (tokens[i] - '0');
				i++;
			}

			values.Push(val);

			// Corrects the for loop offset
			i--;
		}
		else if (tokens[i] == ')') // Closing brace encountered, solve the entire contents of the brace
		{
			while (!operators.IsEmpty() && operators.Peek() != '(')
			{
				int num2 = values.Peek();
				values.Pop();

				int num1 = values.Peek();
				values.Pop();

				char op = operators.Peek();
				operators.Pop();

				values.Push(ApplyOperation(num1, num2, op));
			}

			// Pop opening brace
			if (!operators.IsEmpty())
			{
				operators.Pop();
			}
		}
		else // Current token is an operator
		{
			// Apply operator on Peek of operators to Peek two elements in values stack
			while (!operators.IsEmpty() && GetPrecedence(operators.Peek()) >= GetPrecedence(tokens[i]))
			{
				int num2 = values.Peek();
				values.Pop();

				int num1 = values.Peek();
				values.Pop();

				char op = operators.Peek();
				operators.Pop();

				values.Push(ApplyOperation(num1, num2, op));
			}

			// Push current token to operators
			operators.Push(tokens[i]);
		}
	}

	// Apply remaining operators to remaining values.
	while (!operators.IsEmpty()) {
		int num2 = values.Peek();
		values.Pop();

		int num1 = values.Peek();
		values.Pop();

		char op = operators.Peek();
		operators.Pop();

		values.Push(ApplyOperation(num1, num2, op));
	}

	// Top of values contains result, return it
	return values.Peek();
}