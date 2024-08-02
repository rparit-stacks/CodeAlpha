
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <regex>
#include <string>
#include <vector>
using namespace std;
bool isValidEmail(const string& email) {
    const regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex_match(email, pattern);
}
class Account {
public:
    vector<int> tempAccountNumber = {5, 5, 5, 5, 0, 0, 0, 5, 4};
    long long AccountNumber = 0;
    string IFSC = "HDFC000";
    long long CRN = 0;
    long long currentBalance;

    Account() {  // for IFSC, ACCOUNT NUMBER & CRN
        for (int i = 0; i < 6; i++) {
            tempAccountNumber.push_back(rand() % 9);
        }
        for (int i = 0; i < 15; i++) {
            AccountNumber *= 10;
            AccountNumber += tempAccountNumber[i];
        }

        for (int i = 0; i < 4; i++) {
            IFSC += (tempAccountNumber[i] + '0');
        }

        for (int i = 0; i < 10; i++) {
            CRN *= 10;
            CRN += rand() % 9;
        }
        currentBalance = 0;
    }
};

void printSeparator() {
    cout << "+----------------------+--------------------------+" << endl;
}
class Customer : public Account {
public:
    string name;
    int Age;
    string email;
    long long AccountNumber;
    string IFSC;
    long long CRN;
    int currentBalance;

    Customer() {
        this->AccountNumber = Account::AccountNumber;
        this->IFSC = Account::IFSC;
        this->CRN = Account::CRN;
        this->currentBalance = Account::currentBalance;
    }
};

class BankingService {
public:
    Customer tempName;
    void createNewAccount() {
        cout << "Please Enter Your Details" << endl;

        cout << "Please Enter Your Name: ";
        getline(cin, tempName.name);

        cout << "Please Enter Your Age: ";
        cin >> tempName.Age;

        cin.ignore();

    getEmail:
        cout << "Please Enter Your Email: ";
        getline(cin, tempName.email);

        if (isValidEmail(tempName.email)) {
            cout << "Email is valid." << endl;
        } else {
            cout << "Error: Invalid email format." << endl;
            goto getEmail;
        }
    }

    void accountDetails() {
        cout << "+----------------------+--------------------------+" << endl;
        cout << "|     Account Details                          |" << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| Name                 | " << tempName.name << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| Age                  | " << tempName.Age << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| Email                | " << tempName.email << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| Account Number       | " << tempName.AccountNumber << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| IFSC                 | " << tempName.IFSC << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| CRN                  | " << tempName.CRN << endl;
        cout << "+----------------------+--------------------------+" << endl;
    }

    void depositFunds() {
        double amount;
        printSeparator();
        cout << "|      Deposit Funds                               |" << endl;
        printSeparator();
        cout << "| Enter the amount to deposit: $";
        cin >> amount;
        tempName.currentBalance += amount;
        printSeparator();
        cout << "| Deposit Successful!                             |" << endl;
        printSeparator();
        cout << "| Account Holder Name   | " << tempName.name << endl;
        printSeparator();
        cout << "| Account Number        | " << tempName.AccountNumber << endl;
        printSeparator();
        cout << "| Deposited Amount      | $" << amount << endl;
        printSeparator();
        cout << "| New Balance           | $" << tempName.currentBalance
             << endl;
        printSeparator();
    }
    void withdrawFunds() {
        double amount;
        printSeparator();
        cout << "|        Withdraw Funds                           |" << endl;
        printSeparator();

        cout << "Hello, " << tempName.name
             << "! Enter the amount to withdraw: $";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive number." << endl;
            return;
        }

        if (amount > tempName.currentBalance) {
            cout << "Insufficient funds. Your current balance is $"
                 << tempName.currentBalance << endl;
            return;
        }

        tempName.currentBalance -= amount;
        printSeparator();
        cout << "| Withdrawal Successful!                         |" << endl;
        printSeparator();
        cout << "| Account Holder Name   | " << tempName.name << endl;
        printSeparator();
        cout << "| Account Number        | " << tempName.AccountNumber << endl;
        printSeparator();
        cout << "| Withdrawn Amount      | $" << amount << endl;
        printSeparator();
        cout << "| New Balance           | $" << tempName.currentBalance
             << endl;
        printSeparator();
    }
    void transferFunds() {
        long long recipient;
        long long amount;

        printSeparator();
        cout << "|        Transfer Funds                           |" << endl;
        printSeparator();

        cout << "Hello, " << tempName.name
             << "! Enter the recipient's CRN or account details:" << endl;

        cout << "Enter the recipient's CRN: ";
        cin >> recipient;

        cout << "Enter the amount to transfer: $";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive number." << endl;
            return;
        }

        if (amount > tempName.currentBalance) {
            cout << "Insufficient funds. Your current balance is $"
                 << tempName.currentBalance << endl;
            return;
        }

        tempName.currentBalance -= amount;
        printSeparator();
        cout << "| Transfer Successful!                           |" << endl;
        printSeparator();
        cout << "| Account Holder Name   | " << tempName.name << endl;
        printSeparator();
        cout << "| Amount Transferred    | $" << amount << endl;
        printSeparator();
        cout << "| New Balance           | $" << tempName.currentBalance
             << endl;
        printSeparator();
        cout << "| Recipient CRN         | " << recipient << endl;
        printSeparator();
    }

    void viewBalance() {
        cout << "+----------------------+--------------------------+" << endl;
        cout << "|     Balance Details                             |" << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| Account Holder Name   | " << tempName.name << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| Account Number        | " << tempName.AccountNumber << endl;
        cout << "+----------------------+--------------------------+" << endl;
        cout << "| Current Balance       | $" << tempName.currentBalance
             << endl;
        cout << "+----------------------+--------------------------+" << endl;
    }
};

void displayMenu() {
    cout << endl << endl;
    cout << "============================================\n";
    cout << "|                Banking System             |\n";
    cout << "============================================\n";
    cout << "| 1. View Account Details                   |\n";
    cout << "| 2. Deposit Funds                          |\n";
    cout << "| 3. Withdraw Funds                         |\n";
    cout << "| 4. Transfer Funds                         |\n";
    cout << "| 5. Exit                                   |\n";
    cout << "============================================\n";
}

void bank(BankingService HDFC) {
    int choice;
    displayMenu();
    cout << "Please enter the Number to continue with banking.";
    cin >> choice;
    cout << endl << endl;

    if (choice == 1) {
        HDFC.accountDetails();
        bank(HDFC);
        cout << endl << endl;
    } else if (choice == 2) {
        HDFC.depositFunds();
        bank(HDFC);
        cout << endl << endl;
    } else if (choice == 3) {
        HDFC.withdrawFunds();
        bank(HDFC);
        cout << endl << endl;
    } else if (choice == 4) {
        HDFC.transferFunds();
        bank(HDFC);
        cout << endl << endl;
    } else if (choice == 5) {
        exit(0);
    } else {
        cout << "Invalid choice. Please enter a number between 1 and 5."
             << endl;
        bank(HDFC);
    }
}

int main() {
    cout << "+-----------------------------------------------+" << endl;
    cout << "|               Welcome to HDFC Bank!           |" << endl;
    cout << "+-----------------------------------------------+" << endl;
    BankingService HDFC;
    HDFC.createNewAccount();
    bank(HDFC);
    return 0;
}