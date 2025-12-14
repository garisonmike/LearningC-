#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// ============================================================
// BASE CLASS: Device
// This is the parent class that contains common attributes
// and methods shared by all devices (phones, laptops, watches)
// ============================================================
class Device {
  // PROTECTED: Accessible by this class AND child classes
  // (not accessible from outside like main())
protected:
  string deviceId; // Unique identifier for the device
  string brand;    // Brand name (Samsung, Apple, Dell, etc.)
  double price;    // Price in dollars
  bool isLocked;   // true = locked, false = unlocked
  string password; // Password to unlock device
  bool wifiOn;     // WiFi status

  // PUBLIC: Accessible from anywhere
public:
  // ============================================
  // DEFAULT CONSTRUCTOR
  // Called when you create object without parameters
  // Example: Device myDevice;
  // ============================================
  Device() {
    deviceId = "UNKNOWN";
    brand = "Generic";
    price = 0.0;
    isLocked = true;
    password = "0000";
    wifiOn = false;
    cout << "[Device] Created with default values." << endl;
  }

  // ============================================
  // PARAMETERIZED CONSTRUCTOR
  // Called when you provide values during creation
  // Example: Device myDevice("D001", "Apple", 500, "1234");
  // ============================================
  Device(const string &id, const string &b, double p, const string &pass) {
    deviceId = id;
    brand = b;
    price = p;
    password = pass;
    isLocked = true; // Devices start locked
    wifiOn = false;  // WiFi starts off
    cout << "[Device] " << brand << " created with ID: " << deviceId << endl;
  }

  // ============================================
  // DESTRUCTOR
  // Called automatically when object is destroyed
  // ============================================
  virtual ~Device() {
    cout << "[Device] " << brand << " (ID: " << deviceId << ") destroyed."
         << endl;
  }

  // ============================================
  // UNLOCK METHOD
  // Attempts to unlock the device with password
  // ============================================
  void unlock(const string &inputPass) {
    if (isLocked) {
      if (inputPass == password) {
        isLocked = false;
        cout << "[" << brand << "] Device unlocked successfully!" << endl;
      } else {
        cout << "[" << brand << "] Wrong password! Device remains locked."
             << endl;
      }
    } else {
      cout << "[" << brand << "] Device is already unlocked." << endl;
    }
  }

  // ============================================
  // LOCK METHOD
  // Locks the device
  // ============================================
  void lock() {
    isLocked = true;
    cout << "[" << brand << "] Device locked." << endl;
  }

  // ============================================
  // TOGGLE WIFI
  // Switches WiFi on/off
  // ============================================
  void toggleWifi() {
    if (isLocked) {
      cout << "[" << brand << "] Please unlock device first!" << endl;
      return;
    }
    wifiOn = !wifiOn; // Flip the boolean
    cout << "[" << brand << "] WiFi is now " << (wifiOn ? "ON" : "OFF") << endl;
  }

  // ============================================
  // SHOW DEVICE INFO
  // Displays all device information
  // 'virtual' allows child classes to override this
  // ============================================
  virtual void showDeviceInfo() {
    cout << "\n====== DEVICE INFO ======" << endl;
    cout << "ID:       " << deviceId << endl;
    cout << "Brand:    " << brand << endl;
    cout << "Price:    $" << price << endl;
    cout << "Status:   " << (isLocked ? "Locked" : "Unlocked") << endl;
    cout << "WiFi:     " << (wifiOn ? "ON" : "OFF") << endl;
    cout << "=========================" << endl;
  }

  // ============================================
  // GETTERS - Return private values
  // ============================================
  string getDeviceId() const { return deviceId; }
  string getBrand() const { return brand; }
  double getPrice() const { return price; }
  bool getIsLocked() const { return isLocked; }

  // ============================================
  // SETTERS - Modify private values
  // ============================================
  void setPrice(double newPrice) {
    if (newPrice >= 0) {
      price = newPrice;
      cout << "[" << brand << "] Price updated to $" << price << endl;
    } else {
      cout << "Error: Price cannot be negative!" << endl;
    }
  }

  void setPassword(const string &oldPass, const string &newPass) {
    if (oldPass == password) {
      password = newPass;
      cout << "[" << brand << "] Password changed successfully!" << endl;
    } else {
      cout << "[" << brand << "] Incorrect old password!" << endl;
    }
  }
};

