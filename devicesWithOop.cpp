#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Device {
protected:
  string deviceId;
  string brand;
  string password;
  double price;
  bool isLocked;
  bool wifiOn;

public:
  // trying a default constructor
  Device() {
    deviceId = "0";
    brand = "Device";
    password = "Password";
    price = 00.00;
    isLocked = true;
    wifiOn = true;
    // i hope that'll work
  }

  // trying constructor with parameters,
  Device(string id, string brandType, string pass, double devicePrice) {
    deviceId = id;
    brand = brandType;
    password = pass;
    price = devicePrice;
    // i hope these work too
  }

  virtual ~Device() {
    cout << "If you're seeing this, Device is getting destroyed by a destructor"
         << endl;
  }

  void unlock(const string &pass) {
    if (pass == password) {
      cout << "Device unlocked." << endl;
    } else {
      exit(0);
    }
  }

  void lock() { cout << "locked" << endl; }

  void toggleWifi() {
    if (wifiOn == true) {
      wifiOn = false;
    } else {
      wifiOn = true;
    }
  }

  virtual string showDeviceInfo() const {
    return brand + "" + deviceId + "" + to_string(price);
  }

  string getDeviceId() { return deviceId; }

  string getBrand() { return brand; }

  double getPrice() { return price; }

  void setPrice(double newPrice) { price = newPrice; }

  // done with the base class mehn,
};

class SmartPhone : public Device {
private:
  string phoneNumber;
  int batteryLevel;

public:  // <-- EVERYTHING BELOW NEEDS TO BE PUBLIC!
  // default constructor - call parent!
  SmartPhone() : Device() {
    phoneNumber = "911";
    batteryLevel = 100;
  }

  // parameterized constructor - include parent params AND child params
  SmartPhone(const string &id, const string &brandType, const string &pass,
             double devicePrice, const string &phone, int battery)
      : Device(id, brandType, pass, devicePrice) {  // <-- CALL PARENT!
    phoneNumber = phone;
    batteryLevel = battery;
  }

  ~SmartPhone() override {
    cout << "If you're seeing this then SmartPhone is being destroyed..."
         << endl;
  }

  // ANSWER: string& = uses original (faster), string = makes copy
  // const string& = best for read-only parameters
  void makeCall(const string &phone) {
    cout << "Calling " << phone << "..." << endl;
  }

  // ANSWER: Yes! 'msg' is declared as a parameter - you can use it!
  void sendText(const string &phone, const string &msg) {
    cout << "Text sent to " << phone << ": " << msg << endl;
  }

  void chargeBattery() {
    if (batteryLevel < 100) {
      cout << "Battery charging" << endl;
    } else {
      cout << "Battery already full" << endl;
    }
  }

  string showBattery() {
    return to_string(batteryLevel);
  }
};

class Laptop : public Device {
private:
  string macAddress;
  int ramSize;

public:  // <-- ADDED PUBLIC!
  // default constructor - call parent!
  Laptop() : Device() {
    macAddress = "AAbb";
    ramSize = 16;
  }

  // parameterized constructor - use const string& for string literals
  Laptop(const string &id, const string &brandType, const string &pass,
         double devicePrice, const string &mac, int ram)
      : Device(id, brandType, pass, devicePrice) {
    macAddress = mac;
    ramSize = ram;
  }

  ~Laptop() override {
    cout << "If you're seeing this then Laptop is being destroyed..." << endl;
  }

  void openTerminal() { cout << "Launching Konsole..." << endl; }

  void changeMacAddress(const string &mac) { macAddress = mac; }

  string showSpecs() {
    return deviceId + " " + brand + " " + to_string(price) + " " + macAddress +
           " " + to_string(ramSize);
  }
  // done with this class, confidence low,
};

class SmartWatch : public Device {
private:
  int stepCount;
  int heartRate;

public:
  // default constructor - call parent constructor!
  SmartWatch() : Device() {
    stepCount = 0;
    heartRate = 0;
  }

  // Parameterized constructor
  // For int, pass by value (no &) - it's small!
  SmartWatch(const string &id, const string &brandType, const string &pass,
             double devicePrice, int steps, int heart)
      : Device(id, brandType, pass, devicePrice) {
    stepCount = steps;
    heartRate = heart;
  }

  ~SmartWatch() override {
    cout << "If You're seeing this forget about the SmartWatch. " << endl;
  }

  void trackSteps() {
    cout << "Counting steps started ..."
         << endl; // here i would write a for loop to count steps but no time
                  // for that rn
  }

  int measureHeartRate() { return heartRate; }
  void showHealthStats() {
    cout << "Steps : " << stepCount << endl;
    cout << "Heart Rate : " << heartRate << endl;
  }
};

int main() {
  // Create objects with ALL required parameters
  // Format: ClassName objectName(deviceId, brand, password, price, ...extras);

  Laptop Lenovo("LP001", "Lenovo", "admin", 1200.00, "AA:BB:CC:DD", 16);
  SmartPhone Infinix("SP001", "Infinix", "1234", 299.99, "0712345678", 97);
  SmartWatch Rolex("SW001", "Rolex", "0000", 5000.00, 87, 72);

  // Test the objects
  cout << "\n=== Testing Laptop ===" << endl;
  Lenovo.unlock("admin");
  Lenovo.openTerminal();
  cout << Lenovo.showSpecs() << endl;

  cout << "\n=== Testing SmartPhone ===" << endl;
  Infinix.unlock("1234");
  Infinix.makeCall("0798765432");
  Infinix.sendText("0798765432", "Hello!");

  cout << "\n=== Testing SmartWatch ===" << endl;
  Rolex.trackSteps();
  Rolex.showHealthStats();

  cout << "\n=== Program ending (watch destructors!) ===" << endl;
  return 0;
}
