#include "RPNCalculator.h"

double RPNCalculator::calculate(const std::string &rpnExpression)
{
  Stack<double> operands;
  std::istringstream iss(rpnExpression);
  std::string token;

  while (iss >> token)
  {
    if (RPNUtils::isNumeric(token))
    {
      operands.push(std::stod(token));
    }
    else if (OperatorManager::isOperator(token))
    {
      double operand2 = operands.top();
      operands.pop();
      double operand1 = operands.top();
      operands.pop();

      double result = performOperation(token, operand1, operand2);

      operands.push(result);
    }
  }

  return operands.top();
}

double RPNCalculator::performOperation(const std::string &token, double operand1, double operand2)
{
  if (token == "+")
  {
    return operand1 + operand2;
  }
  else if (token == "-")
  {
    return operand1 - operand2;
  }
  else if (token == "*")
  {
    return operand1 * operand2;
  }
  else if (token == "/")
  {
    return operand1 / operand2;
  }
  else if (token == "^")
  {
    return std::pow(operand1, operand2);
  }

  return 0.0; // Invalid operator
}