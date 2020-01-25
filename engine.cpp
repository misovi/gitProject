#include"engine.h"
#include"parser.h"
#include"basicArithmetic.h"
#include<string>
engine::engine()
{
  ansSet = false;
  ans = 0;
}

int engine::getAns()
{
  return ans;
}

void engine::setAns(int v)
{
  ans = v;
  ansSet = true;
}

int engine::run()
{
  parser prs;
  basicArithmetic calculator;

  bool keepGoing = true;
  int retVal[3] = {0};

  while (keepGoing)
  {
    prs.readAndProcess(retVal);
    std::cout << "DEBUG: " + String.valueOf(retVal[0]) + " " + String.valueOf(retVal[1]) + " " String.valueOf(retVal[2]) << '\n';
    if(retVal[2]<0 && ansSet)
    {
      retVal[2]=retVal[2]*-1;
      retVal[0] = getAns();
    }
    else if(!ansSet)
    {
      retVal[2]=5;
    }
    if(retVal[2]==1)
    {
      setAns(calculator.sum(retVal[0],retVal[1]));
      std::cout << getAns() << '\n';
    }
    if(retVal[2]==2)
    {
      setAns(calculator.subtract(retVal[0],retVal[1]));
      std::cout << getAns() << '\n';
    }
    if(retVal[2]==3)
    {
      setAns(calculator.multiply(retVal[0],retVal[1]));
      std::cout << getAns() << '\n';
    }
    if(retVal[2]==4)
    {
      setAns(calculator.divide(retVal[0],retVal[1]));
      std::cout << getAns() << '\n';
    }
    if(retVal[2]==5)
    {
      std::cout << "Something went wrong." << '\n';
      keepGoing=false;
    }
  }
  return 0;
}