// ============================================================
// DERIVED CLASS: Smartphone
// Inherits from Device using 'public' inheritance
// Has extra features specific to phones
// ============================================================
class Smartphone : public Device {
  // PRIVATE: Only accessible within Smartphone class
private:
  string phoneNumber;
  int batteryLevel; // 0-100%

public:
  // ============================================
  // CONSTRUCTOR
  // Calls parent constructor using : Device(...)
  // Then initializes its own attributes
  // ============================================
  Smartphone(const string &id, const string &b, double p, const string &pass,
             const string &number)
      : Device(id, b, p, pass) { // Call parent constructor FIRST
    phoneNumber = number;
    batteryLevel = 100; // Start fully charged
    cout << "[Smartphone] Phone number: " << phoneNumber << endl;
  }

  // ============================================
  // DESTRUCTOR
  // ============================================
  ~Smartphone() {
    cout << "[Smartphone] " << phoneNumber << " shutting down..." << endl;
  }

  // ============================================
  // MAKE CALL
  // Simulates calling someone
  // ============================================
  void makeCall(const string &number) {
    if (isLocked) {
      cout << "[Smartphone] Please unlock phone first!" << endl;
      return;
    }
    if (batteryLevel <= 0) {
      cout << "[Smartphone] Battery dead! Please charge." << endl;
      return;
    }
    cout << "[Smartphone] Calling " << number << "..." << endl;
    batteryLevel -= 5; // Calling uses battery
  }

  // ============================================
  // SEND TEXT
  // Simulates sending SMS
  // ============================================
  void sendText(const string &number, const string &message) {
    if (isLocked) {
      cout << "[Smartphone] Please unlock phone first!" << endl;
      return;
    }
    cout << "[Smartphone] Sending to " << number << ": \"" << message << "\""
         << endl;
    batteryLevel -= 2;
  }

  // ============================================
  // CHARGE BATTERY
  // Recharges the phone
  // ============================================
  void chargeBattery() {
    cout << "[Smartphone] Charging..." << endl;
    batteryLevel = 100;
    cout << "[Smartphone] Fully charged!" << endl;
  }

  // ============================================
  // SHOW BATTERY
  // Displays current battery level
  // ============================================
  void showBattery() const {
    cout << "[Smartphone] Battery: " << batteryLevel << "%" << endl;
  }

  // ============================================
  // OVERRIDE: showDeviceInfo
  // Adds phone-specific info to parent's output
  // ============================================
  void showDeviceInfo() override {
    Device::showDeviceInfo(); // Call parent method first
    cout << "Phone:    " << phoneNumber << endl;
    cout << "Battery:  " << batteryLevel << "%" << endl;
    cout << "=========================" << endl;
  }

  // GETTER
  string getPhoneNumber() const { return phoneNumber; }
};

// ============================================================
// DERIVED CLASS: Laptop
// Inherits from Device
// Has features specific to laptops
// ============================================================
class Laptop : public Device {
private:
  string macAddress;
  int ramSize; // in GB

public:
  // CONSTRUCTOR
  Laptop(const string &id, const string &b, double p, const string &pass,
         const string &mac, int ram)
      : Device(id, b, p, pass) {
    macAddress = mac;
    ramSize = ram;
    cout << "[Laptop] MAC: " << macAddress << ", RAM: " << ramSize << "GB"
         << endl;
  }

  // DESTRUCTOR
  ~Laptop() { cout << "[Laptop] Shutting down laptop..." << endl; }

  // ============================================
  // OPEN TERMINAL
  // ============================================
  void openTerminal() {
    if (isLocked) {
      cout << "[Laptop] Please unlock laptop first!" << endl;
      return;
    }
    cout << "[Laptop] Opening terminal..." << endl;
    cout << "[Laptop] user@" << brand << ":~$ _" << endl;
  }

  // ============================================
  // CHANGE MAC ADDRESS
  // Only laptops can change their MAC
  // ============================================
  void changeMacAddress(const string &newMac) {
    if (isLocked) {
      cout << "[Laptop] Please unlock laptop first!" << endl;
      return;
    }
    cout << "[Laptop] Changing MAC from " << macAddress << " to " << newMac
         << endl;
    macAddress = newMac;
    cout << "[Laptop] MAC Address updated!" << endl;
  }

  // ============================================
  // SHOW SPECS
  // ============================================
  void showSpecs() const {
    cout << "\n--- Laptop Specifications ---" << endl;
    cout << "MAC Address: " << macAddress << endl;
    cout << "RAM: " << ramSize << " GB" << endl;
    cout << "-----------------------------" << endl;
  }

