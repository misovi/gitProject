#include <iostream>
#include <string>
#include <vector>

class parser
{
private:
  /* data */

public:
  void readAndProcess(double arg[]);
  std::vector<std::string> separateArguments(std::string expression);
};
