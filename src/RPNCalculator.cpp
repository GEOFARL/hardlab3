#include "RPNCalculator.h"

double RPNCalculator::calculate(const std::string &rpnExpression)
{
  Stack<double> operands;
  std::istringstream iss(rpnExpression);
  std::string token;

  while (iss >> token)
  {
  }
}