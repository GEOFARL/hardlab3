#pragma once

#include <unordered_map>
#include <string>
#include "Operator.h"

namespace OperatorManager
{
  extern const std::unordered_map<std::string, Operator> operators;

  bool isOperator(const std::string &token);
  const Operator &getOperator(const std::string &token);
}
