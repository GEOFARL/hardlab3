#pragma once

#include <iostream>
#include <string>
#include "RPNConverter.h"
#include "RPNCalculator.h"

double calculate(std::string expr)
{
  RPNConverter converter{expr};
  std::string rpn = converter.convertToRPN();
  RPNCalculator calculator;
  double result = calculator.calculate(rpn);
  return result;
}