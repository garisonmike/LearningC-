#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
  string IMEI_number;
  string devicePassword;

public:
  // Public member functions
  void makeCall() { cout << "Making a call..." << endl; }

  void installApp() { cout << "Installing an app..." << endl; }

  void setPassword(string oldPassword, string newPassword) {
    if (oldPassword == devicePassword) {
      devicePassword = newPassword;
      cout << "Password updated successfully." << endl;
    } else {
      cout << "Incorrect old password!" << endl;
    }
  }
};
