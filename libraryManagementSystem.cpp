/* Library Management System

What it is: A console application to add books, borrow books, return books, and
calculate fines and check if books are available.

Key Skills: Classes/Objects, Vectors, File Handling (fstream to save data
between sessions), String manipulation.

Twist: Implement a search function that finds books by partial title or author.

*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Person {
  // Person can be student, librarian, lecturer or any library user
private:
  double fineRate;
  //   string book;

public:
  // my constructor
  Person() { const double fineRate = 10; }

  void addBook(string &newBook) {
    cout << newBook << " Added to list of available books." << endl;
  }

  void borrowBook(string &nameOfBook) {
    cout << nameOfBook << " Marked as Borrowed." << endl;
  }

  void returnBook(string &nameOfBook) {
    cout << nameOfBook << " Marked as Returned." << endl;
  }

  double getFine(int &daysOverdue) { return daysOverdue * fineRate; }

  void checkBookAvailability(string &nameOfBook) {
    // here we'll check if book is available for borrowing
    cout << "Checking if book is available for borrowing... " << endl;
  }

  void checkBorrowedBooks() {
    // here we display all the avialable books in the library. i guess we'll
    // display in pages of 30 books each page
    cout << "Listing books marked as Borrowed..." << endl;
  }

  void login(string &username, string &password) {
    // tommorow i'll learn how to use sqlite3 in cpp so i can use it as the db,
    // as of today i'll skip this function.
  }

  int menu() {
    int choice;
    cout << endl;
    cout << "Select choice : " << endl;
    cout << "1.Add a Book. " << endl;
    cout << "2.Borrow a Book. " << endl;
    cout << "3.Return a Book. " << endl;
    cout << "4.Calculate Fine. " << endl;
    cout << "5.Check if a Book is available. " << endl;
    cout << "6.Check Borrowed Books. " << endl;
    cout << "7.EXIT " << endl;

    cout << endl << "Enter your choice: ";
    cin >> choice;

    return choice;
  }
};

int main() {
  string operation;

  Person Librarian;

  string newBook = "null";
  string nameOfBook = "null";
  int daysOverdue = 0;
  double charges = 0;

  while (true) {
    // calling the menu for the user to select from
    int choice = Librarian.menu();
    switch (choice) {
    // adding book
    case 1:
      cout << "Enter name or ID of book to add: ";
      cin >> newBook;
      cout << endl;
      Librarian.addBook(newBook);
      break;

    // borrowing
    case 2:
      cout << "Name of Book to Borrow: ";
      cin >> nameOfBook;
      cout << endl;
      Librarian.borrowBook(nameOfBook);
      break;

    // returning
    case 3:
      cout << "Name of Book to Return: ";
      cin >> nameOfBook;
      cout << endl;
      Librarian.returnBook(nameOfBook);
      break;

    // fine calculation
    case 4:
      cout << "Days overdue: ";
      cin >> daysOverdue;
      charges = Librarian.getFine(daysOverdue);
      cout << endl
           << "The fine for " << daysOverdue << " days is " << charges << endl;
      break;

    // book availability
    case 5:
      cout << "Name of Book to check for availability: ";
      cin >> nameOfBook;
      cout << endl;
      Librarian.checkBookAvailability(nameOfBook);
      break;

    // listing borrowed books
    case 6:
      Librarian.checkBorrowedBooks();
      cout << endl;
      break;

    // exiting
    case 7:
      cout << endl << "quiting program..." << endl;
      exit(0);
      // break;

    // for every other choice,
    default:
      cout << "If you're seeing this you entered an invalid choice!!" << endl;
      break;
    }
    cout << endl;
  }

  return 0;
}