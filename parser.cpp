#include"parser.h"


void parser::readAndProcess(int arg[])
{
  //int val[3];
  std::string input;
  std::string substr;
  std::cin>>input;
  for(int i=0;i<input.length();i++)
  {
    if(input.at(i)>='0' && input.at(i)<='9')
    {
      substr = substr + input.at(i);
    }
    else
    {
      switch (input.at(i)) {
        case '+': arg[2] = 1;break;
        case '-': arg[2] = 2;break;
        case '*': arg[2] = 3;break;
        case '/': arg[2] = 4;break;
        default: arg[2] = -5;
        if(i==0)
        {
          arg[2] = arg[2]*-1;
        }
      }
      arg[0] = stoi(substr);
      substr = "";
    }
  }
  arg[1] = stoi(substr);
}
