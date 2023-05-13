#pragma once

#include <string>
#include <sstream>
#include <cmath>
#include "Stack.h"
#include "RPNUtils.h"
#include "OperatorManager.h"

class RPNCalculator
{
public:
  double calculate(const std::string &);

private:
  double performOperation(const std::string &, double, double);
};