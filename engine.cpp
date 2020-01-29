#include "engine.h"
#include "parser.h"
#include "basicArithmetic.h"
#include <string>
engine::engine()
{
  ansSet = false;
  ans = 0;
}

double engine::getAns()
{
  return ans;
}

void engine::setAns(double v)
{
  ans = v;
  ansSet = true;
}

int engine::run()
{
  parser prs;
  basicArithmetic calculator;

  bool keepGoing = true;
  double retVal[3] = {0};

  while (keepGoing)
  {
    prs.readAndProcess(retVal);

    std::cout << "DEBUG: " << retVal[0] << " " << retVal[1] << " " << retVal[2] << '\n';

    switch ((int)retVal[1])
    {
    case 1:
      setAns(calculator.sum(retVal[0], retVal[2]));
      std::cout << getAns() << '\n';
      break;
    case 2:
      setAns(calculator.subtract(retVal[0], retVal[2]));
      std::cout << getAns() << '\n';
      break;
    case 3:
      setAns(calculator.multiply(retVal[0], retVal[2]));
      std::cout << getAns() << '\n';
      break;
    case 4:
      setAns(calculator.divide(retVal[0], retVal[2]));
      std::cout << getAns() << '\n';
      break;
    default:
      std::cout << "Something went wrong." << '\n';
      keepGoing = false;
      break;
    }
  }

  return 0;
}
