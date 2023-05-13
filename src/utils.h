#pragma once

#include <iostream>
#include <string>
#include "RPNConverter.h"

template <typename T>
T calculate(std::string expr)
{
  RPNConverter<T> converter{expr};
  std::string rpn = converter.convertToRPN();
  std::cout << rpn << endl;
  return 1.5;
}