#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <unordered_map>
#include "Stack.h"

struct Operator
{
  std::string symbol;
  int precedence;
  bool isLeftAssociative;

  Operator(const std::string &sym, int prec, bool isLeftAssoc)
      : symbol(sym), precedence{prec}, isLeftAssociative{isLeftAssoc} {}
};

template <typename T>
class RPNConverter
{
  std::string expression;
  Stack<T> stack;
  std::unordered_map<std::string, Operator> operators;

public:
  RPNConverter(const std::string &expr)
  {
    expression = removeWhiteSpaces(expr);
    initializeOperators();
  }

  std::string convertToRPN()
  {
    std::string rpnExpression;
    std::istringstream iss{expression};
    std::string token;

    while (iss >> token)
    {
    }
  }

private:
  std::string removeWhiteSpaces(const std::string &expr)
  {
    std::stringstream ss;
    for (char c : expr)
    {
      if (!std::isspace(c))
      {
        ss << c;
      }
    }
    return ss.str();
  }

  void initializeOperators()
  {
    operators.emplace("+", Operator("+", 2, true));
    operators.emplace("-", Operator("-", 2, true));
    operators.emplace("*", Operator("*", 3, true));
    operators.emplace("/", Operator("/", 3, true));
    operators.emplace("^", Operator("^", 4, false));
  }

  bool isOperator(const T &token)
  {
    return operators.find(token) != operators.end();
  }
};