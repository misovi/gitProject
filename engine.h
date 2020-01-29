class engine
{
private:
  double ans = 0;
  bool ansSet = false;

public:
  engine();
  int run();
  double getAns();
  void setAns(double v);
};
