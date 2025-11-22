📇 Contact Management System

A simple and efficient Contact Management System built using C++.
It allows users to add, view, search, edit, and delete contacts using a clean and menu-driven console interface.
This project uses file handling to store all contacts locally.

📌 Features
✅ Add Contact

Users can enter a name, phone number, and email.
The data is stored in contacts.txt.

✅ Display All Contacts

Shows all saved contacts in a formatted table view.

✅ Search Contact

Search by name or phone number.
If a match is found, full details are displayed.

✅ Edit Contact

Update an existing contact’s information.
The old entry is replaced with the updated one.

✅ Delete Contact

Remove a contact using a name or phone number.

✅ Exit

Close the program safely.

🛠 Technologies Used

C++

File Handling (fstream)

OOP Concepts

Menu-Driven Programming

📂 File Structure
ContactManagementSystem.cpp   → Main source code
contacts.txt                  → Auto-generated data file

🚀 How to Run the Program
1️⃣ Clone the repository
git clone https://github.com/yourusername/ContactManagementSystem.git
cd ContactManagementSystem

2️⃣ Compile the program
g++ ContactManagementSystem.cpp -o cms

3️⃣ Run it
./cms

📄 Data Storage Format

Each stored contact follows this format:

Name|Phone|Email


Example:

John Doe|9876543210|john@example.com

🧠 How the Code Works
Contact Class

Handles:

Storing data (name, phone, email)

Taking input from the user

Displaying contact details

ContactManager Class

Implements all features:

Add

Display

Search

Edit

Delete

Uses a helper parseLine() function to read contact details from the file.

📷 Sample Output
========== CONTACT MANAGEMENT SYSTEM ==========
1. Add Contact
2. Display All Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit
----------------------------------------------
Enter your choice:

🤝 Contributions

Contributions are welcome!
Feel free to fork the project and submit pull requests.

🧑‍💻 Author

GitHub: [https://github.com/Abhishek7825Agrawal]
