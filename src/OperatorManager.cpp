#include "OperatorManager.h"

namespace OperatorManager
{
  const std::unordered_map<std::string, Operator> operators = {
      {"+", Operator("+", 2, true)},
      {"-", Operator("-", 2, true)},
      {"*", Operator("*", 3, true)},
      {"/", Operator("/", 3, true)},
      {"^", Operator("^", 4, false)}};

  bool isOperator(const std::string &token)
  {
    return operators.find(token) != operators.end();
  }

  const Operator &getOperator(const std::string &token)
  {
    return operators.at(token);
  }
}
