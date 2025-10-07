		
		Name: Kinyua Mike Moreti

		Registration Number: CT101/G/23624/24

		Course: BSc Computer Science
		Unit: SPC 2204 – Object Oriented Programming I
		Lecturer: Dr. Stephen Kahara Wanjau
		Assignment Title: Assignment 1










Q1:
a)fundamental concepts of Object-Oriented Programming.
Encapsulation- This is bundling data and functions that operate on that data into an object so as to hide internal details from the outside world.
Abstraction - This is modelling classes based on their essential features; it helps view classes based on what they can do not how they do it.
Iheritance - A new class can inherit properties and methods from an existing class. The existing class is the superclass and the new class is the subclass.This helps reuse code and create a hierachy of classes.
Polymorphism - A function can be used across many objects hence promotes reuse of code and makes code flexible and easy to maintain.

b)A banking application is being developed. The developers have created
BankAccount class.
 Each BankAccount object has its own accountNumber,accountHolderName, and balance.

i)Which OOP concept is primarily demonstrated by creating individual BankAccount objects like account1 andvaccount2?
Instantiation

ii) If the BankAccount class combines the data (like balance) and the methods that
operate on that data (like deposit(), withdraw()) into a single unit, which OOP concept
is being applied?
Encapsulation

iii) If the BankAccount class hides its internal balance variable from direct external access
and provides public methods to interact with it, which OOP concept is this?
Data hiding

iv) The application has a general Account class. From this, more speci ic classes like SavingsAccount and CurrentAccount are created, each with its own rules for withdraw(). Which OOP concept allows this hierarchical organization and specialized behaviour?
Inheritance

c) State two benefits of using the Object-Oriented Programming paradigm over procedural
programming.
in oop it's easy to organize code and reuse it for different objects while procedural programming it's hard to organize and reuse code.

Q2.
a)What is the difference between a class and an object? Use a real-world analogy to
explain your answer.
A class is a template that can be used with objects to achieve something. An object is an instantiation of a class.
Magunas supermarket can have a system with a class named TotalPayableAmount; to represent the total amount a customer should pay for their items. The class could have functions that add the prices of the items the customer has brough to counter and then calculate taxation on each item and add that taxation, add discounts of items that are on offer and subtract it from the total, that net amount is what the class TotalPayableAmount represents.
In this case an object is the customer and their data is the items they've brought to counter.

b)Examine the following C++ code snippet.
```cpp
#include <iostream>
#include <string>
using namespace std;
class Book {
string title;
string author;
double price;
};
int main() {
Book myBook;
myBook.title = "The C++ Programming Language";
cout << myBook.title;
return 0;
}

i)The code above will result in a compilation error. Explain why.
C++ declares the data members as private by default since not access modifier is specified. So it's not possible to access it directly using myBook.title from main()

ii)Correct the code in the `main()` function to successfully assign and print the
book's title.
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    double price;
};

int main() {
    Book myBook;
    myBook.title = "The C++ Programming Language";
    cout << myBook.title;
    return 0;
}

c) Write a complete C++ program that de ines a simple Student class. The class should
have the following:
-Data Members: name (string), regNumber (string), age (int)
-A member function display() that prints out the student's details.
In the main() function, create two Student objects, initialize their data, and call
the display() method for each.

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


Q3.
a) Explain the principle of Encapsulation. How does it relate to Information Hiding?
Encapsulation is the process of bundling data, attributes, and the functions that operate on that same data into a single unit called a class. This isolates those variables and functions from the outside world. Information hiding is declaring data members as private and providing public methods to access them externally. It helps prevent accidental modification of an object’s internal state.

b) What are access modifiers in C++? List the three main access modifiers and describe their scope.
Public – Members are accessible from anywhere in the program.
Private – Members are accessible only within the same class.
Protected – Members are accessible within the same class and its subclasses (derived classes).

c) You are designing a Smartphone class. The internal state of the smartphone, such as
its IMEI_number and devicePassword, should be strictly protected and not directly
accessible from outside the class. However, functions like makeCall() and installApp() should be publicly available.
i) Write a C++ code snippet for the `Smartphone` class that demonstrates this.
ii) Declare the private data members: `IMEI_number` (string) and `devicePassword`
iii) Declare public member functions: `makeCall()`, `installApp()`, and a `setPassword()`
function that allows the user to set a new password only if the old one is provided.

#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
    string IMEI_number;
    string devicePassword;

public:
    // Public member functions
    void makeCall() {
        cout << "Making a call..." << endl;
    }

    void installApp() {
        cout << "Installing an app..." << endl;
    }

    void setPassword(string oldPassword, string newPassword) {
        if (oldPassword == devicePassword) {
            devicePassword = newPassword;
            cout << "Password updated successfully." << endl;
        } else {
            cout << "Incorrect old password!" << endl;
        }
    }
};


Q4.
a) What is Abstraction in the context of OOP? How does it help in managing complexity in
large software projects?
Abstraction is focusing on essential features of an object while hiding unnecessary implementation details. Users interact with the code from a 'what it can do' perspective instead of 'how it does'. In large software projects abstraction helps manage complexity by dividing systems into smaller understandable modules. Developers work with simplified interfaces rather than complex code behind it hence improving readability, maintainability and collaboration.

b) Explain what an Abstract Data Type (ADT) is. How is it implemented in C++?
An Abstract Data Type (ADT) is a data structure defined by its behavior (operations) rather than its implementation. It specifies what operations can be performed but not how they are carried out internally.In C++, ADTs are implemented using classes, where data members are kept private and only accessible through public methods. This ensures that data is protected, and interaction is done through a controlled interface.

c) Consider you are creating a simulation for a vehicle. You want to de ine a simple interface
for starting and stopping a vehicle's engine. The internal mechanics of how the engine
starts (e.g., fuel injection, spark plug ignition) are hidden from the user.
Write a C++ code snippet that demonstrates abstraction.
-Create a class `Car`.
- It should have a “private” data member `engineStarted` (boolean).
- It should have “public” methods: `startEngine()` and `stopEngine()`. The
`startEngine()` function should set `engineStarted` to `true` and print "Car engine
started." Similarly, the `stopEngine()` function should set it to `false` and print "Car
engine stopped."
- In the `main()` function, create a `Car` object and demonstrate starting and
stopping the engine. The user of the `Car` class does not need to know about the
`engineStarted` variable; they only interact with the public methods.


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

