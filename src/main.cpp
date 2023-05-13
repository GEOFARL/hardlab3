#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
    return 1;
  }
  try
  {
    double result = calculate(string{argv[1]});
    cout << "Result: " << result << endl;
  }
  catch (const exception &e)
  {
    cerr << e.what() << endl;
  }
  return 0;
}