  // OVERRIDE: showDeviceInfo
  void showDeviceInfo() override {
    Device::showDeviceInfo();
    cout << "MAC:      " << macAddress << endl;
    cout << "RAM:      " << ramSize << " GB" << endl;
    cout << "=========================" << endl;
  }

  // GETTER & SETTER
  string getMacAddress() const { return macAddress; }
  void setMacAddress(const string &mac) { macAddress = mac; }
};

// ============================================================
// DERIVED CLASS: Smartwatch
// Inherits from Device
// Has health tracking features
// ============================================================
class Smartwatch : public Device {
private:
  int stepCount;
  int heartRate; // BPM

public:
  // CONSTRUCTOR
  Smartwatch(const string &id, const string &b, double p, const string &pass)
      : Device(id, b, p, pass) {
    stepCount = 0;
    heartRate = 70; // Normal resting heart rate
    cout << "[Smartwatch] Health tracking enabled!" << endl;
  }

  // DESTRUCTOR
  ~Smartwatch() { cout << "[Smartwatch] Watch powering off..." << endl; }

  // ============================================
  // TRACK STEPS
  // Simulates walking and counting steps
  // ============================================
  void trackSteps() {
    int steps = rand() % 1000 + 100; // Random 100-1100 steps
    stepCount += steps;
    cout << "[Smartwatch] +" << steps << " steps! Total: " << stepCount << endl;
  }

  // ============================================
  // MEASURE HEART RATE
  // Simulates heart rate measurement
  // ============================================
  void measureHeartRate() {
    heartRate = rand() % 40 + 60; // Random 60-100 BPM
    cout << "[Smartwatch] Heart rate: " << heartRate << " BPM" << endl;
  }

  // ============================================
  // SHOW HEALTH STATS
  // ============================================
  void showHealthStats() const {
    cout << "\n--- Health Statistics ---" << endl;
    cout << "Steps Today:  " << stepCount << endl;
    cout << "Heart Rate:   " << heartRate << " BPM" << endl;
    cout << "-------------------------" << endl;
  }

  // OVERRIDE: showDeviceInfo
  void showDeviceInfo() override {
    Device::showDeviceInfo();
    cout << "Steps:    " << stepCount << endl;
    cout << "Heart:    " << heartRate << " BPM" << endl;
    cout << "=========================" << endl;
  }

  // GETTERS
  int getStepCount() const { return stepCount; }
  int getHeartRate() const { return heartRate; }
};

// ============================================================
// MAIN FUNCTION
// This is where we create objects and test our classes
// ============================================================
int main() {
  cout << "\n========== CREATING DEVICES ==========\n" << endl;

  // Create a Smartphone object
  Smartphone myPhone("SP001", "Samsung", 999.99, "1234", "0712345678");

  // Create a Laptop object
  Laptop myLaptop("LP001", "Dell", 1499.99, "admin", "AA:BB:CC:DD:EE:FF", 16);

  // Create a Smartwatch object
  Smartwatch myWatch("SW001", "Apple", 449.99, "0000");

  cout << "\n========== TESTING SMARTPHONE ==========\n" << endl;

  // Try to call while locked (should fail)
  myPhone.makeCall("0798765432");

  // Unlock the phone
  myPhone.unlock("1234");

  // Now make a call
  myPhone.makeCall("0798765432");
  myPhone.sendText("0798765432", "Hello from OOP!");

  // Toggle WiFi
  myPhone.toggleWifi();

  // Check battery
  myPhone.showBattery();

  // Show all info
  myPhone.showDeviceInfo();

  cout << "\n========== TESTING LAPTOP ==========\n" << endl;

  // Unlock and use laptop
  myLaptop.unlock("admin");
  myLaptop.openTerminal();
  myLaptop.toggleWifi();

  // Change MAC address
  myLaptop.changeMacAddress("11:22:33:44:55:66");
  myLaptop.showSpecs();
  myLaptop.showDeviceInfo();

  cout << "\n========== TESTING SMARTWATCH ==========\n" << endl;

  // Unlock watch
  myWatch.unlock("0000");

  // Track health
  myWatch.trackSteps();
  myWatch.trackSteps();
  myWatch.measureHeartRate();
  myWatch.showHealthStats();
  myWatch.showDeviceInfo();

  cout << "\n========== PROGRAM ENDING ==========\n" << endl;
  cout << "(Watch the destructors run automatically!)\n" << endl;

  return 0;
}
