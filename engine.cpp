#include"engine.h"
#include"parser.h"
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
  bool keepGoing = true;
  int retVal[3] = {0};

  while (keepGoing)
  {
    prs.readAndProcess(retVal);
    if(retVal[2]==1)
    {
      setAns(retVal[0]+retVal[1]);
      std::cout << getAns() << '\n';
    }
  }
  if(retVal[2]==2)
  {
    setAns(retVal[0]-retVal[1]);
    std::cout << getAns() << '\n';
  }
  if(retVal[2]==3)
  {
    setAns(retVal[0]*retVal[1]);
    std::cout << getAns() << '\n';
  }
  if(retVal[2]==4)
  {
    setAns(retVal[0]/retVal[1]);
    std::cout << getAns() << '\n';
  }
  return 0;
}
