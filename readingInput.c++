// reading user input with cin >>
#include <iostream>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  double num1 = 0;
  double num2 = 0;

  cout << "Enter a the first number: " << endl;
  cin >> num1;
  cout << "Enter the second number: " << endl;
  cin >> num2;

  cout << "You entered " << num1 << " and " << num2 << endl;

  return 0;
}