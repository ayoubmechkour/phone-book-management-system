#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Node {
public:
    string name;
    string number;
    Node* next;

    Node(string name, string number) {
        this->name = name;
        this->number = number;
        this->next = nullptr;
    }
};

class PhoneBook {
private:
    Node* head;

public:
    PhoneBook();
    void addPhoneNumber(string name, string number);
    void displayAllNumbers();
    void searchNumber(string name);
    void deleteNumber(string name);
    void modifyNumber(string name, string newNumber);
};

// Constructor
PhoneBook::PhoneBook() {
    head = nullptr;
}

// Function to add a phone number
void PhoneBook::addPhoneNumber(string name, string number) {
    Node* newNode = new Node(name, number);
    newNode->next = head;
    head = newNode;
    cout << "Phone number added successfully!" << endl;
}

// Function to display all phone numbers
void PhoneBook::displayAllNumbers() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "No phone numbers saved." << endl;
        return;
    }
    cout << left << setw(20) << "Name" << " - " << "Number" << endl;
    while (temp != nullptr) {
        cout << left << setw(20) << temp->name << " - " << temp->number << endl;
        temp = temp->next;
    }
}

// Function to search for a phone number
void PhoneBook::searchNumber(string name) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            cout << "Found: " << temp->name << ", Number: " << temp->number << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Number not found." << endl;
}

// Function to delete a phone number
void PhoneBook::deleteNumber(string name) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->name == name) {
        head = temp->next;
        delete temp;
        cout << "Phone number deleted successfully!" << endl;
        return;
    }

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Number not found." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Phone number deleted successfully!" << endl;
}

// Function to modify a phone number
void PhoneBook::modifyNumber(string name, string newNumber) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            temp->number = newNumber;
            cout << "Phone number modified successfully!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Number not found." << endl;
}

int main() {
    PhoneBook phoneBook;
    int option;
    string name, number;

    do {
        cout<<endl<<endl;
        cout << "============================================" << endl;
        cout << "           PHONE BOOK MANAGEMENT" << endl;
        cout << "============================================" << endl << endl;
        cout << "1- Save New Phone Number" << endl;
        cout << "2- Display All Saved Numbers" << endl;
        cout << "3- Search a Number" << endl;
        cout << "4- Delete a Number" << endl;
        cout << "5- Modify an Existing Number" << endl;
        cout << "0- Exit" << endl;
        cout << "============================================" << endl;
        cout << "-->  ";
        cin >> option;
        cin.ignore(); // To ignore the newline character left in the buffer
        cout<<endl;

        switch (option) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter number: ";
                getline(cin, number);
                phoneBook.addPhoneNumber(name, number);
                break;
            case 2:
                phoneBook.displayAllNumbers();
                break;
            case 3:
                cout << "Enter name to search: ";
                getline(cin, name);
                phoneBook.searchNumber(name);
                break;
            case 4:
                cout << "Enter name to delete: ";
                getline(cin, name);
                phoneBook.deleteNumber(name);
                break;
            case 5:
                cout << "Enter name to modify: ";
                getline(cin, name);
                cout << "Enter new number: ";
                getline(cin, number);
                phoneBook.modifyNumber(name, number);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 0);

    return 0;
}

