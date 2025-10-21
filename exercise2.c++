// converting fahrenheit to celsius
#include <iostream>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  double fahrenheit = 0;
  int celsius = 0;

  cout << "Enter Fahrenheit to convert: ";
  cin >> fahrenheit;
  //   cout << endl;

  celsius = (fahrenheit - 32) *
            (5.0 / 9.0); // you remove decimals from 5.0 and 9.0 it won't
                         // run.Don't ask me why, it just works!!

  cout << "That's equal to " << celsius << " degrees celsius.";

  return 0;
}