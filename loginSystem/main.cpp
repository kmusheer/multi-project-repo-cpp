#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cstring>
using namespace std;

string generatePassword()
{
    int range;
    string pwd;
    srand(time(NULL));
    char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "abcdefghijklmnopqrstuvwxyz"
                   "0123456789"
                   "!@#$%^&*()-_=+[]{}|;:',.<>/?`~";

    cout << "Enter range of password : ";
    cin >> range;
    cin.ignore();
    cout << "Your passwrod is : ";
    int len = strlen(input);
    for (int i = 0; i < range; i++)
    {
        pwd += input[rand() % len];
    }
    return pwd;
    // cout <<"Password : " << pwd << endl;
}

void registration(string &name, string &password)
{
    string cnfrmPassword;
    int choice;
    cout << "Enter your name : ";
    getline(cin, name);
    cout << "Enter your choice 1:generatePassword \t2:userPassword : ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        password = generatePassword();
        cout << "Your password is : " << password << endl;
        return;
    }
    else if (choice == 2)
    {
        int attempts = 3;
        cout << "Enter your password (no spaces): ";
        cin >> password;
        while (--attempts)
        {
            cout << "Confirm your password : ";
            cin >> cnfrmPassword;
            cin.ignore();
            if (password == cnfrmPassword)
            {
                cout << "Matched successfully" << endl;
                break;
            }
            else
                cout << attempts << " attempts left" << endl;
        }
    }
    else
    {
        cout << "Invalid choice " << endl;
        return;
    }
}
bool login(string name, string password)
{
    string pwd, lname;
    char ch;
    int attempts = 3;
    cout << "Enter your login credentials " << endl;
    cout << "User name : ";
    getline(cin, lname);
    // cout << "Password : ";
    // cin >> psw;

    while (attempts--)
    {
        pwd.clear();        //clear previous input
        cout << "Password: ";
        // cin >> psw;
        while ((ch = getch()) != '\r') // 13 carriage return    for enter key getch is windows conio library
        {
            if (ch == '\b') // handle backspace
            {
                if (!pwd.empty())
                {
                    pwd.pop_back();
                    cout << "\b \b"; // first back what u enter then overwrite with space and then again back 1 positon
                }
            }
            else
            {
                pwd.push_back(ch);
                cout << "*";
            }
        }
        // cout << endl << "pass : " << pwd << endl;
        // cin.ignore();
        if (password == pwd)
        {
            return true;
        }
        cout << "Incorrect password. " << attempts << " attempt(s) left." << endl;
    }
    return false;
}

int main()
{
    char choice;

    string input, name, password;
    while (true)
    {
        cout << endl
             << " l:Login " << endl
             << " r:Registration" << endl
             << " q:Quit" << endl
             << "Enter your choice: ";
        getline(cin, input);
        if (input.length() == 1)
            choice = input[0];
        else
            choice = '\0'; // Invalid

        if (choice == 'l')
        {
            if (login(name, password))
            {
                cout << "Login successfully" << endl;
            }
            else
            {
                cout << "Wrong credentials" << endl;
            }
        }
        else if (choice == 'r')
        {
            registration(name, password);
        }
        else if (choice == 'q')
        {
            cout << "Exiting from this app" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
