#include <iostream>
#include <string>
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
  }
};