#include <algorithm>
#include <sstream>
#include <iterator>

#include "parser.h"

std::vector<std::string> parser::separateArguments(std::string expression)
{
  std::istringstream iss(expression);

  return std::vector<std::string>{
      std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
}

void parser::readAndProcess(double arg[])
{
  //int val[3];
  std::string input;
  std::string substr;

  // Read whole line
  std::getline(std::cin, input);

  // Separate commands by space
  std::vector<std::string> arguments = this->separateArguments(input);

  // Convert arguments to doubles
  double arg1 = stod(arguments[0]);
  double arg2 = stod(arguments[2]);

  int oper = -5;

  // Convert the operator
  if (arguments[1] == "+")
  {
    oper = 1;
  }
  else if (arguments[1] == "-")
  {
    oper = 2;
  }
  else if (arguments[1] == "*")
  {
    oper = 3;
  }
  else if (arguments[1] == "/")
  {
    oper = 4;
  }

  // Set the arguments
  arg[0] = arg1;
  arg[1] = oper;
  arg[2] = arg2;

  //   // Remove spaces from input
  //   input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

  //   for (int i = 0; i < input.length(); i++)
  //   {
  //     if (input.at(i) >= '0' && input.at(i) <= '9')
  //     {
  //       substr = substr + input.at(i);
  //     }
  //     else
  //     {
  //       switch (input.at(i))
  //       {
  //       case '+':
  //         arg[2] = 1;
  //         break;
  //       case '-':
  //         arg[2] = 2;
  //         break;
  //       case '*':
  //         arg[2] = 3;
  //         break;
  //       case '/':
  //         arg[2] = 4;
  //         break;
  //       default:
  //         arg[2] = -5;
  //         if (i == 0)
  //         {
  //           arg[2] = arg[2] * -1;
  //         }
  //       }
  //       arg[0] = stoi(substr);
  //       substr = "";
  //     }
  //   }
  //   arg[1] = stoi(substr);
}
