#include <iostream>

int main() {
  int variable1 = 5;
  int variable2 = 8;
  int temp = 0;

  temp = variable1;
  variable1 = variable2;
  variable2 = temp;

  std::cout << variable1;
  std::cout << variable2;

  return 0;
}