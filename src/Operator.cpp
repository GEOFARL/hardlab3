#include "Operator.h"

Operator::Operator(const std::string &sym, int prec, bool isLeftAssoc)
    : symbol(sym), precedence(prec), isLeftAssoc(isLeftAssoc) {}

std::string Operator::getSymbol() const
{
  return symbol;
}

int Operator::getPrecedence() const
{
  return precedence;
}

bool Operator::isLeftAssociative() const
{
  return isLeftAssoc;
}