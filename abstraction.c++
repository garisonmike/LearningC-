#include <iostream>
using namespace std;

class Car {
private:
  bool engineStarted; // underlying code hidden from the user

public:
  // Constructor
  Car() { engineStarted = false; }

  void startEngine() {
    engineStarted = true;
    cout << "Car engine started." << endl;
  }

  void stopEngine() {
    engineStarted = false;
    cout << "Car engine stopped." << endl;
  }
};

int main() {
  Car myCar;           // Creating a Car object
  myCar.startEngine(); // Starting the car
  myCar.stopEngine();  // Stopping the car
  return 0;
}
