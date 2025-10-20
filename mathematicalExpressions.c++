#include <iostream>

int main() {
  int x = 10;
  double y = 4;
  int z = 3;

  int sum = x + y;
  int division = x / y;
  double division2 = x / y;
  int multiplication = x * y;
  int remainder =
      x % z; // didn't use y because it raised an error because y is a dobule.

  //   int k = x++; // will store value of x in k and then increment x
  int p = ++x; // will first increment x and then store it in p so both will
               // have same value

  //   std::cout << sum << std::endl;
  //   std::cout << division << std::endl;
  //   std::cout << division2 << std::endl;
  //   std::cout << multiplication << std::endl;
  //   std::cout << remainder << std::endl;

  std::cout << x << std::endl << p << std::endl << x << std::endl;

  return 0;
}