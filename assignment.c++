#include <iostream>
#include <string>
using namespace std;

class Student {
public:
  string name;
  string regNumber;
  int age;

  // This is the function that displays student details
  void display() {
    cout << "Name: " << name << endl;
    cout << "Registration Number: " << regNumber << endl;
    cout << "Age: " << age << endl;
    cout << "---------------------------" << endl;
  }
};

int main() {
  // First Student object
  Student student1;
  student1.name = "Joe Mwangi";
  student1.regNumber = "CT101/G/232232/2025";
  student1.age = 20;

  // Second Student object
  Student student2;
  student2.name = "Mike Moreti";
  student2.regNumber = "CT101/G/253242/2023";
  student2.age = 19;

  // The function that displays student details
  student1.display();
  student2.display();

  return 0;
}
