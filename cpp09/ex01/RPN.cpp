#include "RPN.hpp"

static bool isOperator(char &c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

void RPN(std::string input)
{
	std::stack<int> stack;
	try
	{
		for (std::string::iterator it = input.begin(); it != input.end();)
		{
			if (std::isdigit(*it))
			{
				stack.push(*it - '0');
			}
			else if (isOperator(*it))
			{
				if (stack.size() < 2)
					throw std::logic_error("not enough element for operation");
				int a = stack.top();
				stack.pop();
				int b = stack.top();
				stack.pop();
				if (*it == '+')
					stack.push(b + a);
				else if (*it == '-')
					stack.push(b - a);
				else if (*it == '/')
					stack.push(b / a);
				else if (*it == '*')
					stack.push(b * a);
			}
			else
				throw std::logic_error("invalid character in input");
			if (*(++it) != ' ' && it != input.end())
				throw std::logic_error("invalid input");
			while (*it == ' ' && it != input.end())
				it++;
		}
		std::cout << stack.top() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}