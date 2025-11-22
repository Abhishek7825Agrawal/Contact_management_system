#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Contact {
public:
    string name, phone, email;

    void input() {
        cout << "\nEnter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Email: ";
        getline(cin, email);
    }

    void display() const {
        cout << left << setw(20) << name
             << setw(15) << phone
             << setw(25) << email << endl;
    }
};

class ContactManager {
public:
    void addContact() {
        Contact c;
        c.input();
        ofstream file("contacts.txt", ios::app);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }
        file << c.name << "|" << c.phone << "|" << c.email << endl;
        file.close();
        cout << "\n Contact added successfully!\n";
    }

    void displayContacts() {
        ifstream file("contacts.txt");
        if (!file) {
            cout << "No contacts found!\n";
            return;
        }

        cout << "\n---------------- CONTACT LIST ----------------\n";
        cout << left << setw(20) << "Name" << setw(15) << "Phone" << setw(25) << "Email" << endl;
        cout << "---------------------------------------------------------------\n";

        string line;
        bool found = false;
        while (getline(file, line)) {
            if (line.empty()) continue;
            Contact c = parseLine(line);
            c.display();
            found = true;
        }
        if (!found) cout << "No contacts available.\n";
        file.close();
    }

    void searchContact() {
        string keyword;
        cout << "\nEnter name or phone number to search: ";
        cin.ignore();
        getline(cin, keyword);

        ifstream file("contacts.txt");
        if (!file) {
            cout << "No contacts found!\n";
            return;
        }

        bool found = false;
        string line;
        while (getline(file, line)) {
            Contact c = parseLine(line);
            if (c.name == keyword || c.phone == keyword) {
                cout << "\n Contact found:\n";
                cout << left << setw(20) << "Name" << setw(15) << "Phone" << setw(25) << "Email" << endl;
                cout << "---------------------------------------------------------------\n";
                c.display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << " Contact not found.\n";
        file.close();
    }

    void deleteContact() {
        string keyword;
        cout << "\nEnter name or phone number to delete: ";
        cin.ignore();
        getline(cin, keyword);

        ifstream file("contacts.txt");
        ofstream temp("temp.txt");

        if (!file) {
            cout << "No contacts found!\n";
            return;
        }

        bool deleted = false;
        string line;
        while (getline(file, line)) {
            Contact c = parseLine(line);
            if (c.name == keyword || c.phone == keyword) {
                deleted = true;
                continue; // Skip this contact (delete)
            }
            temp << c.name << "|" << c.phone << "|" << c.email << endl;
        }

        file.close();
        temp.close();
        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");

        if (deleted)
            cout << " Contact deleted successfully!\n";
        else
            cout << " Contact not found.\n";
    }

    void editContact() {
        string keyword;
        cout << "\nEnter name or phone number to edit: ";
        cin.ignore();
        getline(cin, keyword);

        ifstream file("contacts.txt");
        ofstream temp("temp.txt");

        if (!file) {
            cout << "No contacts found!\n";
            return;
        }

        bool edited = false;
        string line;
        while (getline(file, line)) {
            Contact c = parseLine(line);
            if (c.name == keyword || c.phone == keyword) {
                cout << "\nEditing contact:\n";
                c.input();
                edited = true;
            }
            temp << c.name << "|" << c.phone << "|" << c.email << endl;
        }

        file.close();
        temp.close();
        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");

        if (edited)
            cout << " Contact updated successfully!\n";
        else
            cout << " Contact not found.\n";
    }

private:
    Contact parseLine(const string &line) {
        Contact c;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        c.name = line.substr(0, pos1);
        c.phone = line.substr(pos1 + 1, pos2 - pos1 - 1);
        c.email = line.substr(pos2 + 1);
        return c;
    }
};

int main() {
    ContactManager manager;
    int choice;

    do {
        cout << "\n========== CONTACT MANAGEMENT SYSTEM ==========";
        cout << "\n1. Add Contact";
        cout << "\n2. Display All Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Edit Contact";
        cout << "\n5. Delete Contact";
        cout << "\n6. Exit";
        cout << "\n----------------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addContact(); break;
            case 2: manager.displayContacts(); break;
            case 3: manager.searchContact(); break;
            case 4: manager.editContact(); break;
            case 5: manager.deleteContact(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
