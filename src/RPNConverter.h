#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
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

public:
  RPNConverter(const std::string &expr)
  {
    expression = removeWhiteSpaces(expr);
    cout << expression << endl;
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
};