#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string contact;

public:
    Person() {
        name = "";
        id = 0;
        contact = "";
    }

    void getInf() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter contact: ";
        cin >> contact;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Contact: " << contact << endl;
    }
};

class Member : public Person {
private:
    int membershipID;
    int issueBook;

public:
    Member() {
        membershipID = 0;
        issueBook = 0;
    }

    void inputMember() {
        cout << "membershipID: ";
        cin >> membershipID;
        cout << "IssueBook: ";
        cin >> issueBook;
    }

    void borrowBook() {
        cout << "member borrow book" << endl;
    }

    void issueBooks() {
        cout << "member issue book" << endl;
    }

    void display() override {
        Person::display();
        cout << "MembershipID: " << membershipID << endl;
        cout << "IssueBooks: " << issueBook << endl;
        borrowBook();
        issueBooks();
    }
}; 
class Librarian : public Person {
private:
    int staffID;

public:
    Librarian() {
        staffID = 0;
    }

    void inputLibrarian() {
        cout << "Enter Staff ID: ";
        cin >> staffID;
    }

    void addBook() {
        cout << "librarian add book" << endl;
    }

    void removeBook() {
        cout << "librarian remove book" << endl;
    }

    void issueBooks() {
        cout << "librarian issue book" << endl;
    }

    void display() override {
        Person::display();
        cout << "StaffID: " << staffID << endl;
        addBook();
        removeBook();
        issueBooks();
    }
};
class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    Book() {
        title = "";
        author = "";
        ISBN = "";
        isAvailable = true;
    }

    void getDetails() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter ISBN: ";
        cin >> ISBN;
        isAvailable = true;
    }

    void showBook() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;

        if (isAvailable)
            cout << "Status: Available" << endl;
        else
            cout << "Status: Issued" << endl;
    }

    bool available() {
        return isAvailable;
    }

    void issue() {
        isAvailable = false;
        cout << "Book issued successfully" << endl;
    }

    void returned() {
        isAvailable = true;
        cout << "Book returned successfully" << endl;
    }
};

class IssueBook {
private:
    int lateDays;

public:
    IssueBook() {
        lateDays = 0;
    }

    void calculateFine() {
        cout << "Enter late Days: ";
        cin >> lateDays;
        cout << "CalculateFine: " << lateDays * 20 << endl;
    }
};

int main() {
    Book b[5];
    Member m[5];
    Librarian l[3];
    IssueBook fine;

    int bCount = 0;
    int mCount = 0;
    int lCount = 0;
    int choice;

    while (true) {
        cout << "\n-------LIBRARY MANAGEMENT SYSTEM-------\n";
        cout << "1 Add book\n";
        cout << "2 Show book\n";
        cout << "3 Add Member\n";
        cout << "4 Show member\n";
        cout << "5 Add librarian\n";
        cout << "6 Show librarian\n";
        cout << "7 Issue book\n";
        cout << "8 return book\n";
        cout << "9 calculateFine\n";
        cout << "0 EXIT\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Program Closed" << endl;
            break;
        }

        // ADD BOOK
        if (choice == 1 && bCount < 5) {
            b[bCount++].getDetails();
        }

        // SHOW BOOK
        else if (choice == 2) {
            for (int i = 0; i < bCount; i++)
                b[i].showBook();
        }

        // ADD MEMBER
        else if (choice == 3 && mCount < 5) {
            m[mCount].getInf();        // FIX
            m[mCount].inputMember();
            mCount++;
        }

        // SHOW MEMBER
        else if (choice == 4) {
            for (int i = 0; i < mCount; i++)
                m[i].display();
        }

        // ADD LIBRARIAN
        else if (choice == 5 && lCount < 3) {
            l[lCount].getInf();        // FIX
            l[lCount].inputLibrarian();
            lCount++;
        }

        // SHOW LIBRARIAN
        else if (choice == 6) {
            for (int i = 0; i < lCount; i++)
                l[i].display();
        }

        // ISSUE BOOK
        else if (choice == 7) {
            int n;
            cout << "Enter Book Number: ";
            cin >> n;

            if (n > 0 && n <= bCount) {
                if (b[n - 1].available())
                    b[n - 1].issue();
                else
                    cout << "Book Already Issued" << endl;
            } else {
                cout << "Invalid Book Number" << endl;
            }
        }

        // RETURN BOOK
        else if (choice == 8) {
            int n;
            cout << "Enter Book Number: ";
            cin >> n;

            if (n > 0 && n <= bCount)
                b[n - 1].returned();
            else
                cout << "Invalid Book Number" << endl;
        }

        // FINE
        else if (choice == 9) {
            fine.calculateFine();
        }

        else {
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}
 