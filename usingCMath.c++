// calculating area of a circle with user input radius
#include <cmath>
#include <iostream>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  double radius = 0;
  double area = 0;
  const double pi = 3.142;

  cout << "Here we calculate the area of a circle." << endl;
  cout << "Enter radius: ";
  cin >> radius;

  //   area = pi * radius * radius;
  // because we have cmath, we use pow to power.

  area = pi * pow(radius, 2);
  cout << area << endl;

  return 0;
}