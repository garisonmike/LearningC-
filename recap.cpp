#include <cstdlib>
#include <iostream>
#include <string>

// int main() {
//   std::string name;
//   std::cout << "Enter your name: ";
//   std::cin >> name;
//   std::cout << "Lemme guess, Your name is " << name << ", right? " <<
//   std::endl;

//   return 0;
// }

using namespace std;
class Laptop {
private:
  string macAddress = "2323";
  string password = "Hello";

public:
  void login() {
    string loginPassword;

    cout << "Enter password to login: ";
    cin >> loginPassword;

    if (loginPassword != password) {
      cout << "Login Failed!!" << endl;
      exit(0);
    } else {
      cout << "Login Successful!" << endl;
    };
  }

  void checkMacAddress() {
    login();
    cout << "Your Mac Address is " << macAddress << endl;
  }

  void changePassword() {
    string newPassword;

    login();
    cout << "Enter new password: ";
    cin >> newPassword;
    password = newPassword;
    cout << "New password set" << endl;
  }

  void changeMacAddress() {
    string newMacAddress;

    login();

    cout << "Enter new Mac Address: ";
    cin >> newMacAddress;
    cout << "Your new Mac Address is " << newMacAddress << endl;
  }
};

int main() {

  Laptop lenovo;

  cout << "Let us check the Mac Address lenovo." << endl;
  lenovo.checkMacAddress();
  cout << "Let us try to change the Mac Address lenovo." << endl;
  lenovo.changeMacAddress();
  cout << "Let us try to change the password for lenovo." << endl;
  lenovo.changePassword();

  return 0;
};