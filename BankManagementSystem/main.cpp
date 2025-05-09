#include <iostream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount
{
    static int nextAccountNumber;
    int accountNumber;
    string name;
    char accountType; //'C' = current  'S'= saving
    double balance;

public:
    void createAccount()
    {
        accountNumber = nextAccountNumber++;
        cout << "Your Acount number is : " << accountNumber << endl;
        // cin.ignore();
        cout << "Enter your name : ";
        getline(cin, name);
        cout << "Enter account type (c/s) : ";
        cin >> accountType;
        do
        {
            cout << "Enter your balance : ";
            cin >> balance;
        } while (balance <= 0);
        cin.ignore();
    }
    void showAccount() const
    {
        cout << "Acount number : " << accountNumber << endl
             << "name : " << name << endl
             << "account type : " << accountType << endl
             << "Balance : " << balance << endl;
    }
    void modify()
    {
        cout << "Enter your name : ";
        getline(cin, name);
        cout << "Enter account type (c/s) : ";
        cin >> accountType;
        cin.ignore();
    }
    void deposit(double amnt)
    {
        balance += amnt;
    }
    void withdraw(double amnt)
    {
        if (amnt <= balance)
        {
            balance -= amnt;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
    void report() const
    {
        cout << setw(12) << accountNumber
             << setw(18) << name
             << setw(8) << accountType
             << setw(12) << fixed << setprecision(2) << balance << endl;
    }
    int getAccountNumber() const
    {
        return accountNumber;
    }
    double getBalance() const
    {
        return balance;
    }
    char getAccountType() const
    {
        return accountType;
    }
};

int BankAccount ::nextAccountNumber = 1000;

void displayHeader()
{
    cout << setw(12) << "Account No."
         << setw(18) << "Name"
         << setw(8) << "Type"
         << setw(12) << fixed << setprecision(2) << "Balance" << endl;
}


void writeAccount();
int main()
{
    vector<BankAccount> account;
    int choice;

    do {
        cout << "\n===== Bank Menu =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display Account Details\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                BankAccount acc;
                acc.createAccount();
                account.push_back(acc);
                break;
            }
            case 2: {
                int accNum, found = 0;
                cout << "Enter account number: ";
                cin >> accNum;
                for(auto &acc : account){
                    if(acc.getAccountNumber() == accNum){
                        acc.showAccount();
                        found = 1;
                        break;
                    }
                }
                if(!found)
                    cout << "Account not found.\n";
                break;
            }
            case 3: {
                int accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bool found = false;
                for(auto &acc : account){
                    if(acc.getAccountNumber() == accNum){
                        found = true;
                        acc.deposit(amount);
                    }
                }
                if(!found)
                    cout << "Account not found.\n";
                break;
            }
            case 4: {
                int accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bool found = false;
                for (auto &acc : account) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account not found.\n";
                break;
            }
            case 7:{
                if(account.empty()){
                    cout << "No accounts to display.\n";
                }else{
                    displayHeader();
                    for(const auto &acc: account){
                        acc.report();
                    }
                }
                break;
            }
            case 6:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}


