#pragma once

#include <string>
#include <sstream>
#include "Stack.h"
#include "RPNUtils.h"
#include "OperatorManager.h"

class RPNCalculator
{
public:
  double calculate(const std::string &);
};