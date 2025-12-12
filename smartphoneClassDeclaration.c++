// Include the iostream library for input/output operations (cout, cin)
#include <iostream>
// Include the string library to use the string data type
#include <string>
// This allows us to use cout, string, etc. without typing "std::" every time
using namespace std;

class Smartphone {
  // PRIVATE SECTION
  // Private members can ONLY be accessed from inside the class
  // This is called "encapsulation" - hiding sensitive data

private:
  // These are "member variables" (also called attributes/properties)
  string IMEI_number; // Unique identifier for the phone (hidden from outside)
  string devicePassword; // Password stored securely (hidden from outside)

  // PUBLIC SECTION
  // Public members can be accessed from anywhere (inside or outside the class)
  // These are the "interface" - how others interact with our object
public:
  // These are "member functions" (also called methods)
  // They define what actions a Smartphone can perform

  // Simple method that simulates making a call
  void makeCall() { cout << "Making a call..." << endl; }

  // Simple method that simulates installing an app
  void installApp() { cout << "Installing app..." << endl; }

  // Method to change password securely
  // Parameters: oldPassword (for verification), newPassword (the new one to
  // set)
  void setPassword(string oldPassword, string newPassword) {
    // First, verify the old password matches
    if (oldPassword == devicePassword) {
      devicePassword = newPassword; // Update to new password
      cout << "Password updated successfully." << endl;
    } else {
      cout << "Incorrect old password!" << endl;
    }
  }
};
// Don't forget the semicolon after the class definition! (common mistake)

// MAIN FUNCTION
// This is where your program starts running
// Here we create and use Smartphone objects
int main() {
  // Create an object (instance) of the Smartphone class
  // "myPhone" is now a Smartphone object
  Smartphone myPhone;

  // Call public methods using the dot operator (.)
  cout << "=== Testing myPhone ===" << endl;
  myPhone.makeCall();   // Output: Making a call...
  myPhone.installApp(); // Output: Installing app...

  // Set a password (first time, old password is empty "")
  myPhone.setPassword("", "secret123");

  // Try changing password with wrong old password
  myPhone.setPassword("wrongpass", "newpass"); // Should fail

  // Try changing password with correct old password
  myPhone.setPassword("secret123", "newpass"); // Should succeed

  // You can create multiple objects from the same class!
  Smartphone anotherPhone;
  cout << "\n=== Testing anotherPhone ===" << endl;
  anotherPhone.makeCall();

  // NOTE: You CANNOT do this (uncomment to see the error):
  // myPhone.devicePassword = "hack"; // ERROR! devicePassword is private

  return 0; // Program ended successfully
}