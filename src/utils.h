#pragma once

#include <iostream>
#include <string>
#include "RPNConverter.h"
#include "RPNCalculator.h"

template <typename T>
T calculate(std::string expr)
{
  RPNConverter converter{expr};
  std::string rpn = converter.convertToRPN();
  std::cout << rpn << endl;
  RPNCalculator calculator;
  double result = calculator.calculate(rpn);
  return result;
}