#include "RPNUtils.h"

bool RPNUtils::isNumeric(const std::string &token)
{
  std::istringstream iss(token);
  double value;
  return iss >> value && iss.eof();
}