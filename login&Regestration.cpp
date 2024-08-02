#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

string databaseDir = "database/";

bool isUsernameAvailable(const string& username) {
    ifstream infile(databaseDir + username + ".txt");
    return !infile.good();
}

bool validatePassword(const string& password) {
    regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@#$%^&+=]).{8,}$");
    return regex_match(password, pattern);
}

string hashPassword(const string& password) {
    return "hashed_" + password;
}

bool createUserFile(const string& username, const string& password) {
    ofstream outfile(databaseDir + username + ".txt");
    if (outfile.is_open()) {
        outfile << "Username: " << username << endl;
        outfile << "Password: " << hashPassword(password) << endl;
        outfile.close();
        return true;
    }
    return false;
}

bool authenticateUser(const string& username, const string& password) {
    ifstream infile(databaseDir + username + ".txt");
    if (infile.is_open()) {
        string storedUsername, storedPassword;
        getline(infile, storedUsername);
        getline(infile, storedPassword);
        infile.close();

        return storedPassword == "Password: " + hashPassword(password);
    }
    return false;
}

int main() {
    while (true) {
        int choice;
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string username, password;

            cout << "Enter username (5-20 characters): ";
            cin >> username;

            if (username.length() < 5 || username.length() > 20) {
                cerr << "Username must be between 5 and 20 characters." << endl;
                continue;
            }

            if (!isUsernameAvailable(username)) {
                cerr << "Username is already taken." << endl;
                continue;
            }

            cout << "Enter password (at least 8 characters, include uppercase, "
                    "lowercase, digit, special character): ";
            cin >> password;

            if (!validatePassword(password)) {
                cerr << "Password does not meet requirements." << endl;
                continue;
            }

            if (createUserFile(username, password)) {
                cout << "Registration successful!" << endl;
            } else {
                cerr << "Registration failed. Please try again." << endl;
            }
        } else if (choice == 2) {
            string username, password;

            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            if (authenticateUser(username, password)) {
                cout << "Login successful!" << endl;
            } else {
                cerr << "Invalid username or password." << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cerr << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    return 0;
}
