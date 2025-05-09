#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class BankAccount
{
    static int nextAccountNumber;
    int accountNumber;
    char name[20];
    char accountType; //'C' = current  'S'= saving
    double balance;

public:
    void createAccount()
    {
        accountNumber = nextAccountNumber++;
        cout << "Your Account number is : " << accountNumber << endl;
        // cin.ignore();
        cout << "Enter your name : ";
        // getline(cin, name);
        cin.getline(name, 20);
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
        cin.ignore();
        cout << "Enter your name : ";
        // getline(cin, name);
        cin.getline(name, 20);
        cout << "Enter account type (c/s) : ";
        cin >> accountType;
        cin.ignore();
    }
    void deposit(double amnt)
    {
        balance += amnt;
    }
    bool withdraw(double amnt)
    {
        if (amnt <= balance)
        {
            balance -= amnt;
            return true;
        }
        return false;
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
    static void setNextAccountNumber(int num){      //to access static data member
        nextAccountNumber = num;
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
void displayAccount(int);
void modifyAccount(int);
void deleteAccount(int);
void displayAll();
void depositWithdraw(int, int);
void loadLastAccountNumber();

int main()
{
    int choice, accNum;
    loadLastAccountNumber();        //load all data from file storage
    do
    {
        cout << "\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n";
        cout << "1. Create new account\n";
        cout << "2. Display account details\n";
        cout << "3. Modify account\n";
        cout << "4. Delete account\n";
        cout << "5. Display all accounts\n";
        cout << "6. Deposit money\n";
        cout << "7. Withdraw money\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice)
        {
        case 1:
            writeAccount();
            break;
        case 2:
            cout << "Enter account number to display: ";
            cin >> accNum;
            displayAccount(accNum);
            break;
        case 3:
            cout << "Enter account number to modify: ";
            cin >> accNum;
            modifyAccount(accNum);
            break;
        case 4:
            cout << "Enter account number to delete: ";
            cin >> accNum;
            deleteAccount(accNum);
            break;
        case 5:
            displayAll();
            break;
        case 6:
            cout << "Enter account number to deposit into: ";
            cin >> accNum;
            depositWithdraw(accNum, 1);
            break;
        case 7:
            cout << "Enter account number to withdraw from: ";
            cin >> accNum;
            depositWithdraw(accNum, 2);
            break;
        case 0:
            cout << "Exiting program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void loadLastAccountNumber() {      //prevent for duplicate account number;
    BankAccount acc;

    int accNumber = 999;                //if 1st accNum then also start from 1000;
    ifstream readFile("accounts.dat", ios::binary);
    if(readFile.is_open()){
        while(readFile.read(reinterpret_cast<char *>(&acc),sizeof(acc))){
            accNumber = acc.getAccountNumber();
        }
        readFile.close();
    }
    BankAccount::setNextAccountNumber(accNumber + 1);

}
void writeAccount()
{
    BankAccount acc;
    acc.createAccount();

    ofstream writeFile("accounts.dat", ios::app | ios::binary); // open
    if (writeFile.is_open())
    {
        writeFile.write(reinterpret_cast<char *>(&acc), sizeof(acc)); // writing
        writeFile.close();
        cout << "Account successfully written to file.\n";
    }
    else
    {
        cout << "Error opening file for writing.\n";
    }
}
void displayAccount(int accNum)
{
    BankAccount acc;
    bool found = false;

    ifstream readFile("accounts.dat", ios::binary); // open
    if (readFile.is_open())
    {
        while (readFile.read(reinterpret_cast<char *>(&acc), sizeof(acc))) // reading
        {
            if (acc.getAccountNumber() == accNum)
            {
                acc.showAccount();
                found = true;
                break;
            }
        }
        readFile.close();
        if (!found)
        {
            cout << "Account number " << accNum << " not found.\n";
        }
    }
    else
    {
        cout << "Error opening file for reading.\n";
    }
}

void modifyAccount(int accNum)
{
    BankAccount acc;
    bool found = false;

    fstream file("accounts.dat", ios::binary | ios::out | ios::in);
    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }
    while (file.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
    {
        if (acc.getAccountNumber() == accNum)
        {
            found = true;
            acc.showAccount();
            cout << endl;
            acc.modify();
            // Move write pointer back to the start of this record
            int pos = -static_cast<int>(sizeof(acc)); // use -Ve casting   unsigned to signed int
            file.seekp(pos, ios::cur);                // Move write pointer back to current read position
            file.write(reinterpret_cast<char *>(&acc), sizeof(acc));

            cout << "Account updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Account number " << accNum << " not found.\n";
    }
    file.close();
}

void deleteAccount(int accNum)
{
    BankAccount acc;
    bool found = false;

    ifstream readfile("accounts.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary | ios::app);
    if (readfile.is_open() && temp.is_open())
    {
        while (readfile.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            if (acc.getAccountNumber() == accNum)
            {
                found = true;
                cout << "Deleting this account:\n";
                acc.showAccount();
            }
            else
            {
                temp.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            }
        }
        readfile.close();
        temp.close();
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");
        if (!found)
        {
            cout << "Account number " << accNum << " not found.\n";
        }
        else
        {
            cout << "Account deleted successfully.\n";
        }
    }
    else
    {
        cout << "Error opening file.\n";
    }
}

void displayAll()
{
    BankAccount acc;
    bool found = false;
    ifstream readFile("accounts.dat", ios::binary);
    if (readFile.is_open())
    {
        displayHeader();
        while (readFile.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            acc.report();
            found = true;
        }
        if (!found)
        {
            cout << "No accounts to display.\n";
        }
    }
    else
    {
        cout << "Error opening file.\n";
    }
}

void depositWithdraw(int accNum, int option)
{
    BankAccount acc;
    bool found = false;
    double amount = 0;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    while (file.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
    {
        if (acc.getAccountNumber() == accNum)
        {
            found = true;
            cout << "Account found:\n";
            acc.showAccount();
            if (option == 1) // deposit
            {
                cout << "Enter amount to be deposite : ";
                cin >> amount;
                acc.deposit(amount);
            }
            else if (option == 2) // withdraw
            {
                cout << "Enter amount to be Withdraw : ";
                cin >> amount;
                if (acc.withdraw(amount))
                {
                    cout << "Money withdrewl successfull" << endl;
                }
                else
                {
                    cout << "Insufficient balance" << endl;
                }
            }
            else
            {
                cout << "Invealid option !" << endl;
            }
            int pos = -static_cast<int>(sizeof(acc)); // use -Ve casting   unsigned to signed int
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            cout << "Transaction successful and updated in file.\n";
            break;
        }
    }
    if (!found)
    {
        cout << "Account number " << accNum << " not found.\n";
    }
    file.close();
}