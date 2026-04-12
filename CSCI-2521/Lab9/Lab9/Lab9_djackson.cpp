/**
 * @file Lab9_djackson.cpp
 * @author Darius Jackson
 * @date 2026-4-11
 * @brief Demonstrates inheritance and polymorphism using Account and SavingsAccount.
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;


class Customer {
private:
    string customerID;
    string email;

public:
   
    Customer() {
        customerID = "Unknown";
        email = "none@example.com";
    }
    
    Customer(const string& id, const string& emailAddr)
        : customerID(id), email(emailAddr) {
    }

    
    string getCustomerID() const {
        return customerID;
    }

    
    string getEmail() const {
        return email;
    }

  
    void printCustomerInfo() const {
        cout << "Customer ID: " << customerID << endl;
        cout << "Email: " << email << endl;
    }
};


class Account {
protected:
    string accountNumber;
    double balance;
    Customer owner;

    vector<double> deposits;
    vector<double> withdrawals;

    
    void printSummary(double previousBalance, double totalDeposits, double totalWithdrawals, double newBalance) const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Previous Balance: $" << previousBalance << endl;
        cout << "Total Deposits: $" << totalDeposits << endl;
        cout << "Total Withdrawals: $" << totalWithdrawals << endl;
        cout << "New Balance after COB: $" << newBalance << endl;
    }

public:
    
    Account()
        : accountNumber("0000000000"), balance(0.0), owner(Customer()) {
    }

    Account(const string& accNum, double initialBalance, const Customer& customer)
        : accountNumber(accNum), balance(initialBalance), owner(customer) {
    }

    bool deposit(double amount) {
        if (amount > 0) {
            deposits.push_back(amount);
            return true;
        }
        return false;
    }

  
    bool withdraw(double amount) {
        if (amount > 0) {
            withdrawals.push_back(amount);
            return true;
        }
        return false;
    }

    
    virtual void closeOfBusiness() {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;
        double newBalance = previousBalance + totalDeposits - totalWithdrawals;

        printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

        balance = newBalance;

        deposits.clear();
        withdrawals.clear();
    }

    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        owner.printCustomerInfo();
    }

    void printTransactions() const {
        cout << "Deposits: ";
        for (double d : deposits) cout << "$" << d << " ";
        cout << endl;

        cout << "Withdrawals: ";
        for (double w : withdrawals) cout << "$" << w << " ";
        cout << endl;
    }
};


class SavingsAccount : public Account {
private:
    double dailyInterestRate;

public:
  
    SavingsAccount(const string& accNum, double initialBalance, const Customer& cust, double rate)
        : Account(accNum, initialBalance, cust), dailyInterestRate(rate) {
    }

    
    void printAccountInfo() const override {
        Account::printAccountInfo();
        cout << "Interest Rate: " << dailyInterestRate << endl;
    }

   
    void closeOfBusiness() override {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;
        double newBalance = previousBalance + totalDeposits - totalWithdrawals;

        
        if (newBalance > 0) {
            newBalance += newBalance * dailyInterestRate;
        }

        
        cout << "Account Number: " << accountNumber << endl;
        cout << "Previous Balance: $" << previousBalance << endl;
        cout << "Total Deposits: $" << totalDeposits << endl;
        cout << "Total Withdrawals: $" << totalWithdrawals << endl;
        cout << "New Balance after COB: $" << newBalance << endl;

        balance = newBalance;
        deposits.clear();
        withdrawals.clear();
    }
};

/**
 * @brief Entry point demonstrating polymorphism.
 * @return 0 to indicate success.
 */
int main() {
    Customer customer("0123456789", "customer@cscc.edu");

    
    Account* account = new SavingsAccount("5423678409", 100.0, customer, 0.005);

    account->printAccountInfo();

    int choice;
    double amount;

    do {
        cout << "\nCSCC Bank and Trust\n";
        cout << "Select an option:" << endl;
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Close of Business\n";
        cout << "4. Quit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            account->deposit(amount);
            break;

        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account->withdraw(amount);
            break;

        case 3:
            account->closeOfBusiness();
            break;

        case 4:
            cout << "Bye..." << endl;
            break;

        default:
            cout << "Invalid option selected. Please try again" << endl;
        }

    } while (choice != 4);

    delete account; 

    return 0;
}