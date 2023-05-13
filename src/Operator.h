#pragma once

#include <string>

class Operator
{
private:
  std::string symbol;
  int precedence;
  bool isLeftAssoc;

public:
  Operator() = default;
  Operator(const std::string &, int, bool);

  std::string getSymbol() const;
  int getPrecedence() const;
  bool isLeftAssociative() const;
};