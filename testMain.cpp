#include"parser.h"
#include<iostream>

int main()
{
  parser p;
  int arg[3] = {0,0,0};
  p.readAndProcess(arg);
  std::cout << arg[0] << '\n';
  std::cout << arg[1] << '\n';
  std::cout << arg[2] << '\n';
}
