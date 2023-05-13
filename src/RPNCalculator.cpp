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

      double result = 1; // perform calculation

      operands.push(result);
    }
  }
}